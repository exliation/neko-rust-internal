#pragma once
#include "memory/il2cpp.hpp"
#include "settings.hpp"
#include "offsets.h"

namespace hooks {
	namespace orig {
		static auto baseplayer_client_input = reinterpret_cast<void (*)(base_player*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		static auto BaseProjectile_OnSignal = reinterpret_cast<void (*)(base_projectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		static auto playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		static auto DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		static auto blocksprint = reinterpret_cast<void (*)(base_player*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));
		static auto OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		static auto IsConnected = reinterpret_cast<bool (*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("IsConnected"), 0, _(""), _("Network"))));
		static auto Run = reinterpret_cast<rust::classes::string (*)(uintptr_t, uintptr_t, rust::classes::string, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ConsoleSystem"), _("Run"), 3, _(""), _(""))));

		uintptr_t playerprojectileattack;
		uintptr_t serverrpc_projectileshoot;
		uintptr_t serverrpc_processattack;
	}

	static auto serverrpc_projecileshoot = rb::pattern::find_rel(
		_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 28"));

	static auto serverrpc_uint = rb::pattern::find_rel(
		_("GameAssembly.dll"), _("74 3A 4C 8B 0D ? ? ? ? 48 8B CB"));

	static auto set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

	static auto draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

	static auto set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

	static auto GetSpeed = reinterpret_cast<float (*)(base_player * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

	static auto get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

	static auto IsSwimming = reinterpret_cast<bool (*)(base_player*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

	static auto ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

	static auto OnLand = reinterpret_cast<void (*)(base_player*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

	static auto change_code_rpc = reinterpret_cast<void (*)(base_player*, rust::classes::string, uintptr_t, bool, uintptr_t)>(mem::game_assembly_base + offsets::BaseEntity$$ServerRPC_string_bool_Address); //BaseEntity$$ServerRPC<string, bool> Address

	static auto ServerRPC_int = reinterpret_cast<void (*)(base_projectile*, rust::classes::string funcName, unsigned int arg1, uintptr_t)>(mem::game_assembly_base + offsets::BaseEntity$$ServerRPC_uint_);

	static auto DoHit = reinterpret_cast<bool (*)(base_projectile*, HitTest*, vector3, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 4, _(""), _(""))));

	void init_hooks() {
		orig::IsConnected = reinterpret_cast<bool (*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("IsConnected"), 0, _(""), _("Network"))));
		orig::OnNetworkMessage = reinterpret_cast<void (*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Client"), _("OnNetworkMessage"), 1, _(""), _(""))));
		orig::BaseProjectile_OnSignal = reinterpret_cast<void (*)(base_projectile*, int, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("OnSignal"), 2, _(""), _(""))));
		orig::baseplayer_client_input = reinterpret_cast<void (*)(base_player*, input_state*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), -1, _(""), _(""))));
		orig::playerwalkmovement_client_input = reinterpret_cast<void (*)(playerwalkmovement*, uintptr_t, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("ClientInput"), -1, _(""), _(""))));
		orig::DoFixedUpdate = reinterpret_cast<void (*)(playerwalkmovement*, modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("DoFixedUpdate"), -1, _(""), _(""))));
		orig::blocksprint = reinterpret_cast<void (*)(base_player*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("BlockSprint"), 1, _(""), _(""))));

		serverrpc_projecileshoot = rb::pattern::find_rel(
			_("GameAssembly.dll"), _("4C 8B 0D ? ? ? ? 48 8B 75 28"));

		serverrpc_uint = rb::pattern::find_rel(
			_("GameAssembly.dll"), _("74 3A 4C 8B 0D ? ? ? ? 48 8B CB"));

		ServerRPC_int = reinterpret_cast<void (*)(base_projectile*, rust::classes::string funcName, unsigned int arg1, uintptr_t)>(mem::game_assembly_base + offsets::BaseEntity$$ServerRPC_uint_);

		change_code_rpc = reinterpret_cast<void (*)(base_player*, rust::classes::string, uintptr_t, bool, uintptr_t)>(mem::game_assembly_base + offsets::BaseEntity$$ServerRPC_string_bool_Address);

		set_sprinting = reinterpret_cast<void (*)(modelstate*, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_sprinting"), -1, _(""), _(""))));

		draw_get = reinterpret_cast<void (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Get"), 0, _(""), _("UnityEngine"))));

		set_flying = reinterpret_cast<void (*)(modelstate * model_state, bool value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_flying"), 1, _(""), _(""))));

		GetSpeed = reinterpret_cast<float (*)(base_player * baseplayer, float running, float ducking)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 2, _(""), _(""))));

		get_ducked = reinterpret_cast<bool (*)(modelstate*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("get_ducked"), 0, _(""), _(""))));

		IsSwimming = reinterpret_cast<bool (*)(base_player*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));

		ServerRPC = ServerRPC = reinterpret_cast<void (*)(uintptr_t, rust::classes::string funcName)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));

		OnLand = reinterpret_cast<void (*)(base_player*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));

		DoHit = reinterpret_cast<bool (*)(base_projectile*, HitTest*, vector3, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 4, _(""), _(""))));
	}

	double CalcBulletDrop(double height, double DepthPlayerTarget, float velocity, float gravity) {
		double pitch = (vector3::my_atan2(height, DepthPlayerTarget));
		double BulletVelocityXY = velocity * vector3::my_cos(pitch);
		double Time = DepthPlayerTarget / BulletVelocityXY;
		double TotalVerticalDrop = (0.5f * gravity * Time * Time);
		return TotalVerticalDrop * 10;
	}

	void Prediction(vector3 local, vector3& target, vector3 targetvel, float bulletspeed, float gravity) {
		float Dist = local.get_3d_dist(target);
		float BulletTime = Dist / bulletspeed;

		vector3 vel = vector3(targetvel.x, 0, targetvel.z) * 0.75f;

		vector3 PredictVel = vel * BulletTime;

		target += PredictVel;

		double height = target.y - local.y;
		vector3 dir = target - local;
		float DepthPlayerTarget = vector3::my_sqrt(powFFFFFFFFFFFFFFFFFFFFFF(dir.x) + powFFFFFFFFFFFFFFFFFFFFFF(dir.z));

		float drop = CalcBulletDrop(height, DepthPlayerTarget, bulletspeed, gravity);

		target.y += drop;
	}

