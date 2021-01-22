#pragma once
#include "../assets/assets.hpp"

#include "../rust/unity.hpp"
#include "../rust/features/player_esp.hpp"
#include "../settings.hpp"
#include "../utils/string_format.h"

#define rgba(r,g,b,a) gui::Color(r / 255, g / 255, b / 255, a)

namespace gui {
	class Color {
	public:
		float r;
		float g;
		float b;
		float a;
		Color(float rr, float gg, float bb, float aa) {
			r = rr;
			g = gg;
			b = bb;
			a = aa;
		}
	};

	namespace methods {
		static auto get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		static auto get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		static auto set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		static auto set_color = reinterpret_cast<void(*)(gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));

		static auto Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		static auto _Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));
		static auto ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		static auto set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		static auto get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		static auto gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		static auto set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		static auto get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		static auto LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		static auto LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		static auto DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		static auto Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		static auto DrawLine = reinterpret_cast<void (*)(vector3, vector3, gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _("color"), _("UnityEngine"), 3)));

		static auto set_gizmos_color = reinterpret_cast<void(*)(gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), -1, _(""), _("UnityEngine"))));

		static auto HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));
	}

	uintptr_t white_texture;

	void init_gui() {
		methods::ptr_Label = reinterpret_cast<void(*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::gui_content_temp_ptr = reinterpret_cast<uintptr_t(*)(uintptr_t*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::HorizontalSlider = reinterpret_cast<float(*)(rust::classes::Rect position, float value, float leftValue, float rightValue)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("HorizontalSlider"), 4, _(""), _("UnityEngine"))));

		methods::get_whiteTexture = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));

		methods::get_skin = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));

		methods::set_fontSize = reinterpret_cast<void(*)(uintptr_t label, int size)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), -1, _(""), _("UnityEngine"))));

		methods::set_color = reinterpret_cast<void(*)(gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_color"), -1, _(""), _("UnityEngine"))));

		methods::Label = reinterpret_cast<void(*)(rust::classes::Rect position, uintptr_t content, uintptr_t style)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));

		methods::_Label = reinterpret_cast<void(*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 2, _("text"), _("UnityEngine"), 2)));

		methods::set_alignment = reinterpret_cast<void(*)(uintptr_t label, uintptr_t value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), -1, _(""), _("UnityEngine"))));

		methods::get_current = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));

		methods::gui_content_temp = reinterpret_cast<uintptr_t(*)(rust::classes::string*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));

		methods::set_skin = reinterpret_cast<void(*)(uintptr_t skin)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("set_skin"), 0, _(""), _("UnityEngine"))));

		methods::get_type = reinterpret_cast<rust::classes::EventType(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));

		methods::LoadAllAssets = reinterpret_cast<uintptr_t(*)(uintptr_t bundle, uintptr_t type)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAllAssets"), 1, _("type"), _("UnityEngine"), 1)));

		methods::LoadFromFile = reinterpret_cast<uintptr_t(*)(rust::classes::string path)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));

		methods::DrawTexture = reinterpret_cast<void (*)(rust::classes::Rect, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));

		methods::Box = reinterpret_cast<void (*)(rust::classes::Rect, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GUI"), _("Box"), 2, _("text"), _("UnityEngine"), 2)));

		methods::DrawLine = reinterpret_cast<void (*)(vector3, vector3, gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Debug"), _("DrawLine"), 3, _("color"), _("UnityEngine"), 3)));

		methods::set_gizmos_color = reinterpret_cast<void(*)(gui::Color)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Gizmos"), _("set_color"), -1, _(""), _("UnityEngine"))));

		white_texture = methods::get_whiteTexture();
	}

	uintptr_t label, skin;
	bool open;
	bool InsertPressed;

	float tick_time_when_called;

	void outline_box(vector2 pos, vector2 size, Color clr)
	{
		methods::set_color(clr);

		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x + size.x, pos.y, 1, size.y), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y, size.x, 1), white_texture);
		methods::DrawTexture(rust::classes::Rect(pos.x, pos.y + size.y, size.x, 1), white_texture);
	}

	void fill_box(rust::classes::Rect pos, Color clr)
	{
		methods::set_color(clr);
		methods::DrawTexture(pos, white_texture);
	}

	void init() {
		if (label && skin)
			return;

		skin = methods::get_skin();
		label = mem::read<uintptr_t>(skin + 0x38);

		methods::set_alignment(label, 0);
		methods::set_fontSize(label, 12);
		methods::set_color(Color(1, 1, 1, 1));
	}

	void Label(rust::classes::Rect pos, rust::classes::string text, Color clr, bool centered = false, float size = 12) {
		methods::set_color(clr);

		uintptr_t content = methods::gui_content_temp(&text);

		methods::set_fontSize(label, size);          //prepare style	

		if (centered)
			methods::set_alignment(label, 0x4);
		else
			methods::set_alignment(label, 0x0);

		methods::Label(pos, content, label);
	}

	void Label(rust::classes::Rect pos, uintptr_t text, Color clr, bool centered = false, float size = 12) {
		methods::set_color(clr);

		methods::set_fontSize(label, size);

		methods::ptr_Label(pos, text);
	}

	void Label(rust::classes::Rect pos, rust::classes::string text, float font_size = 0) {

		if (!font_size)
			methods::_Label(pos, text);
		else {
			uintptr_t content = methods::gui_content_temp(&text);

			methods::set_fontSize(label, font_size);          //prepare style	

			methods::Label(pos, content, label);
		}
	}

	void OnKeyUp(rust::classes::KeyCode key) {
		if (key == rust::classes::KeyCode::Insert) {
			InsertPressed = false;
		}
	}

	void OnKeyDown(rust::classes::KeyCode key) {
		if (!InsertPressed && key == rust::classes::KeyCode::Insert) {
			InsertPressed = true;
			open = !open;
		}
	}

	int active_tab = 0;
	vector2 tab_size;

	void tab(rust::classes::EventType event, vector2 pos, vector2 mouse, const wchar_t* tab_name, int id) {

		if (event == rust::classes::EventType::MouseDown) {
			if (rust::classes::Rect(pos.x + id * tab_size.x + 2.0f, pos.y - 4, tab_size.x, tab_size.y).Contains(mouse)) {
				active_tab = id;
			}
		}
		else if (event == rust::classes::EventType::Repaint) {
			if (active_tab == id) {
				fill_box(rust::classes::Rect(pos.x + id * tab_size.x + 2.0f, pos.y, tab_size.x, 2), Color(0.42, 0.36, 0.90, 1));
			}

			Label(rust::classes::Rect{ pos.x + id * tab_size.x + 2.0f + 1, pos.y - 4 + 1, tab_size.x, tab_size.y }, tab_name, gui::Color(0, 0, 0, 120), true, 12);
			Label(rust::classes::Rect{ pos.x + id * tab_size.x + 2.0f, pos.y - 4, tab_size.x, tab_size.y }, tab_name, gui::Color(255, 255, 255, 1), true, 12);
		}
	}

	void button(rust::classes::EventType event, vector2 pos, vector2& current_pos, vector2 mouse, const wchar_t* button_name, bool* out, int id, Color col = Color(255, 255, 255, 220)) {
		const float button_size = 16;
		if (event == rust::classes::EventType::MouseDown) {
			if (rust::classes::Rect(pos.x + id * tab_size.x + 3 + 2.0f, pos.y + current_pos.y - 4, 200, button_size + 3).Contains(mouse)) {
				*out = !*out;
			}
		}

		if (event == rust::classes::EventType::Repaint) {
			gui::Label(rust::classes::Rect{ pos.x + id * tab_size.x + 3 + 2.0f + 1, pos.y + current_pos.y - 4 + 1, 200, button_size + 3 }, button_name, gui::Color(0, 0, 0, 120), false, 10);
			if (*out) {
				gui::Label(rust::classes::Rect{ pos.x + id * tab_size.x + 3 + 2.0f, pos.y + current_pos.y - 4, 200, button_size + 3 }, button_name, Color(0, 0.5, 1, 1), false, 10);
			}
			else
				gui::Label(rust::classes::Rect{ pos.x + id * tab_size.x + 3 + 2.0f, pos.y + current_pos.y - 4, 200, button_size + 3 }, button_name, col, false, 10);
		}
		current_pos.y += button_size;
	}

	void Slider(vector2 pos, uintptr_t text, vector2& current_pos, vector2 value, float& out, int id, float font_size = 0)
	{
		const float button_size = 16;

		out = gui::methods::HorizontalSlider(rust::classes::Rect(pos.x + id * tab_size.x + 3 + 2.0f + 1, pos.y + current_pos.y - 4 + 1, 200, button_size + 3), out, value.x, value.y);

		gui::Label(rust::classes::Rect{ pos.x + id * tab_size.x + 3 + 2.0f + 1 + 210, pos.y + current_pos.y - 4 + 1, 200, button_size + 3 }, text, gui::Color(0, 0, 0, 120), false, 10);
		gui::Label(rust::classes::Rect{ pos.x + id * tab_size.x + 3 + 2.0f + 210, pos.y + current_pos.y - 4, 200, button_size + 3 }, text, Color(255, 255, 255, 220), false, 10);

		current_pos.y += button_size + 5;

	}

	float out;

	void OnGUI(uintptr_t rcx)
	{
		tab_size = vector2(100, 35);
		init();

		if (esp::local_player)
			tick_time_when_called = esp::local_player->get_last_sent_ticket_time();

		auto current = methods::get_current();
		auto event_type = methods::get_type(current);

		if (event_type == rust::classes::EventType::KeyDown || event_type == rust::classes::EventType::KeyUp) {
			rust::classes::KeyCode cur = unity::get_keyCode(current);
			if (event_type == rust::classes::EventType::KeyDown)
				OnKeyDown(cur);
			else
				OnKeyUp(cur);
		}

		auto mouse = get_mousePosition();
		auto height = unity::get_height();

		vector2 pos, menu_pos = { 650, 200 }, menu_size = { 700, 400 }, button_size = { 200, 0 }, mouse_pos = { mouse.x, height - mouse.y };

		if (event_type == rust::classes::EventType::Repaint) {
			gui::Label(rust::classes::Rect{ 10 + 2.0f + 1, 20 - 4 + 1, 300, 50 }, _(L"nekocheat"), gui::Color(0, 0, 0, 120), false, 24);
			gui::Label(rust::classes::Rect{ 10 + 2.0f, 20 - 4, 300, 50 }, _(L"nekocheat"), gui::Color(255, 255, 255, 220), false, 24);

			//if (settings::visuals::raid_esp) {
			///*else if (settings::visuals::raid_esp && *(int*)(object_name.zpad + 45) == 'kcor') {
			//	auto reusableInstace = il2cpp::value(_("Effect"), _("reusableInstace"), false);

			//	auto world_pos = *reinterpret_cast<vector3*>(reusableInstace + 0x5C);

			//	esp_name = il2cpp::methods::new_string(_("Rocket Explosion"));
			//	esp_color = vector4(255, 0, 0, 255);
			//}
			//else if (settings::visuals::raid_esp && *(int*)(object_name.zpad + 32) == 'e_4c') {
			//	esp_name = il2cpp::methods::new_string(_("C4 Explosion"));
			//	esp_color = vector4(255, 0, 0, 255);
			//}*/
			//	auto reusableInstace = il2cpp::value(_("Effect"), _("reusableInstace"), false);

			//	auto draw_explosion = [&](const char* explosion_name) {
			//		auto world_position = *reinterpret_cast<vector3*>(reusableInstace + 0x5C);
			//		vector2 w2s_position = {};
			//		if (esp::out_w2s(world_position, w2s_position)) {
			//			esp::draw_item(w2s_position, il2cpp::methods::new_string(_("Rocket Explosion")), { 255,0,0,255 });
			//		}
			//	};

			//	if (reusableInstace) {
			//		auto world_position = *reinterpret_cast<transform**>(reusableInstace + 0x78);

			//		auto esp_name = (str)(*reinterpret_cast<uintptr_t*>(reusableInstace + 0x88));
			//		auto name = esp_name->str;

			//		LOG("Prefab names: %ls", name);

			//		//auto int_name = *(int*)(name + 32);

			//		//if (*(int*)(name + 45) == 6357039) {
			//		//	draw_explosion(_("Rocket Explosion"));
			//		//}
			//		//else if (int_name == 'orht') {
			//		//	draw_explosion(_("C4 Explosion"));
			//		//}

			//		if (m_wcsicmp(name, _(L"assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion.prefab"))) {
			//			draw_explosion(_("Rocket Explosion"));
			//		}
			//		else if (m_wcsicmp(name, _(L"assets/prefabs/tools/c4/effects/c4_explosion.prefab"))) {
			//			draw_explosion(_("C4 Explosion"));
			//		}
			//	}
			//}

			esp::start();
		}

		if (open) {
			unity::set_lockstate(rust::classes::CursorLockMode::None);

			//fill_box(rust::classes::Rect(menu_pos.x, menu_pos.y, menu_size.x, menu_size.y), Color(0, 0, 0, 0.7));

			//fill_box(rust::classes::Rect(menu_pos.x, menu_pos.y, menu_size.x, 30), Color(0.82, 0.32, 0, 1));

			gui::Label(rust::classes::Rect{ menu_pos.x + 2.0f + 1, menu_pos.y - 4 + 1, menu_size.x, 30 }, _(L"nekocheat"), gui::Color(0, 0, 0, 120), true, 16);
			gui::Label(rust::classes::Rect{ menu_pos.x + 2.0f, menu_pos.y - 4, menu_size.x, 30 }, _(L"nekocheat"), gui::Color(255, 255, 255, 220), true, 16);

			menu_pos.y += 30;
			menu_size.y -= 25;

			auto weapon_tab = 0, visual_tab = 1, misc_tab = 2;

			tab(event_type, menu_pos, mouse_pos, _(L"Weapon"), weapon_tab);
			tab(event_type, menu_pos, mouse_pos, _(L"Visual"), visual_tab);
			tab(event_type, menu_pos, mouse_pos, _(L"Misc"), misc_tab);

			menu_pos = { menu_pos.x, menu_pos.y + 30 };
			menu_size.x -= 90;
			menu_size.y -= 15;

			if (settings::misc::code_lock_code < 1000)
				settings::misc::code_lock_code = 1000;
			else if(settings::misc::code_lock_code > 9999)
				settings::misc::code_lock_code = 9999;

			switch (active_tab) {
			case 0:
				button(event_type, menu_pos, pos, mouse_pos, _(L"Silent Aim"), &settings::weapon::psilent, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Magic Bullet"), &settings::weapon::magic_bullet, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Thick Bullet"), &settings::weapon::thick_bullet, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Silent Melee"), &settings::weapon::silent_melee, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Weapon Removals"), &settings::weapon::weapon_removals, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Always Shoot"), &settings::weapon::always_shoot, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Always Headshot"), &settings::weapon::hitbox_override, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Always Random Hitbox"), &settings::weapon::random_hitbox, weapon_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Fast bullet"), &settings::weapon::fast_bullet, weapon_tab);
				//Slider(menu_pos, il2cpp::methods::new_string(string::format(_("%s %.3f"), _("ProjectileVelocityScale:"), settings::weapon::projectile_velocit_scale)), pos, { 0.1,1.5 }, settings::weapon::projectile_velocit_scale, weapon_tab);
				break;
			case 1:
				button(event_type, menu_pos, pos, mouse_pos, _(L"Players"), &settings::visuals::player_esp, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Chams"), &settings::visuals::chams, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Sleeper"), &settings::visuals::sleeper_esp, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Misc"), &settings::visuals::misc_esp, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Helicopter"), &settings::visuals::heli_esp, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"NPC"), &settings::visuals::npc_esp, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Dropped Items"), &settings::visuals::dropped_items, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Stashes"), &settings::visuals::stash, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Stone Ore"), &settings::visuals::stone_ore, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Metal Ore"), &settings::visuals::metal_ore, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Sulfur Ore"), &settings::visuals::sulfur_ore, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Traps"), &settings::visuals::traps, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Vehicles"), &settings::visuals::vehicles, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Airdrops"), &settings::visuals::airdrops, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Cloth"), &settings::visuals::cloth, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Corpses"), &settings::visuals::corpses, visual_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Tool Cupboard"), &settings::visuals::tc_esp, visual_tab);
				//button(event_type, menu_pos, pos, mouse_pos, _(L"Raids"), &settings::visuals::raid_esp, visual_tab);
				break;
			case 2:
				button(event_type, menu_pos, pos, mouse_pos, _(L"Shoot while mounted"), &settings::misc::attack_on_mountables, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Silent Farm"), &settings::misc::silent_farm, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Speedhack"), &settings::misc::speedhack, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Take Fall Damage"), &settings::misc::TakeFallDamage, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Always Sprint"), &settings::misc::always_sprint, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Low Gravity"), &settings::misc::gravity, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Spinbot"), &settings::misc::spinbot, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Infinite Jump"), &settings::misc::infinite_jump, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Fake Lag"), &settings::misc::fake_lag, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Admin Mode"), &settings::misc::admin_mode, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"Instant Med"), &settings::misc::instant_med, misc_tab, Color(255, 0, 0, 230));
				button(event_type, menu_pos, pos, mouse_pos, _(L"Instant Revive"), &settings::misc::instant_revive, misc_tab);
				button(event_type, menu_pos, pos, mouse_pos, _(L"No Collisions"), &settings::misc::no_playercollision, misc_tab);

				button(event_type, menu_pos, pos, mouse_pos, _(L"Auto lock"), &settings::misc::auto_lock, misc_tab);
				if (settings::misc::auto_lock) {
					Slider(menu_pos, il2cpp::methods::new_string(string::format(_("%s %d"), _("Code:"), (int)settings::misc::code_lock_code)), pos, { 1000, 9999 }, settings::misc::code_lock_code, weapon_tab);
					settings::misc::code_lock_code = (int)settings::misc::code_lock_code;
				}
				break;
			default:
				break;
			};
			pos = {0, 0};
		}
	}
}

