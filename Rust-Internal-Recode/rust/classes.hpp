#pragma once

#include "unity.hpp"
#include "../utils/xor_float.hpp"

uintptr_t _displayName = il2cpp::value(_("BasePlayer"), _("_displayName"));
uintptr_t movement = il2cpp::value(_("BasePlayer"), _("movement"));
uintptr_t player_inventory = il2cpp::value(_("BasePlayer"), _("inventory"));
uintptr_t clActiveItem = il2cpp::value(_("BasePlayer"), _("clActiveItem"));
uintptr_t playerModel = il2cpp::value(_("BasePlayer"), _("playerModel"));
uintptr_t clientTeam = il2cpp::value(_("BasePlayer"), _("clientTeam"));
uintptr_t playerFlags = il2cpp::value(_("BasePlayer"), _("playerFlags"));
uintptr_t clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
uintptr_t eyes = il2cpp::value(_("BasePlayer"), _("eyes"));
uintptr_t lastSentTickTime = il2cpp::value(_("BasePlayer"), _("lastSentTickTime"));
uintptr_t modelState = il2cpp::value(_("BasePlayer"), _("modelState"));
uintptr_t input = il2cpp::value(_("BasePlayer"), _("input"));
uintptr_t containerBelt = il2cpp::value(_("PlayerInventory"), _("containerBelt"));
uintptr_t containerWear = il2cpp::value(_("PlayerInventory"), _("containerWear"));
uintptr_t itemList = il2cpp::value(_("ItemContainer"), _("itemList"));
uintptr_t userID = il2cpp::value(_("BasePlayer"), _("userID"));
uintptr_t mounted = il2cpp::value(_("BasePlayer"), _("mounted"));

uintptr_t newVelocity = il2cpp::value(_("PlayerModel"), _("newVelocity"));
uintptr_t isLocalPlayer = il2cpp::value(_("PlayerModel"), _("isLocalPlayer"));

uintptr_t _health = il2cpp::value(_("BaseCombatEntity"), _("_health"));
uintptr_t _maxHealth = il2cpp::value(_("BaseCombatEntity"), _("_maxHealth"));
uintptr_t lifestate = il2cpp::value(_("BaseCombatEntity"), _("lifestate"));

uintptr_t net = il2cpp::value(_("BaseNetworkable"), _("net"));

uintptr_t heldEntity = il2cpp::value(_("Item"), _("heldEntity"));

uintptr_t canWieldItems = il2cpp::value(_("BaseMountable"), _("canWieldItems"));

uintptr_t recoil = il2cpp::value(_("BaseProjectile"), _("recoil"));
uintptr_t automatic = il2cpp::value(_("BaseProjectile"), _("automatic"));

uintptr_t aimSway = il2cpp::value(_("BaseProjectile"), _("aimSway"));
uintptr_t aimSwaySpeed = il2cpp::value(_("BaseProjectile"), _("aimSwaySpeed"));
uintptr_t primaryMagazine = il2cpp::value(_("BaseProjectile"), _("primaryMagazine"));

uintptr_t aimCone = il2cpp::value(_("BaseProjectile"), _("aimCone"));
uintptr_t hipAimCone = il2cpp::value(_("BaseProjectile"), _("hipAimCone"));
uintptr_t aimConePenaltyMax = il2cpp::value(_("BaseProjectile"), _("aimConePenaltyMax"));
uintptr_t aimconePenaltyPerShot = il2cpp::value(_("BaseProjectile"), _("aimconePenaltyPerShot"));
uintptr_t stancePenaltyScale = il2cpp::value(_("BaseProjectile"), _("stancePenaltyScale"));

uintptr_t successFraction = il2cpp::value(_("FlintStrikeWeapon"), _("successFraction"));
uintptr_t didSparkThisFrame = il2cpp::value(_("FlintStrikeWeapon"), _("_didSparkThisFrame"));

uintptr_t currentVelocity = il2cpp::value(_("Projectile"), _("currentVelocity"));
uintptr_t currentPosition = il2cpp::value(_("Projectile"), _("currentPosition"));
uintptr_t thickness_addr = il2cpp::value(_("Projectile"), _("thickness"));
uintptr_t projectileVelocityScale_addr = il2cpp::value(_("BaseProjectile"), _("projectileVelocityScale"));
uintptr_t mod = il2cpp::value(_("Projectile"), _("mod"));
uintptr_t hitTest = il2cpp::value(_("Projectile"), _("hitTest"));

uintptr_t damageProperties = il2cpp::value(_("BaseMelee"), _("damageProperties"));

uintptr_t weakspots = il2cpp::value(_("BaseHelicopter"), _("weakspots"));

uintptr_t info = il2cpp::value(_("Item"), _("info"));

uintptr_t iconSprite = il2cpp::value(_("ItemDefinition"), _("iconSprite"));
uintptr_t steamItem = il2cpp::value(_("ItemDefinition"), _("steamItem"));

uintptr_t category = il2cpp::value(_("ItemDefinition"), _("category"));
uintptr_t itemid = il2cpp::value(_("ItemDefinition"), _("itemid"));
uintptr_t displayName = il2cpp::value(_("ItemDefinition"), _("displayName"));

uintptr_t viewOffset = il2cpp::value(_("PlayerEyes"), _("viewOffset"));

uintptr_t swimming = il2cpp::value(_("PlayerWalkMovement"), _("swimming"));

uintptr_t lastHitTime = il2cpp::value(_("Chainsaw"), _("lastHitTime"));
uintptr_t lastHitMaterial = il2cpp::value(_("Chainsaw"), _("lastHitMaterial"));
uintptr_t gathering = il2cpp::value(_("BaseMelee"), _("gathering"));

uintptr_t nextAttackTime = il2cpp::value(_("AttackEntity"), _("nextAttackTime"));
uintptr_t timeSinceDeploy = il2cpp::value(_("AttackEntity"), _("timeSinceDeploy"));
uintptr_t deployDelay = il2cpp::value(_("AttackEntity"), _("deployDelay"));
uintptr_t repeatDelay = il2cpp::value(_("AttackEntity"), _("repeatDelay"));
uintptr_t integrity = il2cpp::value(_("Projectile"), _("integrity"));

uintptr_t groundAngleNew = il2cpp::value(_("PlayerWalkMovement"), _("groundAngleNew"));
uintptr_t landTime = il2cpp::value(_("PlayerWalkMovement"), _("landTime"));
uintptr_t jumpTime = il2cpp::value(_("PlayerWalkMovement"), _("jumpTime"));
uintptr_t groundTime = il2cpp::value(_("PlayerWalkMovement"), _("groundTime"));
uintptr_t gravityMultiplier = il2cpp::value(_("PlayerWalkMovement"), _("gravityMultiplier"));
uintptr_t flying = il2cpp::value(_("PlayerWalkMovement"), _("flying"));

