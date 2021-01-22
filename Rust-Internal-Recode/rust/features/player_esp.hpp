#pragma once
#include <array>
#include <cstdint>

#include "../../memory/il2cpp.hpp"
#include "../../settings.hpp"

#include "../classes.hpp"
#include "../rust.hpp"

namespace esp {
	uintptr_t client_entities;
	base_player* local_player;
	VMatrix matrix;

	struct bounds_t {
		float left, right, top, bottom;
	};

	struct rust_str
	{
		char zpad[128];
	};

	bool out_w2s(const vector3& position, vector2& screen_pos)
	{
		if (!matrix.m) {
			return false;
		}

		vector2 out;
		const auto temp = matrix.transpose();

		auto translation_vector = vector3{ temp[3][0], temp[3][1], temp[3][2] };
		auto up = vector3{ temp[1][0], temp[1][1], temp[1][2] };
		auto right = vector3{ temp[0][0], temp[0][1], temp[0][2] };

		float w = translation_vector.dot(position) + temp[3][3];

		if (w < 0.098f) {
			return false;
		}

		float x = up.dot(position) + temp._24;
		float y = right.dot(position) + temp._14;

		out.x = (static_cast<float>(unity::get_width()) / 2) * (1 + y / w);
		out.y = (static_cast<float>(unity::get_height()) / 2) * (1 - x / w);

		screen_pos = out;

		return true;
	}

	//struct str
	//{
	//	char buffer[128];
	//};

	void draw_heli(float x, float y, float w, float h);

	void draw_tool_cupboard(vector2 w2s_position, uintptr_t label, vector4 color, rust::list<PlayerNameID*>* authorizedPlayers_list);

	void draw_hackable_crate(vector2 w2s_position, uintptr_t crate, vector4 color);

	void draw_item(vector2 w2s_position, uintptr_t label, vector4 color, wchar_t* name = _(L""));

	void draw_player(base_player* player, bool is_npc);

	void draw_target_hotbar(aim_target target);

	void draw_name(vector3 position, wchar_t* name);

	void draw_weapon_icon(weapon* item, vector2 w2s_position);

	uintptr_t shader;

	void iterate_players(bool draw = true) {
		aim_target best_target = aim_target();

		auto get_client_entities = [&]() {
			client_entities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		};
		if (!client_entities)
			get_client_entities();

		rust::classes::list* entity_list = (rust::classes::list*)client_entities;

		auto list_value = entity_list->get_value<uintptr_t>();
		if (!list_value)
		{
			get_client_entities();
			return;
		}

		auto size = entity_list->get_size();
		if (!size)
		{
			get_client_entities();
			return;
		}

		auto buffer = entity_list->get_buffer<uintptr_t>();
		if (!buffer)
		{
			get_client_entities();
			return;
		}

		for (int i = 0; i <= size; i++) {
			auto current_object = *reinterpret_cast<uintptr_t*>(buffer + 0x20 + (i * 0x8));
			if (!current_object || current_object <= 100000)
				continue;

			auto base_object = *reinterpret_cast<uintptr_t*>(current_object + 0x10);
			if (!base_object || base_object <= 100000)
				continue;

			auto object = *reinterpret_cast<uintptr_t*>(base_object + 0x30);
			if (!object || object <= 100000)
				continue;

			WORD tag = *reinterpret_cast<WORD*>(object + 0x54);

			auto do_melee_attack = [&](base_projectile* baseprojectile)
			{
				auto ent = *reinterpret_cast<uintptr_t*>(base_object + 0x28);

				auto ent_class = *reinterpret_cast<uintptr_t*>(ent);
				auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);

				auto attack = [&](bool is_tree) {
					auto _class = *reinterpret_cast<uintptr_t*>(base_object + 0x30);

					auto game_object = *reinterpret_cast<uintptr_t*>(_class + 0x30);

					auto transform = *reinterpret_cast<uintptr_t*>(game_object + 0x8);
					auto visual_state = *reinterpret_cast<uintptr_t*>(transform + 0x38);


					auto world_position = *reinterpret_cast<vector3*>(visual_state + 0x90);

					auto local = ClosestPoint(esp::local_player, world_position);
					if (local.get_3d_dist(world_position) >= 5)
						return;

					auto gathering = baseprojectile->Gathering();

					if (is_tree) {
						if (!(gathering->tree()->gatherDamage() > 1)) {
							return;
						}
					}
					else {
						if (!(gathering->ore()->gatherDamage() > 1)) {
							return;
						}
					}

					aim_target target;

					target.pos = world_position;
					target.player = (base_player*)ent;
					target.visible = true;
					attack_melee(target, baseprojectile);
				};

				auto name = *(int*)(entity_class_name);

				if (name == 'eerT') {
					attack(true);
				}
				else if (name == 'HerO') {
					attack(false);
				}
			};

			/*if (esp::local_player && settings::misc::silent_farm) {
				auto weapon = esp::local_player->get_active_weapon();
				if (weapon) {
					auto baseprojectile = weapon->get_base_projetile();
					if (baseprojectile) {
						auto class_name = baseprojectile->get_class_name();
						if (*(int*)(class_name + 4) == 'eleM' || *(int*)(class_name + 4) == 'mmah') {
							do_melee_attack(baseprojectile);
						}
					}
				}
			}*/

			auto ent = *reinterpret_cast<uintptr_t*>(base_object + 0x28);
			if (!ent)
				continue;

			auto ent_class = *reinterpret_cast<uintptr_t*>(ent);
			if (!ent_class)
				continue;

			auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);
			if (!entity_class_name)
				continue;

