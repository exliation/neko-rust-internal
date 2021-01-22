#pragma once
#include "../utils/vector.hpp"
#include "../memory/il2cpp.hpp"

#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define DEFINE_MEMBER_N(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}
#define min(a,b)            (((a) < (b)) ? (a) : (b))

namespace rust {
	template<typename T>
	class list {
	public:
		T get(uint32_t idx)
		{
			const auto internal_list = reinterpret_cast<uintptr_t>(this + 0x20);
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}
		
		T get_value(uint32_t idx)
		{
			const auto list = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			const auto internal_list = list + 0x20;
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}

		T operator[](uint32_t idx) { return get(idx); }

		const uint32_t get_size() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

		template<typename F>
		void for_each(const F callback)
		{
			for (auto i = 0; i < get_size(); i++) {
				auto object = this->get(i);
				if (!object)
					continue;
				callback(object, i);
			}
		}
	};

	namespace classes {
		enum class layer : uint32_t {
			Default = 0,
			TransparentFX = 1,
			Ignore_Raycast = 2,
			Reserved1 = 3,
			Water = 4,
			UI = 5,
			Reserved2 = 6,
			Reserved3 = 7,
			Deployed = 8,
			Ragdoll = 9,
			Invisible = 10,
			AI = 11,
			PlayerMovement = 12,
			Vehicle_Detailed = 13,
			Game_Trace = 14,
			Vehicle_World = 15,
			World = 16,
			Player_Server = 17,
			Trigger = 18,
			Player_Model_Rendering = 19,
			Physics_Projectile = 20,
			Construction = 21,
			Construction_Socket = 22,
			Terrain = 23,
			Transparent = 24,
			Clutter = 25,
			Debris = 26,
			Vehicle_Large = 27,
			Prevent_Movement = 28,
			Prevent_Building = 29,
			Tree = 30,
			Unused2 = 31
		};

		enum objects
		{
			MAINCAMERA = 5,
			PLAYER = 6,
			TERRAIN = 20001,
			CORPSE = 20009, //Animals & Players
			MISC = 20006, //Trash cans, Sleeping Bags, Storage Box, etc
			ANIMAL = 20008,
			SKYDOME = 20012,
			RIVERMESH = 20014,
			MONUMENT = 20015 //Airport, Powerplant, etc
		};

		enum class HitTestType
		{
			Generic = 0,
			ProjectileEffect = 1,
			Projectile = 2,
			MeleeAttack = 3,
			Use = 4,
		};

		class Attack {
		public:
			union {
				DEFINE_MEMBER_N(vector3, pointStart, 0x14);
				DEFINE_MEMBER_N(vector3, pointEnd, 0x18);
				DEFINE_MEMBER_N(unsigned int, hitID, 0x2C);
				DEFINE_MEMBER_N(unsigned int, hitBone, 0x30);
				DEFINE_MEMBER_N(vector3, hitNormalLocal, 0x34);
				DEFINE_MEMBER_N(vector3, hitPositionLocal, 0x40);
				DEFINE_MEMBER_N(vector3, hitNormalWorld, 0x4C);
				DEFINE_MEMBER_N(vector3, hitPositionWorld, 0x48);
				DEFINE_MEMBER_N(unsigned int, hitPartID, 0x64);
				DEFINE_MEMBER_N(unsigned int, hitMaterialID, 0x68);
				DEFINE_MEMBER_N(unsigned int, hitItem, 0x6C);
			};
		};

		class game_object {
		public:
			template<typename T>
			T get_class()
			{
				return *reinterpret_cast<T*>((uintptr_t)this + 0x30);
			}

			template<typename T>
			T get_class(uint32_t second_offset)
			{
				const auto object = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x30);
				if (!object)
					return nullptr;

				return *reinterpret_cast<T*>(object + second_offset);
			}

			char* get_prefab_name() { return *reinterpret_cast<char**>((uintptr_t)this + 0x60); }