uintptr_t model = il2cpp::value(_("BaseEntity"), _("model"));
class base_projectile;

class transform;

class base_player;

class HitTest;
class modelstate;
class col;

typedef struct Str
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *str;

class weapon;

static auto Line = reinterpret_cast<void (*)(vector3, vector3, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));

static auto GetIndex = reinterpret_cast<int(*)(uintptr_t SkinSetCollection, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinSetCollection"), _("GetIndex"), 1, _(""), _(""))));

static auto set_onLadder = reinterpret_cast<void(*)(modelstate*, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_onLadder"), 1, _(""), _(""))));

static auto GetWorldVelocity = reinterpret_cast<vector3(*)(base_player* base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));

static auto HasPlayerFlag = reinterpret_cast<bool(*)(base_player*, rust::classes::PlayerFlags)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("HasPlayerFlag"), 1, _(""), _(""))));

static auto get_game_object_transform = reinterpret_cast<transform * (*)(uintptr_t game_object)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("get_transform"), 0, _(""), _("UnityEngine"))));

static auto get_iconSprite = reinterpret_cast<uintptr_t(*)(weapon* Item)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));

static auto get_texture = reinterpret_cast<uintptr_t(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));

static auto get_rect = reinterpret_cast<rust::classes::Rect(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_rect"), 0, _(""), _("UnityEngine"))));

static auto StringPool_Get = reinterpret_cast<unsigned int(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("StringPool"), _("Get"), 1, _("str"), _(""))));

static auto set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("set_timeScale"), 1, _(""), _("UnityEngine"))));

static auto get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));

static auto FindBone = reinterpret_cast<transform * (*)(base_player*, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("FindBone"), 1, _(""), _(""))));

static auto get_mousePosition = reinterpret_cast<vector3 (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));

static auto FloorToInt = reinterpret_cast<int (*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("FloorToInt"), 1, _(""), _("UnityEngine"))));

static auto get_gravity = reinterpret_cast<vector3 (*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 1, _(""), _("UnityEngine"))));

static auto get_isAlive = reinterpret_cast<bool (*)(base_projectile*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));

static auto get_position = reinterpret_cast<vector3(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));

static auto Find = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));

static auto set_hideFlags = reinterpret_cast<void(*)(uintptr_t material, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_hideFlags"), 1, _(""), _("UnityEngine"))));

static auto set_name = reinterpret_cast<void(*)(uintptr_t, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_name"), 1, _(""), _("UnityEngine"))));

static auto SetInt = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));

static auto get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));

static auto get_IsNpc = reinterpret_cast<bool(*)(uintptr_t player_model)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("get_IsNpc"), -1, _(""), _(""))));

static auto get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));

static auto ClosestPoint = reinterpret_cast<vector3(*)(base_player*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 1, _("position"), _(""), 1)));

static auto InverseTransformPoint = reinterpret_cast<vector3(*)(transform*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));

static auto InverseTransformDirection = reinterpret_cast<vector3(*)(transform*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));

static auto get_transform = reinterpret_cast<transform*(*)(base_player*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));

static auto get_gameObject = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));

static auto set_position = reinterpret_cast<void(*)(transform*, vector3 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));

static auto LookRotation = reinterpret_cast<vector4(*)(vector3, vector3 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Quaternion"), _("LookRotation"), 2, _(""), _("UnityEngine"))));

static auto set_rotation = reinterpret_cast<void(*)(transform*, vector4 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));

static auto StartAttackCooldown = reinterpret_cast<void(*)(base_projectile*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));

static auto ProcessAttack = reinterpret_cast<void(*)(base_projectile*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));

static auto GetProjectileVelocityScale = reinterpret_cast<float(*)(base_projectile*, bool max)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _("getMax"), _(""), 1)));

static auto get_Renderers = reinterpret_cast<rust::list<uintptr_t>*(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));

static auto get_material = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));

class col {
public:
	float r;
	float g;
	float b;
	float a;
	col(float rr, float gg, float bb, float aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}
};

static auto SetColor = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, col value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));

float current_time;