#pragma optimize("", off)
#pragma code_seg(".text")
	inline int64_t get_rbx_value()
	{
		static __declspec(allocate(".text")) char fn_stub[] = {
			0x48,
			0x89,
			0xD8, // mov    rax,rbx
			0xc3 // ret
		};

		return ((int64_t(*)())(&fn_stub))();
	}
#pragma code_seg(pop)
#pragma optimize("", on)

	void hk_serverrpc_playerprojectileattack(int64_t rcx, int64_t rdx, int64_t r9, int64_t _ppa, int64_t arg5) {
		auto        projectile = reinterpret_cast<base_projectile*>(get_rbx_value());
		auto  ppa = reinterpret_cast<rust::classes::PlayerProjectileAttack*>(_ppa);
		auto& attack = ppa->playerAttack->attack;

		const auto orig_fn =
			reinterpret_cast<void (*)(int64_t, int64_t, int64_t, int64_t, int64_t)>(
				hooks::orig::playerprojectileattack);

		auto camera_pos = unity::get_camera_pos();
		if (camera_pos.is_empty())
			return orig_fn(rcx, rdx, r9, _ppa, arg5);

		do {
			if (!esp::local_player)
				break;

			auto hit_test = projectile->get_hit_test();
			if (!hit_test)
				break;

			if (!hit_test->get_gameobject())
				break;

			auto layer = hit_test->get_gameobject()->get_layer();
			auto prefab_name = hit_test->get_gameobject()->get_prefab_name();

			aim_target target = esp::local_player->get_aimbot_target(camera_pos);

			if (!target.player || !target.network_id)
				break;

			auto& hit_entity = hit_test->get_hit_entity();
			if (layer == rust::classes::layer::Player_Server) {
				if (hit_entity->is_teammate(esp::local_player)) {
					hit_test->set_ignore_entity(hit_entity);
					return;
				}
			}

			if (!settings::weapon::hitbox_override && !settings::weapon::random_hitbox && !settings::weapon::magic_bullet)
				break;

			if (hit_entity != target.player && settings::weapon::magic_bullet) {
				const auto hitdist_from_ent = attack->hitPositionLocal.get_3d_dist(target.pos);

				if (hitdist_from_ent > 2.5f)
					break;
				else {
					hit_entity = target.player;
					attack->hitID = target.network_id;
				}
			}
			else if (hit_entity != target.player && !settings::weapon::magic_bullet)
				break;


			if (!target.is_heli && settings::weapon::hitbox_override) {
				attack->hitBone = 698017942;
				attack->hitPartID = 2173623152;
				attack->hitPositionLocal = { -.1f, -.1f, 0 };
				attack->hitNormalLocal = { 0, -1, 0 };
			}
			else if (!target.is_heli && settings::weapon::random_hitbox) {
				switch (my_rand() % 4) {
				case 0: // Head
					attack->hitBone = 698017942;
					attack->hitPartID = 2173623152;
					break;
				case 1: // Chest
					attack->hitBone = 1031402764;
					attack->hitPartID = 1750816991;
					break;
				case 2: // LHand
					attack->hitBone = 182688154;
					attack->hitPartID = 1750816991;
					break;
				case 3: // RHand
					attack->hitBone = 102231371;
					attack->hitPartID = 1750816991;
					break;
				}
				attack->hitPositionLocal = { -.1f, -.1f, 0 };
				attack->hitNormalLocal = { 0, -1, 0 };
			}
			else {
				auto weakspots = target.player->get_weakspots();
				if (!weakspots)
					break;

				auto size = *reinterpret_cast<uintptr_t*>(weakspots + 0x18);

				bool tail_alive = false;
				bool main_alive = false;
				for (int i = 0; i < size; i++) {
					auto weakspot = *(uintptr_t*)(weakspots + 0x20 + i * 0x8);
					if (!weakspot)
						continue;
					auto health = *reinterpret_cast<float*>(weakspot + 0x24);
					if (health > 0) {
						if (i == 0) {
							main_alive = true;
						}
						else {
							tail_alive = true;
						}
					}
				}

				if (tail_alive) {
					attack->hitBone = 2699525250;
					attack->hitPartID = 2306822461;
					attack->hitPositionLocal = { .9f, -.4f, .1f };
					attack->hitNormalLocal = { .9f, -.4f, .1f };
				}
				else if (main_alive) {
					attack->hitBone = 224139191;
					attack->hitPartID = 2306822461;
					attack->hitPositionLocal = { .9f, -.4f, .1f };
					attack->hitNormalLocal = { .9f, -.4f, .1f };
				}
			}
		} while (0);

		return orig_fn(rcx, rdx, r9, _ppa, arg5);
	}

	void hk_serverrpc_projectileshoot(int64_t rcx, int64_t rdx, int64_t r9, int64_t projectileShoot, int64_t arg5) {
		do {
			if (!esp::local_player)
				break;

			auto weapon = esp::local_player->get_active_weapon();

			if (!weapon)
				break;

			auto baseprojectile = esp::local_player->get_active_weapon()->get_base_projetile();

			if (!baseprojectile)
				break;

			auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);
			if (*(int*)(wep_class_name + 4) == 'eleM' || *(int*)(wep_class_name) == 'ddaP')
				break;

			base_projectile* projectile_list = *reinterpret_cast<base_projectile**>(
				*reinterpret_cast<uintptr_t*>((uintptr_t)baseprojectile + 0x338) + 0x10);

			esp::matrix = unity::get_view_matrix();
			auto camera_pos = unity::get_camera_pos();

			aim_target target = esp::local_player->get_aimbot_target(camera_pos);

			uintptr_t shoot_list = *(uintptr_t*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x10);

			auto size = *(int*)(*(uintptr_t*)(projectileShoot + 0x18) + 0x18);

			vector3 aimbot_velocity;

			const auto stats = baseprojectile->get_stats(weapon->get_item_definition_id());

			vector3 aim_angle;
			vector3 rpc_position;

			for (int i = 0; i < size; i++) {
				auto projectile = *(uintptr_t*)(shoot_list + 0x20 + i * 0x8);

				rpc_position = *reinterpret_cast<vector3*>(projectile + 0x18);
				auto original_vel = *reinterpret_cast<vector3*>(projectile + 0x24);


				if (target.player && unity::GetKey(rust::classes::KeyCode::Mouse3) && target.visible && !target.teammate) {
					Prediction(rpc_position, target.pos, target.velocity, original_vel.Length(), stats.gravity_modifier);

					aim_angle = /*get_aim_angle(rpc_position, target.pos, target.velocity, false, stats)*/target.pos - rpc_position;

					aimbot_velocity = (aim_angle).Normalized() * original_vel.Length();

					*reinterpret_cast<vector3*>(projectile + 0x24) = aimbot_velocity;
				}
			}

			for (int i = 0; i < projectile_list->get_size(); i++) {
				auto projectile = *(base_projectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);

				if (!projectile)
					continue;

				if (!projectile->first) {
					projectile->thickness = projectile->get_projectile_thickness();
					projectile->first = true;
				}

				if (settings::weapon::weapon_removals) {
					auto ItemModProjectile = projectile->get_item_mod_projectile();

					ItemModProjectile->projectileSpread() = 0;
					ItemModProjectile->projectileVelocitySpread() = 0;
				}
					
				if (settings::weapon::thick_bullet)
					projectile->set_projectile_thickness(0.70f);
				else
					projectile->set_projectile_thickness(projectile->thickness);

				if (target.player && target.visible && !target.teammate) {
					if (unity::GetKey(rust::classes::KeyCode::Mouse3) && settings::weapon::psilent)
						projectile->set_current_velocity(aimbot_velocity);
				}
			}
		} while (0);

		reinterpret_cast<void (*)(int64_t, int64_t, int64_t, int64_t, int64_t)>(hooks::orig::serverrpc_projectileshoot)(rcx, rdx, r9, projectileShoot, arg5);
	}

	bool is_lagging;

	bool flying = false, is_speeding = false;

	bool has_intialized_methods = false;

	float nextActionTime = 0, period = 1.4721;

	//void hk_baseprojectile_OnSignal(base_projectile* baseprojectile, int signal , rust::classes::string string) {
	//	orig::BaseProjectile_OnSignal(baseprojectile, signal, string);

	//	if (settings::visuals::raid_esp) {
	//		auto reusableInstace = il2cpp::value(_("Effect"), _("reusableInstace"), false);

	//		auto draw_explosion = [&](const char* explosion_name) {
	//			auto world_position = *reinterpret_cast<vector3*>(reusableInstace + 0x5C);
	//			vector2 w2s_position = {};
	//			if (esp::out_w2s(world_position, w2s_position)) {
	//				esp::draw_item(w2s_position, il2cpp::methods::new_string(_("Rocket Explosion")), { 255,0,0,255 });
	//			}
	//		};

	//		if (reusableInstace) {
	//			auto world_position = *reinterpret_cast<transform**>(reusableInstace + 0x78);

	//			auto esp_name = (str)(*reinterpret_cast<uintptr_t*>(reusableInstace + 0x88));
	//			auto name = esp_name->str;

	//			LOG("Prefab names: %ls", name);

	//			if (m_wcsicmp(name, _(L"assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion.prefab"))) {
	//				draw_explosion(_("Rocket Explosion"));
	//			}
	//			else if (m_wcsicmp(name, _(L"assets/prefabs/tools/c4/effects/c4_explosion.prefab"))) {
	//				draw_explosion(_("C4 Explosion"));
	//			}
	//		}
	//	}
	//}