			vector4 esp_color(255, 255, 255, 255);
			uintptr_t esp_name;

			auto game_object = *reinterpret_cast<uintptr_t*>(object + 0x30);
			if (!game_object)
				continue;

			auto transform = *reinterpret_cast<uintptr_t*>(game_object + 0x8);
			if (!transform)
				continue;

			auto visual_state = *reinterpret_cast<uintptr_t*>(transform + 0x38);
			if (!visual_state)
				continue;

			auto world_position = *reinterpret_cast<vector3*>(visual_state + 0x90);
			if (world_position.is_empty())
				continue;

			uintptr_t object_name_ptr = mem::read<uintptr_t>(object + 0x60);
			if (!object_name_ptr)
				continue;

			auto object_name = *reinterpret_cast<rust_str*>(object_name_ptr);
			if (!object_name.zpad)
				continue;

			if (*(int*)(entity_class_name) == 'kcaH' && *(int*)(entity_class_name + 14) == 'tarC')
			{
				auto flag = *reinterpret_cast<int*>(ent + 0x120);
				if (flag != 128 && flag != 256)
					continue;

				vector2 w2s_position = {};
				if (out_w2s(world_position, w2s_position))
					esp::draw_hackable_crate(w2s_position, ent, { 0.45, 0.72, 1, 0.8 });
			}