void init_bp() {
	Line = reinterpret_cast<void (*)(vector3, vector3, col, float, bool, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
	set_onLadder = reinterpret_cast<void(*)(modelstate*, bool)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_onLadder"), 1, _(""), _(""))));
	GetWorldVelocity = reinterpret_cast<vector3(*)(base_player* base_entity)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
	HasPlayerFlag = reinterpret_cast<bool(*)(base_player*, rust::classes::PlayerFlags)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("HasPlayerFlag"), 1, _(""), _(""))));
	get_game_object_transform = reinterpret_cast<transform * (*)(uintptr_t game_object)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("GameObject"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	get_rect = reinterpret_cast<rust::classes::Rect(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_rect"), 0, _(""), _("UnityEngine"))));
	get_iconSprite = reinterpret_cast<uintptr_t(*)(weapon* Item)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
	steamItem = il2cpp::value(_("ItemDefinition"), _("steamItem"));
	iconSprite = il2cpp::value(_("ItemDefinition"), _("iconSprite"));
	get_texture = reinterpret_cast<uintptr_t(*)(uintptr_t sprite)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));
	set_name = reinterpret_cast<void(*)(uintptr_t, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_name"), 1, _(""), _("UnityEngine"))));;
	get_gameObject = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));
	InverseTransformDirection = reinterpret_cast<vector3(*)(transform*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));
	LookRotation = reinterpret_cast<vector4(*)(vector3, vector3 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Quaternion"), _("LookRotation"), 2, _(""), _("UnityEngine"))));
	set_rotation = reinterpret_cast<void(*)(transform*, vector4 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));
	set_position = reinterpret_cast<void(*)(transform*, vector3 value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));
	SetInt = reinterpret_cast<void(*)(uintptr_t material, rust::classes::string name, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 1, _(""), _("UnityEngine"))));
	set_hideFlags = reinterpret_cast<void(*)(uintptr_t material, int value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Object"), _("set_hideFlags"), 1, _(""), _("UnityEngine"))));
	Find = reinterpret_cast<uintptr_t(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));
	SetColor = reinterpret_cast<void(*)(uintptr_t, rust::classes::string name, col value)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _("name"), _("UnityEngine"), 1)));
	get_Renderers = reinterpret_cast<rust::list<uintptr_t> * (*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));
	get_material = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
	StringPool_Get = reinterpret_cast<unsigned int(*)(rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("StringPool"), _("Get"), 1, _("str"), _(""))));
	set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("set_timeScale"), 1, _(""), _("UnityEngine"))));
	get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));
	GetIndex = reinterpret_cast<int(*)(uintptr_t SkinSetCollection, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("SkinSetCollection"), _("GetIndex"), 1, _(""), _(""))));
	FloorToInt = reinterpret_cast<int (*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Mathf"), _("FloorToInt"), 1, _(""), _("UnityEngine"))));
	get_gravity = reinterpret_cast<vector3(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 1, _(""), _("UnityEngine"))));
	FindBone = reinterpret_cast<transform * (*)(base_player*, rust::classes::string)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("FindBone"), 1, _(""), _(""))));
	get_isAlive = reinterpret_cast<bool (*)(base_projectile*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));
	get_mousePosition = reinterpret_cast<vector3(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));

	containerWear = il2cpp::value(_("PlayerInventory"), _("containerWear"));
	canWieldItems = il2cpp::value(_("BaseMountable"), _("canWieldItems"));
	mounted = il2cpp::value(_("BasePlayer"), _("mounted"));
	containerBelt = il2cpp::value(_("PlayerInventory"), _("containerBelt"));
	itemList = il2cpp::value(_("ItemContainer"), _("itemList"));
	integrity = il2cpp::value(_("Projectile"), _("integrity"));
	weakspots = il2cpp::value(_("BaseHelicopter"), _("weakspots"));

	model = il2cpp::value(_("BaseEntity"), _("model"));
	gathering = il2cpp::value(_("BaseMelee"), _("gathering"));

	lastHitTime = il2cpp::value(_("Chainsaw"), _("lastHitTime"));
	lastHitMaterial = il2cpp::value(_("Chainsaw"), _("lastHitMaterial"));
	landTime = il2cpp::value(_("PlayerWalkMovement"), _("landTime"));
	jumpTime = il2cpp::value(_("PlayerWalkMovement"), _("jumpTime"));
	groundTime = il2cpp::value(_("PlayerWalkMovement"), _("groundTime"));
	gravityMultiplier = il2cpp::value(_("PlayerWalkMovement"), _("gravityMultiplier"));

	damageProperties = il2cpp::value(_("BaseMelee"), _("damageProperties"));
	movement = il2cpp::value(_("BasePlayer"), _("movement"));
	_displayName = il2cpp::value(_("BasePlayer"), _("_displayName"));
	player_inventory = il2cpp::value(_("BasePlayer"), _("inventory"));
	clActiveItem = il2cpp::value(_("BasePlayer"), _("clActiveItem"));
	playerModel = il2cpp::value(_("BasePlayer"), _("playerModel"));
	clientTeam = il2cpp::value(_("BasePlayer"), _("clientTeam"));
	playerFlags = il2cpp::value(_("BasePlayer"), _("playerFlags"));
	clientTickInterval = il2cpp::value(_("BasePlayer"), _("clientTickInterval"));
	eyes = il2cpp::value(_("BasePlayer"), _("eyes"));
	lastSentTickTime = il2cpp::value(_("BasePlayer"), _("lastSentTickTime"));
	modelState = il2cpp::value(_("BasePlayer"), _("modelState"));
	input = il2cpp::value(_("BasePlayer"), _("input"));
	userID = il2cpp::value(_("BasePlayer"), _("userID"));

	newVelocity = il2cpp::value(_("PlayerModel"), _("newVelocity"));
	isLocalPlayer = il2cpp::value(_("PlayerModel"), _("isLocalPlayer"));

	nextAttackTime = il2cpp::value(_("AttackEntity"), _("nextAttackTime"));
	timeSinceDeploy = il2cpp::value(_("AttackEntity"), _("timeSinceDeploy"));
	deployDelay = il2cpp::value(_("AttackEntity"), _("deployDelay"));
	repeatDelay = il2cpp::value(_("AttackEntity"), _("repeatDelay"));

	_health = il2cpp::value(_("BaseCombatEntity"), _("_health"));
	_maxHealth = il2cpp::value(_("BaseCombatEntity"), _("_maxHealth"));
	lifestate = il2cpp::value(_("BaseCombatEntity"), _("lifestate"));

	net = il2cpp::value(_("BaseNetworkable"), _("net"));

	heldEntity = il2cpp::value(_("Item"), _("heldEntity"));

	recoil = il2cpp::value(_("BaseProjectile"), _("recoil"));
	automatic = il2cpp::value(_("BaseProjectile"), _("automatic"));

	aimSway = il2cpp::value(_("BaseProjectile"), _("aimSway"));
	aimSwaySpeed = il2cpp::value(_("BaseProjectile"), _("aimSwaySpeed"));
	primaryMagazine = il2cpp::value(_("BaseProjectile"), _("primaryMagazine"));

	aimCone = il2cpp::value(_("BaseProjectile"), _("aimCone"));
	hipAimCone = il2cpp::value(_("BaseProjectile"), _("hipAimCone"));
	aimConePenaltyMax = il2cpp::value(_("BaseProjectile"), _("aimConePenaltyMax"));
	aimconePenaltyPerShot = il2cpp::value(_("BaseProjectile"), _("aimconePenaltyPerShot"));
	stancePenaltyScale = il2cpp::value(_("BaseProjectile"), _("stancePenaltyScale"));

	currentVelocity = il2cpp::value(_("Projectile"), _("currentVelocity"));
	currentPosition = il2cpp::value(_("Projectile"), _("currentPosition"));
	thickness_addr = il2cpp::value(_("Projectile"), _("thickness"));
	mod = il2cpp::value(_("Projectile"), _("mod"));
	hitTest = il2cpp::value(_("Projectile"), _("hitTest"));

	info = il2cpp::value(_("Item"), _("info"));

	category = il2cpp::value(_("ItemDefinition"), _("category"));
	itemid = il2cpp::value(_("ItemDefinition"), _("itemid"));
	displayName = il2cpp::value(_("ItemDefinition"), _("displayName"));

	viewOffset = il2cpp::value(_("PlayerEyes"), _("viewOffset"));

	swimming = il2cpp::value(_("PlayerWalkMovement"), _("swimming"));
	groundAngleNew = il2cpp::value(_("PlayerWalkMovement"), _("groundAngleNew"));
	flying = il2cpp::value(_("PlayerWalkMovement"), _("flying"));

	get_position = reinterpret_cast<vector3(*)(uintptr_t transform)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));

	get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));

	get_IsNpc = reinterpret_cast<bool(*)(uintptr_t player_model)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("get_IsNpc"), -1, _(""), _(""))));

	get_time = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));

	GetProjectileVelocityScale = reinterpret_cast<float(*)(base_projectile*, bool max)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _("getMax"), _(""), 1)));

	ClosestPoint = reinterpret_cast<vector3(*)(base_player*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 1, _("position"), _(""), 1)));

	StartAttackCooldown = reinterpret_cast<void(*)(base_projectile*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));

	get_transform = reinterpret_cast<transform * (*)(base_player* )>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));

	InverseTransformPoint = reinterpret_cast<vector3(*)(transform*, vector3)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));

	ProcessAttack = reinterpret_cast<void(*)(base_projectile*, HitTest*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
}