float unity::get_fov(vector3 Pos) {
	esp::matrix = unity::get_view_matrix();

	vector3 ScreenPos = WorldToScreen(Pos);
	if (ScreenPos.is_empty())
		return 1000;

	return get_2d_dist(vector2(unity::get_width() / 2, unity::get_height() / 2), ScreenPos);
}

void ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b)
{
	if (s == 0.0f)
	{
		// gray
		out_r = out_g = out_b = v;
		return;
	}

	h = my_fmod(h, 1.0f) / (60.0f / 360.0f);
	int   i = (int)h;
	float f = h - (float)i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - s * f);
	float t = v * (1.0f - s * (1.0f - f));

	switch (i)
	{
	case 0: out_r = v; out_g = t; out_b = p; break;
	case 1: out_r = q; out_g = v; out_b = p; break;
	case 2: out_r = p; out_g = v; out_b = t; break;
	case 3: out_r = p; out_g = q; out_b = v; break;
	case 4: out_r = t; out_g = p; out_b = v; break;
	case 5: default: out_r = v; out_g = p; out_b = q; break;
	}
}

gui::Color HSV(float h, float s, float v, float a = 1.0f) { float r, g, b; ColorConvertHSVtoRGB(h, s, v, r, g, b); return gui::Color(r, g, b, a); }