			if (settings::visuals::misc_esp) {					
				if (*(int*)(entity_class_name) == 'porD') {
					if (!settings::visuals::dropped_items)
						continue;

					if (*(int*)(entity_class_name + 40) == 'kcab')
						continue;

					if (*(int*)(object_name.zpad) == 'orra')
						continue;

					if (*(int*)(object_name.zpad + 12) == 'ian.')
						continue;

					auto Item = *reinterpret_cast<uintptr_t*>(ent + 0x150);
					if (!Item)
						continue;

					auto item = reinterpret_cast<weapon*>(Item);

					auto item_name = item->get_weapon_name();

					esp_color = vector4(196, 124, 0, 255);

					vector2 w2s_position = {};
					if (out_w2s(world_position, w2s_position))
						draw_weapon_icon(item, w2s_position);
					//esp::draw_item(w2s_position, 0, esp_color, item_name);

					continue;
				}
				
				if (settings::visuals::tc_esp && *(int*)(entity_class_name) == 'liuB' && *(int*)(entity_class_name + 8) == 'virP')
				{
					auto authorizedPlayers_wrapper = *reinterpret_cast<uintptr_t*>(ent + 0x510);
					if (!authorizedPlayers_wrapper)
						continue;
					const auto authorizedPlayers_list = *reinterpret_cast<rust::list<PlayerNameID*>**>(authorizedPlayers_wrapper + 0x10);
					if (!authorizedPlayers_list)
						continue;

					vector2 w2s_position = {};
					if (out_w2s(world_position, w2s_position))
						esp::draw_tool_cupboard(w2s_position, il2cpp::methods::new_string(_("Tool Cupboard")), vector4(255, 0, 0, 255), authorizedPlayers_list);
				}


				if (*(int*)(entity_class_name + 4) == 'ileH' && settings::visuals::heli_esp) {
					auto base_heli = reinterpret_cast<base_player*>(ent);

					vector2 rearrotor, beam, mainrotor;
					out_w2s(base_heli->get_bone_transform(22)->get_bone_position(), rearrotor);
					out_w2s(base_heli->get_bone_transform(19)->get_bone_position(), mainrotor);
					out_w2s(base_heli->get_bone_transform(56)->get_bone_position(), beam);

					uintptr_t transform = mem::read<uintptr_t>(base_heli->get_model() + 0x48);

					const vector2 diff = { (beam.x + rearrotor.x) / 2, (beam.y + rearrotor.y) / 2 };

					const float h = max(beam.y, rearrotor.y) - min(beam.y, rearrotor.y);
					const float y = diff.y;
					const float w = (max(beam.x, rearrotor.x) - min(beam.x, rearrotor.x));
					float x = diff.x - h / 4;

					draw_heli(x, y, w, h);
				}

				if (settings::visuals::stash && *(int*)(object_name.zpad + 46) == '_hsa') {
					esp_name = il2cpp::methods::new_string(_("Stash"));
				}
				else if (settings::visuals::stone_ore && (*(int*)(object_name.zpad + 52) == 'nots' || *(int*)(object_name.zpad + 47) == 'nots')) {
					esp_name = il2cpp::methods::new_string(_("Stone Ore"));
					esp_color = vector4(232, 232, 232, 255);
				}
				else if (settings::visuals::sulfur_ore && (*(int*)(object_name.zpad + 52) == 'flus' || *(int*)(object_name.zpad + 47) == 'flus')) {
					esp_name = il2cpp::methods::new_string((_("Sulfur Ore")));
					esp_color = vector4(203, 207, 0, 255);
				}
				else if (settings::visuals::metal_ore && (*(int*)(object_name.zpad + 52) == 'atem' || *(int*)(object_name.zpad + 47) == 'atem')) {
					esp_name = il2cpp::methods::new_string(_("Metal Ore"));
					esp_color = vector4(145, 145, 145, 255);
				}
				else if (settings::visuals::traps && (*(int*)(object_name.zpad + 36) == 'terr' || *(int*)(object_name.zpad + 43) == 'tnug' || *(int*)(object_name.zpad + 38) == 'rtra')) {
					if (*(int*)(object_name.zpad + 36) == 'terr')
						esp_name = il2cpp::methods::new_string(_("*Auto Turret*"));
					else if (*(int*)(object_name.zpad + 43) == 'tnug')
						esp_name = il2cpp::methods::new_string(_("*Shotgun Trap*"));
					else if (*(int*)(object_name.zpad + 38) == 'rtra')
						esp_name = il2cpp::methods::new_string(_("*Bear Trap*"));

					esp_color = vector4(255, 166, 0, 255);
				}
				else if (settings::visuals::vehicles && *(int*)(entity_class_name + 4) == 'iheV') {
					esp_name = il2cpp::methods::new_string(_("Vehicle"));
					esp_color = vector4(0, 161, 219, 255);
				}
				else if (settings::visuals::airdrops && *(int*)(object_name.zpad + 39) == 'pord') {
					esp_name = il2cpp::methods::new_string(_("Airdrop"));
					esp_color = vector4(0, 161, 219, 255);
				}
				else if (settings::visuals::cloth && *(int*)(object_name.zpad + 52) == 'c-pm') {
					esp_name = il2cpp::methods::new_string(_("Cloth"));
					esp_color = vector4(0, 219, 58, 255);
				}
				else if (settings::visuals::corpses && *(int*)(object_name.zpad + 29) == 'proc') {
					esp_name = il2cpp::methods::new_string(_("Player Corpse"));
					esp_color = vector4(230, 230, 230, 255);
				}
				else if (tag != 6)
					continue;

				if (tag != 6) {
					if (*(int*)(entity_class_name) == 'satS') {
						auto flag = *reinterpret_cast<int*>(ent + 0x120);
						if (flag != 2048)
							continue;
					}

					vector2 w2s_position = {};
					if (out_w2s(world_position, w2s_position))
						esp::draw_item(w2s_position, esp_name, esp_color);

					continue;
				}
			}
			else if (tag != 6)
				continue;