class transform {
public:
	vector3 get_object_position()
	{
		if (!(uintptr_t)this)
			return {};

		const auto visual_state = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x38);
		if (!visual_state)
			return {};

		return *reinterpret_cast<vector3*>(visual_state + 0x90);
	}

	vector3* get_position_ptr()
	{
		if (!(uintptr_t)this)
			return {};

		const auto visual_state = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x38);
		if (!visual_state)
			return {};

		return reinterpret_cast<vector3*>(visual_state + 0x90);
	}

	vector3 get_bone_position() {
		if (!(uintptr_t)this)
			return {};

		return get_position((uintptr_t)this);
	}
};

class mono_behaviour {
public:
	transform* get_transform()
	{
		// const auto unk = *reinterpret_cast< uintptr_t* >( this + 0x30 );

		return *reinterpret_cast<transform**>((uintptr_t)this + 0x8);
	}
};

class item_mod_projectile {
public:
	float get_projectile_velocity() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x34);
	}

	float& projectileSpread() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x30);
	}
	
	float& projectileVelocitySpread() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x38);
	}
};

class base_player;


struct Ray {
	vector3 origin;
	vector3 dir;
	Ray(vector3 o, vector3 d) {
		origin = o;
		dir = d;
	}
};

class HitTest {
public:
	uintptr_t game_object() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x70);
	}

	rust::classes::game_object* get_gameobject()
	{
		auto gameObject = game_object();
		if (!gameObject)
			return nullptr;

		return *reinterpret_cast<rust::classes::game_object**>(gameObject + 0x10);
	}

	void set_hit_transform(transform* hit_transform) {
		*reinterpret_cast<transform**>((uintptr_t)this + 0xB0) = hit_transform;
	}	
	
	void set_hit_type(rust::classes::HitTestType hit_type) {
		*reinterpret_cast<int*>((uintptr_t)this + 0x10) = (int)hit_type;
	}

	void set_ignore_entity(base_player* entity_to_ignore) {
		*reinterpret_cast<base_player**>((uintptr_t)this + 0x80) = entity_to_ignore;
	}

	void set_radius(float radius) {
		*reinterpret_cast<float*>((uintptr_t)this + 0x2C) = radius;
	}

	void set_did_hit(bool did_hit) {
		*reinterpret_cast<bool*>((uintptr_t)this + 0x66) = did_hit;
	}

	void set_attack_ray(Ray ray) {
		*reinterpret_cast<Ray*>((uintptr_t)this + 0x14) = ray;
	}

	void set_best_hit(bool best_hit) {
		*reinterpret_cast<bool*>((uintptr_t)this + 0x65) = best_hit;
	}

	void set_max_distance(float max_dist) {
		*reinterpret_cast<float*>((uintptr_t)this + 0x34) = max_dist;
	}

	void set_hit_entity(base_player* entity) {
		*reinterpret_cast<base_player**>((uintptr_t)this + 0x88) = entity;
	}

	base_player*& get_hit_entity() {
		return *reinterpret_cast<base_player**>((uintptr_t)this + 0x88);
	}

	void set_hit_point(vector3 hit_point) {
		*reinterpret_cast<vector3*>((uintptr_t)this + 0x90) = hit_point;
	}

	void set_hit_normal(vector3 hit_nromal) {
		*reinterpret_cast<vector3*>((uintptr_t)this + 0x9C) = hit_nromal;
	}
	void set_damage_properties(uintptr_t damage_properties) {
		*reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x68) = damage_properties;
	}
};

class GatherPropertyEntry {
public:
	float& gatherDamage() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x10);
	}
	
	float& destroyFraction() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x14);
	}
	
	float& conditionLost() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x18);
	}
};

class GatherProperties {
public:
	GatherPropertyEntry*& tree() {
		return *reinterpret_cast<GatherPropertyEntry**>((uintptr_t)this + 0x10);
	}

	GatherPropertyEntry*& ore() {
		return *reinterpret_cast<GatherPropertyEntry**>((uintptr_t)this + 0x18);
	}
};

class base_projectile {
public:
	float projectilevel_scale = projectileVelocityScale();
	bool first = false;
	float thickness = 0;

	GatherProperties*& Gathering() {
		return *reinterpret_cast<GatherProperties**>((uintptr_t)this + gathering);
	}