			uint32_t get_tag() { return *reinterpret_cast<uint16_t*>((uintptr_t)this + 0x54); }

			layer get_layer() { return *reinterpret_cast<layer*>(this + 0x50); }
		};

		class PlayerAttack {
		public:
			union {
				DEFINE_MEMBER_N(Attack*, attack, 0x18);
			};
		};

		class PlayerProjectileAttack {
		public:
			union {
				DEFINE_MEMBER_N(PlayerAttack*, playerAttack, 0x18);
				DEFINE_MEMBER_N(vector3, hitVelocity, 0x20);
				DEFINE_MEMBER_N(float, hitDistance, 0x2C);
				DEFINE_MEMBER_N(float, travelTime, 0x30);
			};
		};

		enum class Layers
		{
			Terrain = 8388608,
			World = 65536,
			Ragdolls = 512,
			Construction = 2097152,
			ConstructionSocket = 4194304,
			Craters = 1,
			GameTrace = 16384,
			Trigger = 262144,
			VehiclesDetailed = 8192,
			RainFall = 1101070337,
			Deploy = 1235288065,
			DefaultDeployVolumeCheck = 537001984,
			BuildLineOfSightCheck = 2097152,
			ProjectileLineOfSightCheck = 2162688,
			ProjectileLineOfSightCheckTerrain = 10551296,
			MeleeLineOfSightCheck = 2162688,
			EyeLineOfSightCheck = 2162688,
			EntityLineOfSightCheck = 1218519041,
			PlayerBuildings = 18874624,
			PlannerPlacement = 161546496,
			Solid = 1218652417,
			VisCulling = 10551297,
			AltitudeCheck = 1218511105,
			HABGroundEffect = 1218511105,
			AILineOfSight = 1218519297,
			DismountCheck = 1486946561,
			AIPlacement = 278986753,
			WheelRay = 1235321089,
		};

		enum class Bone_List : int
		{
			pelvis = 1,
			l_hip,
			l_knee,
			l_foot,
			l_toe,
			l_ankle_scale,
			penis,
			GenitalCensor,
			GenitalCensor_LOD0,
			Inner_LOD0,
			Inner_LOD01,
			GenitalCensor_LOD1,
			GenitalCensor_LOD2,
			r_hip, r_knee, r_foot, r_toe, r_ankle_scale, spine1, spine1_scale, spine2, spine3, spine4, l_clavicle, l_upperarm, l_forearm, l_hand, l_index1,
			l_index2, l_index3, l_little1, l_little2, l_little3, l_middle1, l_middle2, l_middle3, l_prop, l_ring1, l_ring2, l_ring3, l_thumb1, l_thumb2, l_thumb3,
			IKtarget_righthand_min, IKtarget_righthand_max, l_ulna, neck, head, jaw, eyeTranform, l_eye, l_Eyelid, r_eye, r_Eyelid, r_clavicle,
			r_upperarm, r_forearm, r_hand, r_index1, r_index2, r_index3, r_little1, r_little2, r_little3, r_middle1, r_middle2, r_middle3, r_prop,
			r_ring1, r_ring2, r_ring3, r_thumb1, r_thumb2, r_thumb3, IKtarget_lefthand_min, IKtarget_lefthand_max, r_ulna, l_breast, r_breast, BoobCensor,
			BreastCensor_LOD0, Inner_LOD02, Inner_LOD03, BreastCensor_LOD1, BreastCensor_LOD2
		};

		class list {
		public:
			template <typename T>
			T get_value() {
				auto list = *reinterpret_cast<uintptr_t*>(this + 0x10);
				if (!list)
					return 0;

				auto value = *reinterpret_cast<T*>(list + 0x28);
				if (!value)
					return 0;
				return value;
			}

			int get_size() {
				auto value = get_value<uintptr_t>();
				if (!value)
					return 0;

				auto size = mem::read<int>(value + 0x10);
				if (!size)
					return 0;
			}