void esp::draw_heli(float x, float y, float w, float h) {
	gui::outline_box({ x - w / 2, y + 1 - h / 2 }, { w, h - 2 }, { 255, 255, 255, 255 });
	gui::outline_box({ x - w / 2, y + 1 - h / 2 }, { w, h - 2 }, { 0, 0, 0, 30 });
}

void esp::draw_tool_cupboard(vector2 w2s_position, uintptr_t new_str_text, vector4 color, rust::list<PlayerNameID*>* authorizedPlayers_list)
{
	auto label = [&](float y,wchar_t* text)
	{
		gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3 - y, 150, 20 }, text, gui::Color(0, 0, 0, 120), false, 12);
		gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2 - y, 150, 20 }, text, gui::Color(color.x, color.y, color.z, color.w), false, 12);
	};

	gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3, 150, 20 }, new_str_text, gui::Color(0, 0, 0, 120), false, 12);
	gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2, 150, 20 }, new_str_text, gui::Color(color.x, color.y, color.z, color.w), false, 12);
	float info_y = 12;

	authorizedPlayers_list->for_each([&](PlayerNameID* authorizedPlayer, int32_t idx) {
		if (authorizedPlayer)
		{
			auto user = authorizedPlayer->get_username();
			label(info_y, user);

			LOG("Username: %ls", user);
			info_y += 30;
		}
	});
}