	void set_last_hit_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + lastHitTime) = time;
	}

	void set_last_hit_material(rust::classes::string material) {
		*reinterpret_cast<rust::classes::string*>((uintptr_t)this + lastHitMaterial) = material;
	}

	float get_next_attack_time() {
		return *reinterpret_cast<float*>((uintptr_t)this + nextAttackTime);
	}

	float get_time_since_deploy() {
		return *reinterpret_cast<float*>((uintptr_t)this + timeSinceDeploy);
	}

	float get_deploy_delay() {
		return *reinterpret_cast<float*>((uintptr_t)this + deployDelay);
	}

	float get_repeat_delay() {
		return *reinterpret_cast<float*>((uintptr_t)this + repeatDelay);
	}

	char* get_class_name() {
		auto bp = *reinterpret_cast<uintptr_t*>(this);
		return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
	}

	uintptr_t get_damage_properties() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + damageProperties);
	}

	HitTest* get_hit_test() {
		return *reinterpret_cast<HitTest**>((uintptr_t)this + hitTest);
	}

	void set_integrity(float to_set) {
		*reinterpret_cast<float*>((uintptr_t)this + integrity) = to_set;
	}

	item_mod_projectile* get_item_mod_projectile() {
		return *reinterpret_cast<item_mod_projectile**>((uintptr_t)this + mod);
	}

	weapon_stats_t get_stats(int32_t weapon_id) {
		const auto primary_magazine = *reinterpret_cast<uintptr_t*>((uintptr_t)this + primaryMagazine);
		if (primary_magazine == 1)
			return weapon_stats_t{ xf(1000) };

		float velocity = xf(1000);
		float gravity_modifier = xf(1);
		float drag = xf(.001f);
		float distance = xf(0);

		auto velocity_scale = xf(1);
		bool scale_velocity = false;

		const auto ammo_definition = *reinterpret_cast<uintptr_t*>(primary_magazine + 0x20);
		if (ammo_definition) {
			// itemid
			const auto ammo_id = *reinterpret_cast<int32_t*>(ammo_definition + 0x18);

			switch (ammo_id) {
			case shotgun:
				velocity = xf(225);
				drag = xf(1);
				distance = xf(3);
				break;
			case shotgun_slug:
				velocity = xf(225);
				drag = xf(1);
				distance = xf(10);
				break;
			case shotgun_fire:
				velocity = 100;
				drag = 1;
				distance = 3;
				break;
			case shotgun_handmade:
				velocity = 100;
				drag = 1;
				distance = 0;
				break;
			case rifle_556:
				velocity = 375;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_hv:
				velocity = 450;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_fire:
				velocity = 225;
				drag = .6;
				distance = 15;
				break;
			case rifle_556_explosive:
				velocity = 225;
				gravity_modifier = 1.25;
				drag = .6;
				distance = 15;
				break;
			case pistol:
				velocity = 300;
				drag = .7;
				distance = 15;
				break;
			case pistol_hv:
				velocity = 400;
				drag = .7;
				distance = 15;
				break;
			case pistol_fire:
				velocity = 225;
				drag = .7;
				distance = 15;
				break;
			case arrow_wooden:
				velocity = 50;
				gravity_modifier = .75;
				drag = .005;
				break;
			case arrow_hv:
				velocity = 80;
				gravity_modifier = .5;
				drag = .005;
				break;
			case arrow_fire:
				velocity = 40;
				gravity_modifier = 1;
				drag = .01;
				break;
			case arrow_bone:
				velocity = 45;
				gravity_modifier = .75;
				drag = .01;
				break;
			case nailgun_nails:
				velocity = 50;
				gravity_modifier = .75;
				drag = .005;
				break;
			}

			scale_velocity = true;
			velocity_scale =
				GetProjectileVelocityScale(this, false);
		}

		switch (weapon_id) {
		case spear_wooden:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case spear_stone:
			velocity = 30;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		}

		if (scale_velocity && (velocity_scale != 0))
			velocity *= velocity_scale;

		return { velocity, gravity_modifier, drag, distance };
	}

	vector3 get_current_position() {
		return *reinterpret_cast<vector3*>((uintptr_t)this + currentPosition);
	}

	void set_projectile_thickness(float thickness)
	{
		*reinterpret_cast<float*>((uintptr_t)this + thickness_addr) = thickness;
	}
	
	float get_projectile_thickness()
	{
		return *reinterpret_cast<float*>((uintptr_t)this + thickness_addr);
	}

	float& projectileVelocityScale()
	{
		return *reinterpret_cast<float*>((uintptr_t)this + projectileVelocityScale_addr);
	}

	void set_current_velocity(vector3 position)
	{
		*reinterpret_cast<vector3*>((uintptr_t)this + currentVelocity) = position;
	}

	uint32_t get_size() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

	void set_recoil(float yaw_min, float yaw_max, float pitch_min, float pitch_max) {
		auto recoil_properties = *reinterpret_cast<uintptr_t*>((uintptr_t)this + recoil);

		*reinterpret_cast<float*>(recoil_properties + 0x18) = yaw_min;
		*reinterpret_cast<float*>(recoil_properties + 0x1C) = yaw_max;
		*reinterpret_cast<float*>(recoil_properties + 0x20) = pitch_min;
		*reinterpret_cast<float*>(recoil_properties + 0x24) = pitch_max;
	}

	void set_no_sway() {
		*reinterpret_cast<float*>((uintptr_t)this + aimSway) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + aimSwaySpeed) = 0;
	}

	bool& is_automatic() {
		return *reinterpret_cast<bool*>((uintptr_t)this + automatic);
	}

	void set_no_spread() {
		*reinterpret_cast<float*>((uintptr_t)this + aimCone) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + hipAimCone) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + aimConePenaltyMax) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + aimconePenaltyPerShot) = 0;
		*reinterpret_cast<float*>((uintptr_t)this + stancePenaltyScale) = 0;
	}

	void set_success_fraction(float fraction) {
		*reinterpret_cast<float*>((uintptr_t)this + successFraction) = 0;
	}

	void set_did_spark_this_frame(bool state) {
		*reinterpret_cast<bool*>((uintptr_t)this + didSparkThisFrame) = state;
	}
};

class PlayerNameID {
public:
	wchar_t* get_username() {
		auto username = (str)(*reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x18));

		return username->str;
	}

	unsigned long get_user_id()
	{
		return *reinterpret_cast<unsigned long*>((uintptr_t)this + 0x20);
	}
};

class weapon {
public:
	uintptr_t get_icon_sprite() {
		const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<uintptr_t*>(item_definition + iconSprite);
	}
	
	uintptr_t get_steam_icon_sprite() {
		const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
		if (!item_definition)
			return 0;

		auto SteamInventoryItem = *reinterpret_cast<uintptr_t*>(item_definition + steamItem);
		if (!SteamInventoryItem)
			return 0;

		return *reinterpret_cast<uintptr_t*>(SteamInventoryItem + 0x20);
	}

	wchar_t* get_weapon_name() {
		auto item_def = *reinterpret_cast<uintptr_t*>((uintptr_t)this + info);
		if (!item_def)
			return {};

		auto display_name = *reinterpret_cast<uintptr_t*>(item_def + displayName);
		if (!display_name)
			return {};

		auto weapon_name = (str)(*reinterpret_cast<uintptr_t*>(display_name + 0x18));

		return weapon_name->str;
	}

	bool is_weapon() {
		const auto     item_definition = mem::read<uintptr_t>((uintptr_t)this + info);
		if (!item_definition)
			return false;

		return mem::read<uint32_t>(item_definition + category) == 0;
	}

	int32_t get_item_definition_id()
	{
		const auto     item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + info);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>(item_definition + itemid);
	}

	base_projectile* get_base_projetile() {
		return *reinterpret_cast<base_projectile**>((uintptr_t)this + heldEntity);
	}
};

class modelstate {
public:
	void set_water_level(float water_level) {
		*reinterpret_cast<float*>((uintptr_t)this + 0x14) = water_level;
	}

	void remove_flag(rust::classes::ModelState_Flag flag) {
		int flags = *reinterpret_cast<int*>((uintptr_t)this + 0x24);
		flags &= ~(int)flag;

		*reinterpret_cast<int*>((uintptr_t)this + 0x24) = flags;
	}
	