			template <typename T>
			T get_buffer() {
				auto value = get_value<uintptr_t>();

				return *reinterpret_cast<uintptr_t*>(value + 0x18);
			}
		};

		enum class KeyCode
		{
			Backspace = 8,
			Delete = 127,
			Tab = 9,
			Clear = 12,
			Return = 13,
			Pause = 19,
			Escape = 27,
			Space = 32,
			Keypad0 = 256,
			Keypad1 = 257,
			Keypad2 = 258,
			Keypad3 = 259,
			Keypad4 = 260,
			Keypad5 = 261,
			Keypad6 = 262,
			Keypad7 = 263,
			Keypad8 = 264,
			Keypad9 = 265,
			KeypadPeriod = 266,
			KeypadDivide = 267,
			KeypadMultiply = 268,
			KeypadMinus = 269,
			KeypadPlus = 270,
			KeypadEnter = 271,
			KeypadEquals = 272,
			UpArrow = 273,
			DownArrow = 274,
			RightArrow = 275,
			LeftArrow = 276,
			Insert = 277,
			Home = 278,
			End = 279,
			PageUp = 280,
			PageDown = 281,
			F1 = 282,
			F2 = 283,
			F3 = 284,
			F4 = 285,
			F5 = 286,
			F6 = 287,
			F7 = 288,
			F8 = 289,
			F9 = 290,
			F10 = 291,
			F11 = 292,
			F12 = 293,
			F13 = 294,
			F14 = 295,
			F15 = 296,
			Alpha0 = 48,
			Alpha1 = 49,
			Alpha2 = 50,
			Alpha3 = 51,
			Alpha4 = 52,
			Alpha5 = 53,
			Alpha6 = 54,
			Alpha7 = 55,
			Alpha8 = 56,
			Alpha9 = 57,
			Exclaim = 33,
			DoubleQuote = 34,
			Hash = 35,
			Dollar = 36,
			Percent = 37,
			Ampersand = 38,
			Quote = 39,
			LeftParen = 40,
			RightParen = 41,
			Asterisk = 42,
			Plus = 43,
			Comma = 44,
			Minus = 45,
			Period = 46,
			Slash = 47,
			Colon = 58,
			Semicolon = 59,
			Less = 60,
			Equals = 61,
			Greater = 62,
			Question = 63,
			At = 64,
			LeftBracket = 91,
			Backslash = 92,
			RightBracket = 93,
			Caret = 94,
			Underscore = 95,
			BackQuote = 96,
			A = 97,
			B = 98,
			C = 99,
			D = 100,
			E = 101,
			F = 102,
			G = 103,
			H = 104,
			I = 105,
			J = 106,
			K = 107,
			L = 108,
			M = 109,
			N = 110,
			O = 111,
			P = 112,
			Q = 113,
			R = 114,
			S = 115,
			T = 116,
			U = 117,
			V = 118,
			W = 119,
			X = 120,
			Y = 121,
			Z = 122,
			LeftCurlyBracket = 123,
			Pipe = 124,
			RightCurlyBracket = 125,
			Tilde = 126,
			Numlock = 300,
			CapsLock = 301,
			ScrollLock = 302,
			RightShift = 303,
			LeftShift = 304,
			RightControl = 305,
			LeftControl = 306,
			RightAlt = 307,
			LeftAlt = 308,
			LeftCommand = 310,
			LeftApple = 310,
			LeftWindows = 311,
			RightCommand = 309,
			RightApple = 309,
			RightWindows = 312,
			AltGr = 313,
			Help = 315,
			Pr = 316,
			SysReq = 317,
			Break = 318,
			Menu = 319,
			Mouse0 = 323,
			Mouse1 = 324,
			Mouse2 = 325,
			Mouse3 = 326,
			Mouse4 = 327,
			Mouse5 = 328,
			Mouse6 = 329
		};

		enum class CursorLockMode
		{
			None = 0,
			Locked = 1,
			Confined = 2
		};