			esp::matrix = unity::get_view_matrix();

			if (tag == 6 && !settings::visuals::player_esp)
				continue;

			auto player = reinterpret_cast<base_player*>(ent);

			auto hit_player = [&]() {
				auto weapon = esp::local_player->get_active_weapon();
				if (weapon) {
					auto baseprojectile = weapon->get_base_projetile();
					if (baseprojectile) {
						auto class_name = baseprojectile->get_class_name();
						if (*(int*)(class_name + 4) == 'eleM' || *(int*)(class_name + 4) == 'mmah')
						{
							auto world_position = player->get_bone_transform(48)->get_bone_position();
							auto local = ClosestPoint(esp::local_player, world_position);
							auto camera = esp::local_player->get_bone_transform(48)->get_bone_position();

							if (camera.get_3d_dist(world_position) >= 4.5f)
								return;

							aim_target target = esp::local_player->get_aimbot_target(camera);

							attack_melee(target, baseprojectile, true);
						}
					}
				}
			};

			if (!player->is_alive())
				continue;

			if (player->is_sleeping() && !settings::visuals::sleeper_esp)
				continue;

			bool is_npc = false;

			if (get_IsNpc(player->get_player_model())) {
				is_npc = true;

				if (!settings::visuals::npc_esp)
					continue;
			}

			if(player->is_local_player())
				local_player = reinterpret_cast<base_player*>(ent);
			else {
				if (esp::local_player) {
					auto target = aim_target();
					target.pos = player->get_bone_transform(19)->get_bone_position();

					auto distance = esp::local_player->get_bone_transform(48)->get_bone_position().get_3d_dist(target.pos);
					target.distance = distance;

					auto fov = unity::get_fov(target.pos);
					target.fov = fov;

					target.player = player;

					if (target < best_target)
						best_target = target;
				}
				if (draw) {
					if (settings::visuals::chams) {
						auto _multiMesh = mem::read<uintptr_t>(player->get_player_model() + 0x280);
						if (_multiMesh) {
							auto render = get_Renderers(_multiMesh);

							for (int i = 0; i < render->get_size(); i++) {
								auto renderer = render->get_value(i);

								if (renderer) {
									auto material = get_material(renderer);
									if (material) {
										if (shader != unity::get_shader(material)) {
											if (!shader)
												shader = Find(_(L"Hidden/Internal-Colored"));
											unity::set_shader(material, shader);
											SetColor(material, _(L"_Color"), col(1, 0, 0, 1));
										}
									}
								}
							}
						}
					}

					draw_player(player, is_npc);

					if (settings::weapon::silent_melee)
						hit_player();
				}
			}
		}

		esp::draw_target_hotbar(best_target);
	}

	void draw_teammates() {
		if (!esp::local_player)
			return;

		auto team = mem::read<uintptr_t>((uintptr_t)local_player + clientTeam);

		auto member = mem::read<uintptr_t>(team + 0x30);

		auto size = mem::read<int>(member + 0x18);

		auto list = mem::read<uintptr_t>(member + 0x10);

		for (int i = 0; i < size; i++) {
			auto player = mem::read<uintptr_t>(list + 0x20 + i * 0x8);

			auto online = mem::read<bool>(player + 0x38);

			if (!online && !settings::visuals::sleeper_esp)
				continue;

			auto id = mem::read<unsigned long>(player + 0x20);

			if (id == esp::local_player->get_steam_id())
				continue;

			auto position = mem::read<vector3>(player + 0x2C);
			auto distance = esp::local_player->get_bone_transform(48)->get_bone_position().distance(position);
			if (distance < 350.f)
				continue;

			auto player_name = (str)(*reinterpret_cast<uintptr_t*>(player + 0x18));
			auto name =  player_name->str;
			vector2 out;
			esp::out_w2s(position, out);
			esp::draw_name({ out.x, out.y, 0 }, name);
		}
	}

	void start() {
		//esp::draw_target_snap_line();
		//draw_raid();
		draw_teammates();
		iterate_players();
	}
}