	void set_flag(rust::classes::ModelState_Flag flag) {
		int flags = *reinterpret_cast<int*>((uintptr_t)this + 0x24);

		*reinterpret_cast<int*>((uintptr_t)this + 0x24) = flags |= (int)flag;
	}

	bool has_flag(rust::classes::ModelState_Flag f)
	{
		int& flags = *reinterpret_cast<int*>((uintptr_t)this + 0x24);

		return (flags & (int)f) == (int)f;
	}
};

class playerwalkmovement {
public:
	void set_swimming(bool flag) {
		*reinterpret_cast<bool*>((uintptr_t)this + swimming) = flag;
	}

	bool get_admin_cheat() {
		return *reinterpret_cast<bool*>((uintptr_t)this + 0x18);
	}

	void set_admin_cheat(bool admin_cheat) {
		*reinterpret_cast<bool*>((uintptr_t)this + 0x18) = admin_cheat;
	}

	bool get_flying() {
		return *reinterpret_cast<bool*>((uintptr_t)this + flying);
	}

	void set_flying(bool fly) {
		*reinterpret_cast<bool*>((uintptr_t)this + flying) = fly;
	}

	void set_ground_angles_new(float angle) {
		*reinterpret_cast<float*>((uintptr_t)this + groundAngleNew) = angle;
	}

	void set_land_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + landTime) = time;
	}

	void set_jump_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + jumpTime) = time;
	}

	void set_ground_time(float time) {
		*reinterpret_cast<float*>((uintptr_t)this + groundTime) = time;
	}

	void set_gravity_multiplier(float multiplier) {
		*reinterpret_cast<float*>((uintptr_t)this + gravityMultiplier) = multiplier;
	}
};

auto cliententities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);

class networkable {
public:
	unsigned int get_id() {
		return *reinterpret_cast<unsigned int*>((uintptr_t)this + 0x10);
	}
};

class aim_target {
public:
	vector3 pos;

	base_player* player = NULL;

	float distance = 10000;
	float fov = 10000;

	int network_id;

	bool is_heli = false;
	bool visible = false;
	bool sleeping = false;
	bool teammate = false;
	bool found = false;

	/*Velocity related shit*/
	vector3 velocity;

	bool operator<(const aim_target& b) {
		if (fov == 10000) {
			return distance < b.distance;
		}
		else {
			return fov < b.fov;
		}
	}
};

float get_2d_dist(const vector2& Src, const vector3& Dst) {
	return vector3::my_sqrt( powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y));
}

class playereyes {
public:
	void set_view_offset(vector3 offset) {
		*reinterpret_cast<vector3*>((uintptr_t)this + viewOffset) = offset;
	}

	vector3 get_view_offset() {
		return *reinterpret_cast<vector3*>((uintptr_t)this + viewOffset);
	}
};

class input_state {
public:
	void set_aim_angles(vector3 aim_angle) {
		auto current = mem::read<uintptr_t>((uintptr_t)this + 0x10);

		*reinterpret_cast<vector3*>(current + 0x18) = aim_angle;
	}
};

class basemountable {
public:
	bool& canwielditem() {
		return *reinterpret_cast<bool*>((uintptr_t)this + canWieldItems);
	}
};

class base_player {
public:
	vector3 bodyAngles()
	{
		auto plr_input = *reinterpret_cast<uintptr_t*>(this + input);
		if (!plr_input)
			return {};

		constexpr auto bodyAngles = 0x3C;
		return *reinterpret_cast<vector3*>(plr_input + bodyAngles);

	}

	basemountable* get_mountable() {
		return mem::read<basemountable*>((uintptr_t)this + mounted);
	}

	wchar_t* get_player_name() {
		auto player_name = (str)(*reinterpret_cast<uintptr_t*>((uintptr_t)this + _displayName));
		return player_name->str;
	}

