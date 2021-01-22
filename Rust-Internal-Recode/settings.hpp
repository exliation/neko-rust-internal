#pragma once

namespace settings {
	namespace weapon {
		bool hitbox_override  = true;
		bool magic_bullet  = true;
		bool random_hitbox  = true;
		bool silent_melee = true;
		bool weapon_removals  = true;
		bool always_shoot  = true;
		bool psilent = true;
		bool thick_bullet = true;
		bool fast_bullet = false;
	}

	namespace visuals {
		bool player_esp = true;
		bool chams = true;
		bool misc_esp  = false;
		bool sleeper_esp  = false;
		bool heli_esp = true;
		bool npc_esp = true;
		bool dropped_items = true;
		bool stash = true;
		bool sulfur_ore = true;
		bool stone_ore = true;
		bool metal_ore = true;
		bool traps = true;
		bool vehicles = true;
		bool airdrops = true;
		bool cloth = true;
		bool corpses = true;
		bool tc_esp = true;
		bool raid_esp = true;
		bool hackable_crate_esp = true;
	}

	namespace misc {
		float    m_idebugcam_speed = 1.f;
		float code_lock_code = 1000;
		bool spinbot  = true;
		bool attack_on_mountables = true;
		bool speedhack = false;
		bool TakeFallDamage = true;
		bool silent_farm = true;
		bool auto_lock = true;
		bool always_sprint = true;
		bool gravity = true;
		bool infinite_jump = true;
		bool fake_lag = true;
		bool admin_mode = true;
		bool view_offset  = true;
		bool instant_med  = true;
		bool instant_revive = true;
		bool no_playercollision = true;
	}
}