void esp::draw_hackable_crate(vector2 w2s_position, uintptr_t crate, vector4 color)
{
	auto label = [&](float y, wchar_t* text)
	{
		gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3 + y, 150, 20 }, text, gui::Color(0, 0, 0, 120), false, 14);
		gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2 + y, 150, 20 }, text, gui::Color(color.x, color.y, color.z, color.w), false, 14);
	};

	auto timer_text = *reinterpret_cast<uintptr_t*>(crate + 0x440);
	if (!timer_text)
		return;

	auto text = (str)(*reinterpret_cast<uintptr_t*>(timer_text + 0xD0));
	if (!text)
		return;

	auto m_Text = text->str;
	if (!m_Text)
		return;

	gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3, 150, 20 }, _(L"Hackable Crate"), gui::Color(0, 0, 0, 120), false, 14);
	gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2, 150, 20 }, _(L"Hackable Crate"), gui::Color(color.x, color.y, color.z, color.w), false, 14);
	label(12, m_Text);
}

void esp::draw_item(vector2 w2s_position, uintptr_t label, vector4 color, wchar_t* name) { // vector4 because color gui im mretard dont talk about it
	color /= 255;
	if (label) {
		gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3, 150, 20 }, label, gui::Color(0, 0, 0, 120), false, 12);
		gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2, 150, 20 }, label, gui::Color(color.x, color.y, color.z, color.w), false, 12);
	}
	else {
		gui::Label(rust::classes::Rect{ w2s_position.x + 1, w2s_position.y + 3, 150, 20 }, name, gui::Color(0, 0, 0, 120), false, 12);
		gui::Label(rust::classes::Rect{ w2s_position.x, w2s_position.y + 2, 150, 20 }, name, gui::Color(color.x, color.y, color.z, color.w), false, 12);
	}
}