	aim_target get_aimbot_target(vector3 source, float max_distance = 500) {
		aim_target best_target = aim_target();

		if (!cliententities) {
			cliententities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
			if (!cliententities)
				return best_target;
		}

		rust::classes::list* entity_list = (rust::classes::list*)cliententities;

		auto list_value = entity_list->get_value<uintptr_t>();
		if (!list_value)
			return best_target;

		auto size = entity_list->get_size();
		if (!size)
			return best_target;

		auto buffer = entity_list->get_buffer<uintptr_t>();
		if (!buffer)
			return best_target;

		for (int i = 0; i <= size; i++) {
			auto current_object = *reinterpret_cast<uintptr_t*>(buffer + 0x20 + (i * 0x8));
			if (!current_object)
				continue;

			auto base_object = *reinterpret_cast<uintptr_t*>(current_object + 0x10);
			if (!base_object)
				continue;

			auto object = *reinterpret_cast<uintptr_t*>(base_object + 0x30);
			if (!object)
				continue;

			WORD tag = *reinterpret_cast<WORD*>(object + 0x54);

			auto ent = *reinterpret_cast<uintptr_t*>(base_object + 0x28);

			auto ent_class = *reinterpret_cast<uintptr_t*>(ent);
			auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);

			bool is_heli = false;

			if (*(int*)(entity_class_name + 4) == 'ileH')
				is_heli = true;

			if (tag == 6 && !settings::visuals::player_esp)
				continue;

			if (is_heli && !settings::visuals::heli_esp)
				continue;

			if (tag != 6 && !is_heli)// not a player
				continue;

			auto player = (base_player*)current_object;
			if (!player)
				continue;

			uintptr_t object_name_ptr = *reinterpret_cast<uintptr_t*>(object + 0x60);

			rust::classes::string object_name = *reinterpret_cast<rust::classes::string*>(object_name_ptr);

			if (m_strstr(object_name.zpad, _("LocalPlayer")))
				continue;

			aim_target target;
			target.player = player;

			if (!is_heli) {
				if (!player->is_alive())
					continue;

				if (player->is_sleeping()) {
					target.sleeping = true;
					continue;
				}

				if (player->is_teammate(this)) {
					target.teammate = true;
				}

				if (get_IsNpc( player->get_player_model())) {
					if (!settings::visuals::npc_esp)
						continue;
				}

				auto velocity = player->get_new_velocity();
				target.velocity = velocity;
			}
			else {
				auto velocity = GetWorldVelocity(player);
				target.velocity = velocity;
			}

			auto pos = is_heli ? player->get_bone_transform(19)->get_bone_position() : player->get_bone_transform((int)rust::classes::Bone_List::head)->get_bone_position();
			target.pos = pos;

			target.is_heli = is_heli;

			auto networkable = target.player->get_networkable();
			if (!networkable)
				continue;

			auto id = networkable->get_id();
			if (!id)
				continue;

			target.network_id = id;

			auto visible = player->is_visible(source, pos);
			target.visible = visible;
			//if (!visible)
			//	continue;

			auto distance = source.get_3d_dist(pos);
			target.distance = distance;
			if (distance > max_distance)
				continue;

			auto fov = unity::get_fov(pos);
			target.fov = fov;
			//if (fov >= 100)//>= max fov
			//	continue;

			if (target < best_target)
				best_target = target;
		}
		return best_target;
	}

	uintptr_t get_weakspots() {
		return *reinterpret_cast<uintptr_t*>(this + weakspots);
	}

	vector3 get_new_velocity() {
		auto player_model = *reinterpret_cast<uintptr_t*>((uintptr_t)this + playerModel);
		return *reinterpret_cast<vector3*>(player_model + newVelocity);
	}

	modelstate* get_model_state() {
		return *reinterpret_cast<modelstate**>((uintptr_t)this + modelState);
	}

	void set_client_tick_interval(float tick) {
		if (!this)
			return;

		*reinterpret_cast<float*>((uintptr_t)this + clientTickInterval) = tick;
	}

	void set_admin_flag(rust::classes::PlayerFlags flag) {
		int PlayerFlag = *reinterpret_cast<int*>((uintptr_t)this + playerFlags);

		*reinterpret_cast<int*>((uintptr_t)this + playerFlags) = PlayerFlag |= (int)flag;
	}

	unsigned long get_steam_id() {
		if (!this)
			return 0;

		if (!get_player_model())
			return 0;

		return *reinterpret_cast<unsigned long*>((uintptr_t)this + userID);
	}

	bool is_teammate(base_player* local_player) {
		auto team = mem::read<uintptr_t>((uintptr_t)local_player + clientTeam);

		auto member = mem::read<uintptr_t>(team + 0x30);

		auto size = mem::read<int>(member + 0x18);

		auto list = mem::read<uintptr_t>(member + 0x10);

		auto steam_id = get_steam_id();

		for (int i = 0; i < size; i++) {
			auto player = mem::read<uintptr_t>(list + 0x20 + i * 0x8);

			auto id = mem::read<unsigned long>(player + 0x20);

			if (id == steam_id)
				return true;
		}
		return false;
	}

	auto get_last_sent_ticket_time() {
		return *reinterpret_cast<float*>((uintptr_t)this + lastSentTickTime);
	}

	transform* get_bone_transform( int bone_id) {
		uintptr_t entity_model = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x118);
		uintptr_t bone_dict = *reinterpret_cast<uintptr_t*>(entity_model + 0x48);
		transform* BoneValue = *reinterpret_cast<transform**>(bone_dict + 0x20 + bone_id * 0x8);

		return BoneValue;
	}

	bool is_visible(vector3 source, vector3 destination) {
		auto visible = unity::is_visible(source, destination);
		if (visible)
			return true;

		return false;
	}

	rust::list<weapon*>* get_belt_items()
	{
		const auto     inventory = *reinterpret_cast<uintptr_t*>((uintptr_t)this + player_inventory);
		if (!inventory)
			return {};

		const auto container_belt = *reinterpret_cast<uintptr_t*>(inventory + containerBelt);
		if (!container_belt)
			return {};

		// get_once(uint32_t, itemList, 0, get_offset("ItemContainer", "itemList"));
		const auto list_wrapper = *reinterpret_cast<uintptr_t*>(container_belt + itemList);
		if (!list_wrapper)
			return {};

		const auto item_list =
			*reinterpret_cast<rust::list<weapon*>**>(list_wrapper + 0x10);
		if (!item_list)
			return {};

		return item_list;
	}
	
	rust::list<weapon*>* get_wearable_items()
	{
		const auto     inventory = *reinterpret_cast<uintptr_t*>((uintptr_t)this + player_inventory);
		if (!inventory)
			return {};

		const auto container_belt = *reinterpret_cast<uintptr_t*>(inventory + containerWear);
		if (!container_belt)
			return {};

		// get_once(uint32_t, itemList, 0, get_offset("ItemContainer", "itemList"));
		const auto list_wrapper = *reinterpret_cast<uintptr_t*>(container_belt + itemList);
		if (!list_wrapper)
			return {};

		const auto item_list =
			*reinterpret_cast<rust::list<weapon*>**>(list_wrapper + 0x10);
		if (!item_list)
			return {};

		return item_list;
	}

	std::pair<aim_target, bool> resolve_closest_entity(float max_distance, bool get_code = true) {
		aim_target closest_entity;
		auto client_entities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
		if (!client_entities)
			return { closest_entity, false };

		rust::classes::list* entity_list = (rust::classes::list*)client_entities;

		auto list_value = entity_list->get_value<uintptr_t>();
		if (!list_value)
			return { closest_entity, false };

		auto size = entity_list->get_size();
		if (!size)
			return { closest_entity, false };

		auto buffer = entity_list->get_buffer<uintptr_t>();
		if (!buffer)
			return { closest_entity, false };

		auto closest_entity_distance = 9999;
		bool is_code_lock = false;/*iscodelock/is_tree*/

		for (int i = 0; i <= size; i++) {
			auto current_object = *reinterpret_cast<uintptr_t*>(buffer + 0x20 + (i * 0x8));
			if (!current_object)
				continue;

			auto base_object = *reinterpret_cast<uintptr_t*>(current_object + 0x10);
			if (!base_object)
				continue;

			auto object = *reinterpret_cast<uintptr_t*>(base_object + 0x30);
			if (!object)
				continue;

			auto ent = *reinterpret_cast<uintptr_t*>(base_object + 0x28);
			auto ent_class = *reinterpret_cast<uintptr_t*>(ent);
			auto entity_class_name = (char*)*reinterpret_cast<uintptr_t*>(ent_class + 0x10);

			auto name = *(int*)(entity_class_name);

			if (get_code) {

				if (!(name == 'edoC') && !(name == 'LyeK'))
					continue;

				if (name == 'edoC')
					is_code_lock = true;

				auto flag = *reinterpret_cast<int*>(ent + 0x120);

				if (flag == 16)//Locked
					continue;
			}
			else{
				if (name != 'eerT' && name != 'HerO')
					continue;

				if (name == 'HerO')
					is_code_lock = false;
				else
					is_code_lock = true;

				if (name == 'eerT') {
					if (*(int*)(entity_class_name + 4) != 'itnE')
						continue;
				}
			}

			auto game_object = *reinterpret_cast<uintptr_t*>(object + 0x30);

			auto transform = *reinterpret_cast<uintptr_t*>(game_object + 0x8);

			auto visual_state = *reinterpret_cast<uintptr_t*>(transform + 0x38);

			auto world_position = *reinterpret_cast<vector3*>(visual_state + 0x90);

			auto bone_pos = this->get_bone_transform(48)->get_bone_position();

			auto distance = bone_pos.get_3d_dist(world_position);
			if (distance < closest_entity_distance && distance < max_distance) {
				auto object_class = *reinterpret_cast<uintptr_t*>(object + 0x30);
				if (!object_class)
					continue;

				auto entity = *reinterpret_cast<uintptr_t*>(object_class + 0x18);
				if (!entity)
					continue;

				auto baseentity = *reinterpret_cast<uintptr_t*>(entity + 0x28);
				if (!baseentity)
					continue;

				auto player = reinterpret_cast<base_player*>(baseentity);

				aim_target new_target;

				auto local = ClosestPoint(this, world_position);
				if (local.get_3d_dist(world_position) >= max_distance)
					continue;

				new_target.pos = world_position;
				new_target.player = (base_player*)ent;
				new_target.visible = /*unity::is_visible(bone_pos, world_position)*/true;
				new_target.found = true;

				closest_entity_distance = distance;
				closest_entity = new_target;
			}
		}

		return { closest_entity , is_code_lock};
	}

	bool is_sleeping()
	{
		auto Flags = *reinterpret_cast<int*>((uintptr_t)this + playerFlags);
		return Flags & 16;
	}

	playereyes* get_player_eyes() {
		return *reinterpret_cast<playereyes**>((uintptr_t)this + eyes);
	}

	weapon* get_active_weapon()
	{
		unsigned int ActUID = mem::read<unsigned int>((uintptr_t)this + clActiveItem);
		if (!ActUID)
			return 0;
		weapon* ActWeapon;

		uint64_t Inventory = mem::read<uint64_t>((uintptr_t)this + player_inventory);
		uint64_t Belt = mem::read<uint64_t>(Inventory + 0x28);
		uint64_t ItemList = mem::read<uint64_t>(Belt + 0x38);

		auto items = mem::read<uint64_t>(ItemList + 0x10);
		if (!items)
			return 0;

		for (int i = 0; i < 6; i++) //For each slot	
		{
			weapon* WeaponInfo = mem::read<weapon*>(items + 0x20 + (i * 0x8));;

			unsigned int WeaponUID = mem::read<unsigned int>((uintptr_t)WeaponInfo + 0x28);
			if (!WeaponUID)
				return 0;
			if (ActUID == WeaponUID)
			{
				ActWeapon = WeaponInfo;
				return ActWeapon;
			}
		}
		return 0;
	}

	uintptr_t get_player_model() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + playerModel);
	}

	uintptr_t get_model() {
		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + model);
	}

	networkable* get_networkable() {
		return *reinterpret_cast<networkable**>((uintptr_t)this + 0x50);
	}
	
	playerwalkmovement* get_movement() {
		return *reinterpret_cast<playerwalkmovement**>((uintptr_t)this + movement);
	}

	float get_health() {
		return *reinterpret_cast<float*>((uintptr_t)this + _health);
	}

	float get_max_health() {
		return *reinterpret_cast<float*>((uintptr_t)this + _maxHealth);
	}

	bool is_local_player(){
		if (!this)
			return false;

		auto player_model = get_player_model();
		if (!player_model)
			return false;

		auto is_local = *reinterpret_cast<bool*>(player_model + isLocalPlayer);

		return is_local;
	}

	bool is_alive() {
		if (!this)
			return 0;
		const auto life_state = *reinterpret_cast<uint32_t*>((uintptr_t)this + lifestate);

		return life_state == 0;
	}

	rust::classes::game_object* get_game_object()
	{
		if (!(uintptr_t)this)
			return nullptr;

		const auto unk0 = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
		if (!unk0)
			return nullptr;

		const auto unk1 = *reinterpret_cast<rust::classes::game_object**>(unk0 + 0x30);
		if (!unk1)
			return nullptr;

		return unk1;
	}
};