#define ptr_assert(val) \
    if(val == 0)        \
    return
	uintptr_t client_entities;

	void hk_dofixedupdate(playerwalkmovement* base_movement, modelstate* modelstate) {
		if (esp::local_player && settings::misc::always_sprint) {
			bool is_busy = get_ducked(modelstate) | IsSwimming(esp::local_player);

			float speed = GetSpeed(esp::local_player, 1, is_busy);

			vector3 vel = *reinterpret_cast<vector3*>(base_movement + 0x34);
			vector3 xz = vector3(vel.x, 0, vel.z).normalize() * speed;
			vel = vector3(xz.x, vel.y, xz.z);

			if (!flying) {
				*reinterpret_cast<vector3*>(base_movement + 0x34) = vel;

				set_sprinting(modelstate, true);
			}
		}

		orig::DoFixedUpdate(base_movement, modelstate);
	}

	void hk_blocksprint(base_player* player, float duration) {
		if (!settings::weapon::always_shoot)
			return hooks::orig::blocksprint(player, duration);

		return;
	}

	void draw_raid()
	{
		auto effect_network = il2cpp::init_class(_("EffectNetwork"));
		if (!effect_network)
			return;

		auto effect = *reinterpret_cast<uintptr_t*>(effect_network + 0xB8);
		if (!effect)
		{
			LOG("Effect null...");
			return;
		}

		effect = *reinterpret_cast<uintptr_t*>(effect);
		if (!effect)
		{
			LOG("Effect1 null...");
			return;
		}

		auto world_pos = *reinterpret_cast<vector3*>(effect + 0x5C);
		if (world_pos.is_empty())
		{
			LOG("world_pos.is_empty()");
			return;
		}

		auto pooled_str = (str)(*reinterpret_cast<uintptr_t*>(effect + 0x88));
		auto pooledString = pooled_str->str;

		uintptr_t m_szTranslated;

		//assets/prefabs/ammo/rifle/riflebullet_explosive.prefab

		LOG("pooledString: %ls", pooled_str);
	}

	void hk_OnNetworkMessage(uintptr_t client, uintptr_t packet)
	{
		draw_raid();
		orig::OnNetworkMessage(client, packet);
	}

	void get_skydome()
	{
		uintptr_t m_skydome = NULL;
		uintptr_t m_camera = NULL;
		uintptr_t last_object = NULL;
		{
			auto gom = mem::read<uintptr_t>(mem::unity_player_base + 0x17C1F18);
			auto current_tagged_base = mem::read<uintptr_t>(gom + 0x08	);
			auto current_tagged_obj = mem::read<uintptr_t>(current_tagged_base + 0x10);

			while (current_tagged_obj &&
				current_tagged_obj != last_object &&
				(!m_skydome || !m_camera)) {
				INT16 tag = mem::read<uintptr_t>(current_tagged_obj + 0x54);

				if (!m_camera) {
					if (tag == 5) {
						uintptr_t objClass = mem::read<uintptr_t>(current_tagged_obj + 0x30);

						uintptr_t ent = mem::read<uintptr_t>(objClass + 0x18);

						m_camera = mem::read<uintptr_t>(current_tagged_obj + 0x18);
					}
				}

				if (!m_skydome) {
					if (tag == 20011) {
						uint64_t p = mem::read<uint64_t>(current_tagged_obj + 0x30);
						uint64_t p1 = mem::read<uint64_t>(p + 0x18);
						uint64_t p2 = mem::read<uint64_t>(p1 + 0x28);

						const auto TOD_Day = *reinterpret_cast<uintptr_t*>(p2 + 0x50);

						const auto TOD_Night = *reinterpret_cast<uintptr_t*>(p2 + 0x58);

						*(float*)(TOD_Night + 0x50) = 6.f;
						*(float*)(TOD_Night + 0x54) = 1.f;
						*(float*)(TOD_Day + 0x50) = 1.f;
						*(float*)(TOD_Day + 0x54) = 1.f;

						m_skydome = mem::read<uintptr_t>(current_tagged_obj + 0x18);
					}
				}
				last_object = current_tagged_obj;
				current_tagged_base = mem::read<uintptr_t>(current_tagged_base + 0x8);
				current_tagged_obj = mem::read<uintptr_t>(current_tagged_base + 0x10);
			}
		}
	}

	vector3 m_debugcam_toggle_pos;
	vector3 m_debugcam_pos;

	void hk_playerwalkmovement_ClientInput(playerwalkmovement* player_walk_movement, uintptr_t inputstate, modelstate* model_state) {
		orig::playerwalkmovement_client_input(player_walk_movement, inputstate, model_state);

		set_sprinting(model_state, true);

		flying = player_walk_movement->get_flying();

		if(unity::GetKey(rust::classes::KeyCode::Z))
			set_onLadder(model_state, true);

		model_state->remove_flag(rust::classes::ModelState_Flag::Flying);
	}

	uintptr_t do_fixed_update_ptr, client_input_ptr;

	//bool is_connected_hk(uintptr_t Client)
	//{
	//	auto  is_connected = orig::IsConnected(Client);

	//	static auto caller_addr = rb::pattern::find(
	//		_("GameAssembly.dll"), _("84 C0 74 15 33 C9 E8 ? ? ? ? 84"));

	//	if (!caller_addr)
	//		__debugbreak();

	//	if (reinterpret_cast<uintptr_t>(_ReturnAddress()) != caller_addr)
	//		return is_connected;

	//	static auto xref = rb::pattern::find(_("GameAssembly.dll"),
	//		_("FF 90 ? ? ? ? 84 C0 74 15 33 C9")) +
	//		0x1F;

	//	static auto xref_SendClientTick =
	//		reinterpret_cast<void(__fastcall*)(base_player*)>(
	//			xref + *(int32_t*)(xref - 4));

	//	static auto xref_SetNetworkPosition =
	//		reinterpret_cast<void(__fastcall*)(base_player*, vector3*)>(
	//			rb::pattern::find(_("GameAssembly.dll"),
	//				_("E8 ? ? ? ? 0F B6 F8 84 C0 74 4B")) -
	//			0x38);

	//	const auto send_tick = [&]() {
	//		xref_SendClientTick(esp::local_player);

	//		// If we send a tick ourselves, don't let the game send one again.
	//		is_connected = false;
	//	};

	//	auto local = esp::local_player;
	//	if (!local)
	//		return false;

	//	auto modelstate = local->get_model_state();
	//	if (!modelstate)
	//		return false;

	//	// Get the current player position...
	//	auto game_object = local->get_game_object();
	//	if (!game_object)
	//		return is_connected;

	//	auto behaviour = game_object->get_class<mono_behaviour*>();
	//	if (!game_object)
	//		return behaviour;

	//	auto transform = behaviour->get_transform();
	//	if (!game_object)
	//		return transform;


	//	if (!m_debugcam_toggle_pos.is_empty()) {
	//		xref_SetNetworkPosition(local, &m_debugcam_toggle_pos);
	//		send_tick();
	//		xref_SetNetworkPosition(local, &m_debugcam_pos);

	//		return is_connected;
	//	}
	//}

	void hk_baseplayer_ClientInput(base_player* baseplayer, input_state* state) {
		if(!do_fixed_update_ptr)
			do_fixed_update_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("DoFixedUpdate"), &hk_dofixedupdate);

		if(!client_input_ptr)
			client_input_ptr = mem::hook_virtual_function(_("PlayerWalkMovement"), _("ClientInput"), &hk_playerwalkmovement_ClientInput);

		if (!has_intialized_methods) {
			auto il2cpp_codegen_initialize_method = reinterpret_cast<void (*)(unsigned int)>(il2cpp::methods::intialize_method);
			//56229 for real rust or 56204 for cracked rust
			for (int i = 0; i <
#ifdef cracked_rust
				56204
#else
				56229
#endif
				; i++) {
				il2cpp_codegen_initialize_method(i);
			}
			has_intialized_methods = true;
		}

		static uintptr_t* serverrpc_projecshoot;
		if (!serverrpc_projecshoot) {
			auto method_serverrpc_projecshoot = *reinterpret_cast<uintptr_t*>(hooks::serverrpc_projecileshoot);

			if (method_serverrpc_projecshoot) {
				serverrpc_projecshoot = **(uintptr_t***)(method_serverrpc_projecshoot + 0x30);

				hooks::orig::serverrpc_projectileshoot = *serverrpc_projecshoot;

				*serverrpc_projecshoot = reinterpret_cast<uintptr_t>(&hooks::hk_serverrpc_projectileshoot);
			}
		}

		static uintptr_t* serverrpc_playerprojectileattack;
		if (!serverrpc_playerprojectileattack) {
			auto method_serverrpc_playerprojectileattack = *reinterpret_cast<uintptr_t*>(mem::game_assembly_base + offsets::Method$BaseEntity_ServerRPC_PlayerProjectileAttack___);//Method$BaseEntity_ServerRPC_PlayerProjectileAttack___

			if (method_serverrpc_playerprojectileattack) {
				serverrpc_playerprojectileattack = **(uintptr_t***)(method_serverrpc_playerprojectileattack + 0x30);

				hooks::orig::playerprojectileattack = *serverrpc_playerprojectileattack;

				*serverrpc_playerprojectileattack = reinterpret_cast<uintptr_t>(&hooks::hk_serverrpc_playerprojectileattack);
			}
		}

		if (baseplayer) {
			get_skydome();
			//auto game_object = baseplayer->get_game_object();

			//auto behaviour = game_object->get_class<mono_behaviour*>();

			//auto transform = behaviour->get_transform();

			//if (unity::GetKeyDown(rust::classes::KeyCode::F2)) {
			//	if (m_debugcam_toggle_pos.is_empty()) {
			//		m_debugcam_toggle_pos = m_debugcam_pos =
			//			transform->get_object_position();
			//	}
			//	else {
			//		auto last_good_pos = m_debugcam_toggle_pos;

			//		// Setting twice due to possible race condition
			//		*transform->get_position_ptr() = last_good_pos;
			//		m_debugcam_toggle_pos = { 0.f, 0.f, 0.f };
			//		*transform->get_position_ptr() = last_good_pos;
			//	}
			//}

			//// Update position
			//if (!m_debugcam_toggle_pos.is_empty()) {
			//	auto angles = baseplayer->bodyAngles();
			//	angles.y = -angles.y + 90.f; // Convert to source angles
			//	angles.clamp();

			//	vector3 fw, up = { 0.f, 1.f, 0.f }, rh;
			//	angles.angle_vectors(&fw, nullptr, nullptr);

			//	angles.x = 0.f;
			//	angles.y -= 90.f;
			//	angles.clamp();
			//	angles.angle_vectors(&rh, nullptr, nullptr);

			//	const auto scalar = unity::GetKey(rust::classes::KeyCode::LeftControl)
			//		? settings::misc::m_idebugcam_speed * 0.5f
			//		: unity::GetKey(rust::classes::KeyCode::LeftShift)
			//		? settings::misc::m_idebugcam_speed * 1.5f
			//		: settings::misc::m_idebugcam_speed;

			//	if (unity::GetKey(rust::classes::KeyCode::W))
			//		m_debugcam_pos = m_debugcam_pos + fw * scalar;
			//	else if (unity::GetKey(rust::classes::KeyCode::S))
			//		m_debugcam_pos = m_debugcam_pos - fw * scalar;
			//	if (unity::GetKey(rust::classes::KeyCode::A))
			//		m_debugcam_pos = m_debugcam_pos - rh * scalar;
			//	else if (unity::GetKey(rust::classes::KeyCode::D))
			//		m_debugcam_pos = m_debugcam_pos + rh * scalar;

			//	if (unity::GetKey(rust::classes::KeyCode::Space))
			//		m_debugcam_pos = m_debugcam_pos + up * scalar;

			//	*transform->get_position_ptr() = m_debugcam_pos;
			//}

			if (settings::misc::attack_on_mountables) {
				auto mountable = baseplayer->get_mountable();
				if (mountable)
					mountable->canwielditem() = true;
			}

			if (unity::GetKeyDown(rust::classes::KeyCode::P) && settings::misc::TakeFallDamage) {
				OnLand(baseplayer, -8.0001f - 100);
			}

			if (settings::misc::admin_mode)
				baseplayer->set_admin_flag(rust::classes::PlayerFlags::IsAdmin);

			if (!is_lagging && !flying && settings::misc::fake_lag && !is_speeding) {
				baseplayer->set_client_tick_interval(0.4f);
				is_lagging = true;
			}
			else if (is_lagging && flying || is_lagging && is_speeding) {
				esp::local_player->set_client_tick_interval(0.05f);
				is_lagging = false;
			}
			else if (is_lagging && !settings::misc::fake_lag) {
				esp::local_player->set_client_tick_interval(0.05f);
				is_lagging = false;
			}

			if (auto movement = baseplayer->get_movement()) {
				if (settings::misc::infinite_jump) {
					movement->set_land_time(0);
					movement->set_jump_time(0);
					movement->set_ground_time(100000);
				}

				if (settings::misc::gravity)
					movement->set_gravity_multiplier(1.75f);
				else
					movement->set_gravity_multiplier(2.35f);

				if (settings::weapon::always_shoot) {
					if (auto modelstate = baseplayer->get_model_state()) {
						modelstate->set_flag(rust::classes::ModelState_Flag::OnGround);
						mem::write<float>((uint64_t)movement + 0x48, 1);
					}
				}
			}

			auto item = baseplayer->get_active_weapon();

			if (settings::misc::auto_lock) {
				auto closest_ent = baseplayer->resolve_closest_entity(3);

				auto addr = mem::read<uintptr_t>(mem::game_assembly_base + offsets::Method_BaseEntity_ServerRPC_string_bool_address); //Method$BaseEntity.ServerRPC<string, bool>() address

				if (closest_ent.first.found && addr) {
					if (closest_ent.second) {
						auto code_str = string::format(_("%d"), (int)settings::misc::code_lock_code);
						change_code_rpc(closest_ent.first.player, rust::classes::string(_(L"RPC_ChangeCode")), il2cpp::methods::new_string(code_str), false, addr);
						ServerRPC((uintptr_t)closest_ent.first.player, rust::classes::string(_(L"TryLock")));
						ServerRPC((uintptr_t)closest_ent.first.player, rust::classes::string(_(L"RPC_Lock")));
					}
					else
						ServerRPC((uintptr_t)closest_ent.first.player, rust::classes::string(_(L"RPC_Lock")));
				}
			}

			if (settings::misc::speedhack && unity::GetKey(rust::classes::KeyCode::Z)) {
				set_timeScale(8);
				is_speeding = true;
			}
			else {
				set_timeScale(1);
				is_speeding = false;
			}

			if (item) {
				auto baseprojectile = item->get_base_projetile();
				if (baseprojectile) {
					auto wep_class_name = *(const char**)(*(uintptr_t*)(uintptr_t)baseprojectile + 0x10);

					auto attack = [&](aim_target target, bool is_tree) {
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

						attack_melee(target, baseprojectile);
					};

					if (settings::misc::silent_farm) {
						auto entity = baseplayer->resolve_closest_entity(3, false);
						if (entity.first.found && entity.first.player) {
							if (*(int*)(wep_class_name + 4) == 'eleM' || *(int*)(wep_class_name + 4) == 'mmah') {
								attack(entity.first, entity.second);
							}
						}
					}

					if (!(*(int*)(wep_class_name + 4) == 'eleM' && *(int*)(wep_class_name) == 'esaB')) {
						if (unity::GetKey(rust::classes::KeyCode::Mouse0) && settings::misc::instant_med) {
							const auto item_id = item->get_item_definition_id();

							if (item_id == 1079279582 || item_id == -2072273936) {
								auto time = get_time();
								if (baseprojectile->get_time_since_deploy() > baseprojectile->get_deploy_delay() && baseprojectile->get_next_attack_time() <= get_time()) {
									if (time > nextActionTime) {
										nextActionTime = time + period;
										ServerRPC((uintptr_t)baseprojectile, rust::classes::string(_(L"UseSelf")));
									}
								}
							}
						}
						else if (unity::GetKey(rust::classes::KeyCode::Mouse1) && settings::misc::instant_med) {
							const auto item_id = item->get_item_definition_id();

							if (item_id == 1079279582 || item_id == -2072273936) {
								esp::matrix = unity::get_view_matrix();
								auto camera_pos = unity::get_camera_pos();

								auto target = baseplayer->get_aimbot_target(camera_pos);

								if (target.player && target.distance < 5) {
									auto net = target.player->get_networkable();
									if (net) {
										auto id = net->get_id();
										if (id) {
											auto method_addr = mem::read<uintptr_t>(mem::game_assembly_base + offsets::Method$BaseEntity_ServerRPC_uint);
											if (method_addr) {
												auto time = get_time();
												if (baseprojectile->get_time_since_deploy() > baseprojectile->get_deploy_delay() && baseprojectile->get_next_attack_time() <= get_time()) {
													if (time > nextActionTime) {
														nextActionTime = time + period;
														ServerRPC_int(baseprojectile, rust::classes::string(_(L"UseOther")), id, method_addr);
													}
												}
											}
										}
									}
								}
							}
						}
						if (*(int*)(wep_class_name) == 'esaB' && *(int*)(wep_class_name + 4) == 'jorP' || *(int*)(wep_class_name) == 'nilF') {
							if (item->is_weapon()) {
								const auto item_id = item->get_item_definition_id();

								switch (item_id) {
								case 722955039:
								case 1491189398:
								case -1815301988:
								case -75944661:
									if (settings::weapon::weapon_removals) {
										baseprojectile->set_did_spark_this_frame(true);
										baseprojectile->set_success_fraction(100);
									}
									break;
								default:
									if (settings::weapon::weapon_removals) {
										if(settings::weapon::fast_bullet)
											baseprojectile->projectileVelocityScale() = 1.4f;
										baseprojectile->is_automatic() = true;
										baseprojectile->set_no_spread();
										baseprojectile->set_recoil(0, 0, 0, 0);
										baseprojectile->set_no_sway();

										if (settings::weapon::fast_bullet && settings::weapon::magic_bullet)
											baseprojectile->projectileVelocityScale() = 0.5f;
									}
									break;
								}
							}
						}
					}
				}
			}

			if (settings::misc::instant_revive) {
				auto target = baseplayer->get_aimbot_target(unity::get_camera_pos());
				if (!target.is_heli && target.player && target.distance <= 5 && target.teammate && target.player->get_health() <= 4 && target.visible)
					ServerRPC((uintptr_t)target.player, rust::classes::string(_(L"RPC_Assist")));
			}

			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Water, !settings::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::Tree, settings::misc::no_playercollision);
			unity::IgnoreLayerCollision(rust::classes::layer::PlayerMovement, rust::classes::layer::AI, settings::misc::no_playercollision);

			draw_get();

			auto tick_time = baseplayer->get_last_sent_ticket_time();
			if (tick_time > gui::tick_time_when_called + 10) {
				unity::camera = unity::get_main_camera();
				gui::tick_time_when_called = tick_time;
			}
		}

		orig::baseplayer_client_input(baseplayer, state);

		auto model_state = baseplayer->get_model_state();

		//model_state->set_water_level(99999);
		if (settings::misc::spinbot) {
			state->set_aim_angles(vector3(100, my_rand() % 999 + -999, 100));
		}
	}
}