void esp::draw_target_hotbar(aim_target target) {
	auto screen = WorldToScreen(target.pos);

	if (target.player && !target.is_heli && screen.z != 0 && !target.teammate) {
		auto draw_item = [&](bool draw_wearable, float x, float width) {
			rust::list<weapon*>* belt = target.player->get_belt_items();
			if (draw_wearable)
				belt = target.player->get_wearable_items();

			if (belt) {
				float info_y = 0;
				weapon* result = nullptr;

				belt->for_each([&](weapon* item, int32_t idx) {
					if (!item)
						return;

					const auto item_name = item->get_weapon_name();
					if (item_name) {
						auto sprite = get_iconSprite(item);
						if (!sprite)
							return;

						auto texture = get_texture(sprite);
						if (!texture)
							return;

						auto rect = get_rect(sprite);
						gui::fill_box({ 680 + info_y, 900, 75, 75 }, { 0, 0, 0, 0.12 });

						//gui::Label(rust::classes::Rect{ 600, 920, 200, 200 }, target.player->get_player_name(), gui::Color(0, 0, 0, 120), true, 12);
						//gui::Label(rust::classes::Rect{ 600, 920, 200, 200 }, target.player->get_player_name(), gui::Color(255, 255, 255, 220), true, 12);

						gui::methods::set_color({ 1, 1, 1, 1 });
						gui::methods::DrawTexture({ 680 + info_y, 900, rect.wid / 3.8f, rect.hei / 3.8f }, texture);
						//gui::Label(rust::classes::Rect{ x + 2.0f + 1, info_y - 4 + 13 + 1, width - 10, height / current_item }, item_name, gui::Color(0, 0, 0, 120), true, 12);
						//gui::Label(rust::classes::Rect{ x + 2.0f, info_y - 4 + 13, width - 10, height / current_item }, item_name, gui::Color(255, 255, 255, 220), true, 12);
						info_y += 80;
					}
					});
				info_y = 0;
			}
		};

		float width = 260;
		draw_item(false, (unity::get_width() - width) / 2, width);
		//draw_item(true, (unity::get_width() - (width + width) / 2), width);
	}
}

