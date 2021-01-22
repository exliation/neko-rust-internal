#pragma once

#include "../memory/il2cpp.hpp"

#include "rust.hpp"

namespace unity {
	static auto set_lockstate = reinterpret_cast<void(*)(rust::classes::CursorLockMode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Cursor"), _("set_lockState"), 1, _("value"), _("UnityEngine"))));

	static auto get_width = reinterpret_cast<int (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Screen"), _("get_width"), 0, _(""), _("UnityEngine"))));

	static auto get_height = reinterpret_cast<int (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Screen"), _("get_height"), 0, _(""), _("UnityEngine"))));

	static auto GetKeyDown = reinterpret_cast<bool(*)(rust::classes::KeyCode key)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyDown"), 1, _("key"), _("UnityEngine"), 1)));

	static auto get_main_camera = reinterpret_cast<uintptr_t(*)()>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::get_main()")));

	static auto IgnoreLayerCollision = reinterpret_cast<void(*)(rust::classes::layer, rust::classes::layer, bool)>(il2cpp::methods::resolve_icall(_("UnityEngine.Physics::IgnoreLayerCollision()")));

	static auto get_keyCode = reinterpret_cast<rust::classes::KeyCode(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));

	static auto LineOfSight = reinterpret_cast<bool(*)(vector3, vector3, rust::classes::Layers layer, float padding)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("LineOfSight"), -1, _(""), _(""))));

	static auto GetKey = reinterpret_cast<bool(*)(rust::classes::KeyCode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));

	static auto set_visible = reinterpret_cast<void(*)(bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Cursor"), _("set_visible"), 1, _("value"), _("UnityEngine"))));

	static auto get_shader = reinterpret_cast<uintptr_t(*)(uintptr_t material)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));

	static auto set_shader = reinterpret_cast<void(*)(uintptr_t, uintptr_t)>(il2cpp::methods::resolve_icall(_("UnityEngine.Material::set_shader()")));

	void init_unity() {
		get_shader = reinterpret_cast<uintptr_t(*)(uintptr_t material)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));

		set_shader = reinterpret_cast<void(*)(uintptr_t, uintptr_t)>(il2cpp::methods::resolve_icall(_("UnityEngine.Material::set_shader()")));

		set_lockstate = reinterpret_cast<void(*)(rust::classes::CursorLockMode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Cursor"), _("set_lockState"), 1, _("value"), _("UnityEngine"))));

		set_visible = reinterpret_cast<void(*)(bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Cursor"), _("set_visible"), 1, _("value"), _("UnityEngine"))));

		get_width = reinterpret_cast<int (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Screen"), _("get_width"), 0, _(""), _("UnityEngine"))));

		get_height = reinterpret_cast<int (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Screen"), _("get_height"), 0, _(""), _("UnityEngine"))));

		GetKeyDown = reinterpret_cast<bool(*)(rust::classes::KeyCode key)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyDown"), 1, _("key"), _("UnityEngine"), 1)));

		get_main_camera = reinterpret_cast<uintptr_t(*)()>(il2cpp::methods::resolve_icall(_("UnityEngine.Camera::get_main()")));

		IgnoreLayerCollision = reinterpret_cast<void(*)(rust::classes::layer, rust::classes::layer, bool)>(il2cpp::methods::resolve_icall(_("UnityEngine.Physics::IgnoreLayerCollision()")));

		get_keyCode = reinterpret_cast<rust::classes::KeyCode(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));

		LineOfSight = reinterpret_cast<bool(*)(vector3, vector3, rust::classes::Layers layer, float padding)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("LineOfSight"), -1, _(""), _(""))));

		GetKey = reinterpret_cast<bool(*)(rust::classes::KeyCode)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));
	}

	bool is_visible(vector3 source, vector3 destination) {
		auto layer = (int)rust::classes::Layers::ProjectileLineOfSightCheck | (int)rust::classes::Layers::Terrain;

		return LineOfSight(source, destination, rust::classes::Layers(layer), 0);
	}

	auto camera = unity::get_main_camera();

	VMatrix get_view_matrix() {
		if (!camera) {
			camera = unity::get_main_camera();
		}

		auto camera_ = mem::read<uintptr_t>(camera + 0x10);
		if (!camera_) {
			camera = unity::get_main_camera();
			return {};
		}

		auto matrix = mem::read<VMatrix>(camera_ + 0x2E4);
		if (!matrix.m) {
			camera = unity::get_main_camera();
			return {};
		}

		return matrix;
	}

	vector3 get_camera_pos() {
		if (!camera) {
			camera = unity::get_main_camera();
		}

		auto camera_ = mem::read<uintptr_t>(camera + 0x10);
		if (!camera_) {
			camera = unity::get_main_camera();
			return {};
		}

		auto matrix = mem::read<vector3>(camera_ + 0x42C);
		if (!matrix.x || !matrix.y) {
			camera = unity::get_main_camera();
			return {};
		}


		return matrix;
	}
	float get_fov(vector3 Pos);
}