void attack_melee(aim_target target, base_projectile* baseprojectile, bool is_player = false) {
	if (!target.visible)
		return;

	if (target.teammate)
		return;

	vector3 local_position = unity::get_camera_pos();

	if (baseprojectile->get_next_attack_time() >= get_time())
		return;

	if (baseprojectile->get_time_since_deploy() < baseprojectile->get_deploy_delay())
		return;

	auto hit_test_class = il2cpp::init_class(_("HitTest"));
	if (!hit_test_class)
		return;

	HitTest* hit_test = (HitTest*)il2cpp::methods::object_new(hit_test_class);

	Ray ray = Ray(local_position, (target.pos - local_position).Normalized());

	transform* trans = is_player ? target.player->get_bone_transform(48) : get_transform(target.player);

	if (!trans)
		return;

	hit_test->set_max_distance(1000);
	hit_test->set_hit_transform(trans);
	hit_test->set_attack_ray(ray);
	hit_test->set_did_hit(true);
	hit_test->set_hit_entity(target.player);
	hit_test->set_hit_point(InverseTransformPoint(trans, target.pos));
	hit_test->set_hit_normal(vector3(0, 0, 0));
	hit_test->set_damage_properties(baseprojectile->get_damage_properties());

	StartAttackCooldown(baseprojectile, baseprojectile->get_repeat_delay());

	return ProcessAttack(baseprojectile, hit_test);
}

vector3 WorldToScreen(vector3 position)
{
	auto matrix = unity::get_view_matrix();

	if (!matrix.m) {
		return { 0,0,0 };
	}
	vector3 out;
	const auto temp = matrix.transpose();

	auto translation_vector = vector3{ temp[3][0], temp[3][1], temp[3][2] };
	auto up = vector3{ temp[1][0], temp[1][1], temp[1][2] };
	auto right = vector3{ temp[0][0], temp[0][1], temp[0][2] };

	float w = translation_vector.dot(position) + temp[3][3];

	if (w < 0.098f) {
		return vector3(0, 0, 0);
	}

	float x = up.dot(position) + temp._24;
	float y = right.dot(position) + temp._14;

	out.x = (static_cast<float>(unity::get_width()) / 2) * (1 + y / w);
	out.y = (static_cast<float>(unity::get_height()) / 2) * (1 - x / w);
	out.z = w;

	return out;
}