//void esp::draw_target_snap_line()
//{
//	if (!esp::local_player)
//		return;
//
//	auto game_object = esp::local_player->get_game_object();
//
//	auto behaviour = game_object->get_class<mono_behaviour*>();
//
//	auto transform = behaviour->get_transform();
//
//	auto local_pos = transform->get_object_position();
//
//	auto target = esp::local_player->get_aimbot_target(local_pos);
//
//	vector2 local_foot_w2s, target_pos_w2s;
//	if (!out_w2s(target.pos, target_pos_w2s))
//		return;
//
//	if (!out_w2s(local_pos, local_foot_w2s))
//		return;
//
//	if (!target.teammate)
//	{
//		gui::outline_box({ local_foot_w2s.x, local_foot_w2s.y, 0 }, { target_pos_w2s.x, target_pos_w2s.y, 0 }, { 255,0,0,255 }, 0.1, false, true);
//
//	}
//}

void esp::draw_name(vector3 position, wchar_t* name)
{
	if (name)
	{
		gui::Label(rust::classes::Rect{ position.x + 2.0f + 1, position.y - 4 + 1, 150, 20 }, name, gui::Color(0, 0, 0, 120), false, 12);
		gui::Label(rust::classes::Rect{ position.x + 2.0f, position.y - 4, 150, 20 }, name, gui::Color(255, 255, 255, 220), false, 12);
	}
}