		enum class PlayerFlags
		{
			Unused1 = 1,
			Unused2 = 2,
			IsAdmin = 4,
			ReceivingSnapshot = 8,
			Sleeping = 16,
			Spectating = 32,
			Wounded = 64,
			IsDeveloper = 128,
			Connected = 256,
			ThirdPersonViewmode = 1024,
			EyesViewmode = 2048,
			ChatMute = 4096,
			NoSprint = 8192,
			Aiming = 16384,
			DisplaySash = 32768,
			Relaxed = 65536,
			SafeZone = 131072,
			ServerFall = 262144,
			Workbench1 = 1048576,
			Workbench2 = 2097152,
			Workbench3 = 4194304,
		};

		enum class ModelState_Flag
		{
			Ducked = 1,
			Jumped = 2,
			OnGround = 4,
			Sleeping = 8,
			Sprinting = 16,
			OnLadder = 32,
			Flying = 64,
			Aiming = 128,
			Prone = 256,
			Mounted = 512,
			Relaxed = 1024,
		};

		class string {
		public:
			char zpad[0x10];

			int size;
			wchar_t str[128 + 1];
			string(const wchar_t* st) {
				size = min(m_wcslen((wchar_t*)st), 128);
				for (int i = 0; i < size; i++) {
					str[i] = st[i];
				}
				str[size] = 0;
			}
		};

		class Rect {
		public:
			float x; // 0x10
			float y; // 0x14
			float wid; // 0x18
			float hei; // 0x1C
			Rect(float x, float y/*top left*/, float x_rightsize, float y_downsize) {
				this->x = x;
				this->y = y;
				wid = x_rightsize;
				hei = y_downsize;
			}
			Rect() {
				this->x = 0;
				this->y = 0;
				wid = 0;
				hei = 0;
			}
			bool Contains(vector2 point)
			{
				return point.x >= x && point.x < (x + wid) && point.y >= y && point.y < (y + hei);
			}
		};

		enum class EventType : int {
			MouseDown = 0,
			MouseUp = 1,
			MouseDrag = 3,
			KeyDown = 4,
			KeyUp = 5,
			Repaint = 7
		};

		class HitTest {
		public:
			union {
				//              Type     Name    Offset
				DEFINE_MEMBER_N(uintptr_t, type, 0x10);
				DEFINE_MEMBER_N(vector3, AttackRay, 0x14);
				DEFINE_MEMBER_N(float, Radius, 0x2C);
				DEFINE_MEMBER_N(float, Forgiveness, 0x30);
				DEFINE_MEMBER_N(float, MaxDistance, 0x34);
				DEFINE_MEMBER_N(uintptr_t, RayHit, 0x38);
				DEFINE_MEMBER_N(bool, MultiHit, 0x64);
				DEFINE_MEMBER_N(bool, BestHit, 0x65);
				DEFINE_MEMBER_N(bool, DidHit, 0x66);
				DEFINE_MEMBER_N(uintptr_t, damageProperties, 0x68);
				DEFINE_MEMBER_N(uintptr_t, gameObject, 0x70);
				DEFINE_MEMBER_N(uintptr_t, collider, 0x78);
				DEFINE_MEMBER_N(uintptr_t, ignoreEntity, 0x80);
				DEFINE_MEMBER_N(uintptr_t, HitEntity, 0x88);
				DEFINE_MEMBER_N(vector3, HitPoint, 0x90);
				DEFINE_MEMBER_N(vector3, HitNormal, 0x9C);
				DEFINE_MEMBER_N(vector3, HitNormal, 0x9C);
				DEFINE_MEMBER_N(float, HitDistance, 0xA8);
				DEFINE_MEMBER_N(uintptr_t, HitTransform, 0xB0);
				DEFINE_MEMBER_N(unsigned int, HitPart, 0xB8);
				DEFINE_MEMBER_N(string, HitMaterial, 0xC0);
			};
		};
	}

}