void esp::draw_weapon_icon(weapon* item, vector2 w2s_position) {

	auto sprite = get_iconSprite(item);
	if (!sprite)
		return;

	auto texture = get_texture(sprite);
	if (!texture)
		return;

	auto rect = get_rect(sprite);
	if (texture) {
		gui::methods::set_color({ 1, 1, 1, 1 });
		gui::methods::DrawTexture({ w2s_position.x + 2.0f + 1, w2s_position.y - 4 + 13 + 1, rect.wid / 7, rect.hei / 7 }, texture);
		//gui::Label({ w2s_position.x + 2.0f + 1, w2s_position.y - 4 + 13 + 1, rect.wid / 7, rect.hei / 7 }, il2cpp::methods::new_string(_("")), gui::Color(196, 124, 0, 255));
	}
}

void esp::draw_player(base_player* player, bool is_npc)
{
	if (!local_player)
		return;

	auto visible_color = gui::Color(0.42, 0.36, 0.90, 1);
	auto invisible_color = gui::Color(1, 0.46, 0.46, 1);
	auto teammate_color = gui::Color(0.33, 0.93, 0.76, 1);
	auto safezone_color = gui::Color{ 0.18, 0.8, 0.44, 1.0 };
	bounds_t bounds;

	struct bone_t {
		vector3 screen;
		int8_t     index;
		bool       on_screen;
		vector3 world_position;
		bool visible;
	};

	std::array<bone_t, 20> bones = {
		bone_t{ vector3{}, 17, false, vector3{}, false }, bone_t{ vector3{}, 18, false, vector3{}, false },
		bone_t{ vector3{}, 15, false, vector3{}, false }, bone_t{ vector3{}, 14, false, vector3{}, false },
		bone_t{ vector3{}, 1, false, vector3{}, false },  bone_t{ vector3{}, 2, false, vector3{}, false },
		bone_t{ vector3{}, 3, false, vector3{}, false },  bone_t{ vector3{}, 6, false, vector3{}, false },
		bone_t{ vector3{}, 5, false, vector3{}, false },  bone_t{ vector3{}, 21, false, vector3{}, false },
		bone_t{ vector3{}, 23, false, vector3{}, false }, bone_t{ vector3{}, 48, false, vector3{}, false },
		bone_t{ vector3{}, 24, false, vector3{}, false }, bone_t{ vector3{}, 25, false, vector3{}, false },
		bone_t{ vector3{}, 26, false, vector3{}, false }, bone_t{ vector3{}, 27, false, vector3{}, false },
		bone_t{ vector3{}, 55, false, vector3{}, false }, bone_t{ vector3{}, 56, false, vector3{}, false },
		bone_t{ vector3{}, 57, false, vector3{}, false }, bone_t{ vector3{}, 76, false, vector3{}, false }
	};

	bool is_visible = false;

	bool is_teammate = player->is_teammate(local_player);

	auto camera_position = unity::get_camera_pos();

	const auto get_bounds = [&](bounds_t& out, float expand = 0) -> bool {
		bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

		for (auto& [bone_screen, bone_idx, on_screen, world_position, visible] : bones) {

			auto transform = player->get_bone_transform(bone_idx);

			world_position = transform->get_bone_position();

			if (bone_idx == 48) // lol
				world_position.y += 0.2f;

			bone_screen = WorldToScreen(world_position);
			if (bone_screen.x < bounds.left)
				bounds.left = bone_screen.x;
			if (bone_screen.x > bounds.right)
				bounds.right = bone_screen.x;
			if (bone_screen.y < bounds.top)
				bounds.top = bone_screen.y;
			if (bone_screen.y > bounds.bottom)
				bounds.bottom = bone_screen.y;
			on_screen = true;
		}

		if (bounds.left == FLT_MAX)
			return false;
		if (bounds.right == FLT_MIN)
			return false;
		if (bounds.top == FLT_MAX)
			return false;
		if (bounds.bottom == FLT_MIN)
			return false;

		bounds.left -= expand;
		bounds.right += expand;
		bounds.top -= expand;
		bounds.bottom += expand;

		out = bounds;

		return true;
	};

	if (get_bounds(bounds, 4)) {
		if (!is_visible)
			is_visible = player->is_visible(camera_position, bones[16].world_position);

		gui::Color clr = !is_teammate ? (is_visible ? visible_color : invisible_color) : teammate_color;
		if (HasPlayerFlag(player, rust::classes::PlayerFlags::SafeZone))
			clr = safezone_color;

		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;

		wchar_t* name = player->get_player_name();
		auto player_weapon = player->get_active_weapon();

		gui::outline_box(vector2{ bounds.left - 1, bounds.top - 1 }, vector2{ box_width + 2, box_height + 2 }, gui::Color(0, 0, 0, 120));
		gui::outline_box(vector2{ bounds.left, bounds.top }, vector2{ box_width, box_height }, clr);
		gui::outline_box(vector2{ bounds.left + 1, bounds.top + 1 }, vector2{ box_width - 2, box_height - 2 }, gui::Color(0, 0, 0, 120));

		const auto cur_health = player->get_health();
		const auto max_health = (is_npc ? player->get_max_health() : 100);
		const auto health_pc = min(cur_health / max_health, 1);
		const auto health_color =
			HSV((health_pc * .25f), 1, .875f * 1);

		const auto     height = (bounds.bottom - bounds.top) * health_pc;


		gui::fill_box(rust::classes::Rect(bounds.left - 5, bounds.top, 4, box_height), gui::Color(0, 0, 0, 120));
		gui::fill_box(rust::classes::Rect(bounds.left - 4, bounds.top + box_height - height - 1, 2, height), health_color);

		if (player_weapon)
		{
			auto sprite = get_iconSprite(player_weapon);
			if (!sprite)
				return;

			auto texture = get_texture(sprite);
			if (!texture)
				return;

			auto rect = get_rect(sprite);
			if (texture) {
				gui::methods::set_color({ 1, 1, 1, 1 });
				gui::methods::DrawTexture({ bounds.right + 2.0f + 1, bounds.top - 4 + 13 + 1, rect.wid / 7, rect.hei / 7 }, texture);
			}

			/*auto weapon_name = player_weapon->get_weapon_name();
			if (weapon_name)
			{
				gui::Label(rust::classes::Rect{ bounds.right + 2.0f + 1, bounds.top - 4 + 13 + 1, 150, 20 }, weapon_name, gui::Color(0, 0, 0, 120), false, 9);
				gui::Label(rust::classes::Rect{ bounds.right + 2.0f, bounds.top - 4 + 13, 150, 20 }, weapon_name, gui::Color(255, 255, 255, 220), false, 9);
			}*/
		}

		if (name)
		{
			auto transform = player->get_bone_transform(48);

			auto position = transform->get_bone_position();

			auto distance = esp::local_player->get_bone_transform(48)->get_bone_position().distance(position);
			//const char* new_name = ;
			gui::Label(rust::classes::Rect{ bounds.right + 2.0f + 1, bounds.top - 4 + 1, 150, 20 }, /*il2cpp::methods::new_string(string::format(_("%ls [%dm]"), name, (int)distance))*/name, gui::Color(0, 0, 0, 120), false, 12);
			gui::Label(rust::classes::Rect{ bounds.right + 2.0f, bounds.top - 4, 150, 20 }, /*il2cpp::methods::new_string(string::format(_("%ls [%dm]"), name, (int)distance))*/name, gui::Color(255, 255, 255, 220), false, 12);
		}
	}
}