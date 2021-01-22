#pragma once
#include <cmath>
#include <cfloat>

class vector2
{
public:
	float x;
	float y;

	vector2()
	{}

	vector2(float x, float y)
		: x(x), y(y)
	{}
};
struct weapon_stats_t {
	float initial_velocity;
	float gravity_modifier;
	float drag;
	float initial_distance;
};

enum ammo_types : int32_t {
	shotgun = -1685290200,
	shotgun_slug = -727717969,
	shotgun_fire = -1036635990,
	shotgun_handmade = 588596902,

	rifle_556 = -1211166256,
	rifle_556_hv = 1712070256,
	rifle_556_fire = 605467368,
	rifle_556_explosive = -1321651331,

	pistol = 785728077,
	pistol_hv = -1691396643,
	pistol_fire = 51984655,

	arrow_wooden = -1234735557,
	arrow_hv = -1023065463,
	arrow_fire = 14241751,
	arrow_bone = 215754713,

	nailgun_nails = -2097376851
};

enum weapon_types : int32_t {
	spear_stone = 1602646136,
	spear_wooden = 1540934679
};

float my_pow(float base, float exp)
{
	auto nth_root = [](float A, int n) {
		constexpr int K = 8;
		float         x[K] = { 1 };
		for (int k = 0; k < K - 1; k++)
			x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / my_pow(x[k], n - 1));
		return x[K - 1];
	};
	if (base == 0)
		return 0;
	if (exp == 0)
		return 1;
	else if (exp < 0)
		return 1 / my_pow(base, -exp);
	else if (exp > 0 && exp < 1)
		return nth_root(base, 1 / exp);
	else if ((int)exp % 2 == 0) {
		float half_pow = my_pow(base, exp / 2);
		return half_pow * half_pow;
	}
	else
		return base * my_pow(base, exp - 1);
}

class vector3
{
public:
	float x;
	float y;
	float z;

	vector3()
	{}

	vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

#define M_PI_2 1.57079632679489661923
#define M_PI 3.14159265358979323846
#define RAD_TO_DEG 180 / 3.141592654f

	bool is_empty() { return x == 0 && y == 0 && z == 0; }

	static float my_sqrt(float number)
	{
		long        i;
		float       x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long*)&y; // floating point bit level hacking [sic]
		i = 0x5f3759df - (i >> 1); // Newton's approximation
		y = *(float*)&i;
		y = y * (threehalfs - (x2 * y * y)); // 1st iteration
		y = y * (threehalfs - (x2 * y * y)); // 2nd iteration

		return 1 / y;
	}

	inline float Length()
	{
		return my_sqrt((x * x) + (y * y) + (z * z));
	}

	static double my_atan(double x)
	{
		// Return arctangent(x) given that 5/3 < x <= 2, with the same properties as atan.
		auto atani5 = [](double x) {
			constexpr double p00 = +0x1.124A85750FB5Cp+00;
			constexpr double p01 = +0x1.D59AE78C11C49p-03;
			constexpr double p02 = -0x1.8AD3C44F10DC3p-04;
			constexpr double p03 = +0x1.2B090AAD5F9DCp-05;
			constexpr double p04 = -0x1.881EC3D15241Fp-07;
			constexpr double p05 = +0x1.8CB82A74E0699p-09;
			constexpr double p06 = -0x1.3182219E21362p-12;
			constexpr double p07 = -0x1.2B9AD13DB35A8p-12;
			constexpr double p08 = +0x1.10F884EAC0E0Ap-12;
			constexpr double p09 = -0x1.3045B70E93129p-13;
			constexpr double p10 = +0x1.00B6A460AC05Dp-14;

			double y = x - 0x1.d555555461337p0;

			return ((((((((((+p10) * y + p09) * y + p08) * y + p07) * y + p06) * y +
				p05) *
				y +
				p04) *
				y +
				p03) *
				y +
				p02) *
				y +
				p01) *
				y +
				p00;
		};
		// Return arctangent(x) given that 4/3 < x <= 5/3, with the same properties as
		// atan.
		auto atani4 = [](double x) {
			constexpr double p00 = +0x1730BD281F69Dp-01;
			constexpr double p01 = +0x1.3B13B13B13B0Cp-02;
			constexpr double p02 = -0x1.22D719C06115Ep-03;
			constexpr double p03 = +0x1.C963C83985742p-05;
			constexpr double p04 = -0x1.135A0938EC462p-06;
			constexpr double p05 = +0x1.13A254D6E5B7Cp-09;
			constexpr double p06 = +0x1.DFAA5E77B7375p-10;
			constexpr double p07 = -0x14AC1342182D2p-10;
			constexpr double p08 = +0x1.25BAD4D85CBE1p-10;
			constexpr double p09 = -0x1.E4EEF429EB680p-12;
			constexpr double p10 = +0x1.B4E30D1BA3819p-14;
			constexpr double p11 = +0x1.0280537F097F3p-15;

			double y = x - 0x1.8000000000003p0;

			return (((((((((((+p11) * y + p10) * y + p09) * y + p08) * y + p07) * y +
				p06) *
				y +
				p05) *
				y +
				p04) *
				y +
				p03) *
				y +
				p02) *
				y +
				p01) *
				y +
				p00;
		};
		// Return arctangent(x) given that 1 < x <= 4 / 3, with the same properties as
		// atan.
		auto atani3 = [](double x) {
			constexpr double p00 = +0x1.B96E5A78C5C40p-01;
			constexpr double p01 = +0x1.B1B1B1B1B1B3Dp-02;
			constexpr double p02 = -0x1.AC97826D58470p-03;
			constexpr double p03 = +0x1.3FD2B9F586A67p-04;
			constexpr double p04 = -0x1.BC317394714B7p-07;
			constexpr double p05 = -0x1.2B01FC60CC37Ap-07;
			constexpr double p06 = +0x1.73A9328786665p-07;
			constexpr double p07 = -0x1.C0B993A09CE31p-08;
			constexpr double p08 = +0x1.2FCDACDD6E5B5p-09;
			constexpr double p09 = +0x1.CBD49DA316282p-13;
			constexpr double p10 = -0x1.0120E602F6336p-10;
			constexpr double p11 = +0x1.A89224FF69018p-11;
			constexpr double p12 = -0x1.883D8959134B3p-12;

			double y = x - 0x1.2aaaaaaaaaa96p0;

			return ((((((((((((+p12) * y + p11) * y + p10) * y + p09) * y + p08) * y +
				p07) *
				y +
				p06) *
				y +
				p05) *
				y +
				p04) *
				y +
				p03) *
				y +
				p02) *
				y +
				p01) *
				y +
				p00;
		};
		// Return arctangent(x) given that 3 / 4 < x <= 1, with the same properties as
		// atan.
		auto atani2 = [](double x) {
			constexpr double p00 = +0x1.700A7C580EA7Ep-01;
			constexpr double p01 = +0x1.21FB781196AC3p-01;
			constexpr double p02 = -0x1.1F6A8499714A2p-02;
			constexpr double p03 = +0x1.41B15E5E8DCD0p-04;
			constexpr double p04 = +0x1.59BC93F81895Ap-06;
			constexpr double p05 = -0x1.63B543EFFA4EFp-05;
			constexpr double p06 = +0x1.C90E92AC8D86Cp-06;
			constexpr double p07 = -0x1.91F7E2A7A338Fp-08;
			constexpr double p08 = -0x1.AC1645739E676p-08;
			constexpr double p09 = +0x1.152311B180E6Cp-07;
			constexpr double p10 = -0x1.265EF51B17DB7p-08;
			constexpr double p11 = +0x1.CA7CDE5DE9BD7p-14;

			double y = x - 0x1.c0000000f4213p-1;

			return (((((((((((+p11) * y + p10) * y + p09) * y + p08) * y + p07) * y +
				p06) *
				y +
				p05) *
				y +
				p04) *
				y +
				p03) *
				y +
				p02) *
				y +
				p01) *
				y +
				p00;
		};
		// Return arctangent(x) given that 1/2 < x <= 3/4, with the same properties as
		// atan.
		auto atani1 = [](double x) {
			constexpr double p00 = +0x1.1E00BABDEFED0p-1;
			constexpr double p01 = +0x1.702E05C0B8155p-1;
			constexpr double p02 = -0x1.4AF2B78215A1Bp-2;
			constexpr double p03 = +0x1.5D0B7E9E69054p-6;
			constexpr double p04 = +0x1.A1247CA5D9475p-4;
			constexpr double p05 = -0x1.519E110F61B54p-4;
			constexpr double p06 = +0x1.A759263F377F2p-7;
			constexpr double p07 = +0x1.094966BE2B531p-5;
			constexpr double p08 = -0x1.09BC0AB7F914Cp-5;
			constexpr double p09 = +0x1F3B7C531AA4Ap-8;
			constexpr double p10 = +0x1.950E69DCDD967p-7;
			constexpr double p11 = -0x1.D88D31ABC3AE5p-7;
			constexpr double p12 = +0x1.10F3E20F6A2E2p-8;

			double y = x - 0x1.4000000000027p-1;

			return ((((((((((((+p12) * y + p11) * y + p10) * y + p09) * y + p08) * y +
				p07) *
				y +
				p06) *
				y +
				p05) *
				y +
				p04) *
				y +
				p03) *
				y +
				p02) *
				y +
				p01) *
				y +
				p00;
		};
		// Return arctangent(x) given that 0x1p-27 < |x| <= 1/2, with the same properties
		// as atan.
		auto atani0 = [](double x) {
			constexpr double p03 = -0x1.555555555551Bp-2;
			constexpr double p05 = +0x1.99999999918D8p-3;
			constexpr double p07 = -0x1.2492492179CA3p-3;
			constexpr double p09 = +0x1.C71C7096C2725p-4;
			constexpr double p11 = -0x1.745CF51795B21p-4;
			constexpr double p13 = +0x1.3B113F18AC049p-4;
			constexpr double p15 = -0x1.10F31279EC05Dp-4;
			constexpr double p17 = +0x1.DFE7B9674AE37p-5;
			constexpr double p19 = -0x1.A38CF590469ECp-5;
			constexpr double p21 = +0x1.56CDB5D887934p-5;
			constexpr double p23 = -0x1.C0EB85F543412p-6;
			constexpr double p25 = +0x1.4A9F5C4724056p-7;

			// Square x.
			double x2 = x * x;

			return ((((((((((((+p25) * x2 + p23) * x2 + p21) * x2 + p19) * x2 + p17) *
				x2 +
				p15) *
				x2 +
				p13) *
				x2 +
				p11) *
				x2 +
				p09) *
				x2 +
				p07) *
				x2 +
				p05) *
				x2 +
				p03) *
				x2 * x +
				x;
		};
		// Return arctangent(x) given that 2 < x, with the same properties as atan.
		auto Tail = [](double x) {
			{
				constexpr double HalfPi = 0x3.243f6a8885a308d313198a2e037ap-1;

				// For large x, generate inexact and return pi/2.
				if (0x1p53 <= x)
					return HalfPi + DBL_EPSILON;
				if (x != x) // isnan
					return x - x;
			}

			constexpr double p03 = -0x1.5555555554A51p-2;
			constexpr double p05 = +0x1.999999989EBCAp-3;
			constexpr double p07 = -0x1.249248E1422E3p-3;
			constexpr double p09 = +0x1.C71C5EDFED480p-4;
			constexpr double p11 = -0x1.745B7F2D72663p-4;
			constexpr double p13 = +0x1.3AFD7A0E6EB75p-4;
			constexpr double p15 = -0x1.104146B1A1AE8p-4;
			constexpr double p17 = +0x1.D78252FA69C1Cp-5;
			constexpr double p19 = -0x1.81D33E401836Dp-5;
			constexpr double p21 = +0x1.007733E06CEB3p-5;
			constexpr double p23 = -0x1.83DAFDA7BD3FDp-7;

			constexpr double p000 = +0x1.921FB54442D18p0;
			constexpr double p001 = +0x1.1A62633145C07p-54;

			double y = 1 / x;

			// Square y.
			double y2 = y * y;

			return p001 -
				((((((((((((+p23) * y2 + p21) * y2 + p19) * y2 + p17) * y2 + p15) *
					y2 +
					p13) *
					y2 +
					p11) *
					y2 +
					p09) *
					y2 +
					p07) *
					y2 +
					p05) *
					y2 +
					p03) *
					y2 * y +
					y) +
				p000;
		};

		if (x < 0)
			if (x < -1)
				if (x < -5 / 3.)
					if (x < -2)
						return -Tail(-x);
					else
						return -atani5(-x);
				else if (x < -4 / 3.)
					return -atani4(-x);
				else
					return -atani3(-x);
			else if (x < -.5)
				if (x < -.75)
					return -atani2(-x);
				else
					return -atani1(-x);
			else if (x < -0x1.d12ed0af1a27fp-27)
				return atani0(x);
			else if (x <= -0x1p-1022)
				// Generate inexact and return x.
				return (DBL_EPSILON + 1) * x;
			else if (x == 0)
				return x;
			else
				// Generate underflow and return x.
				return x * DBL_EPSILON + x;
		else if (x <= +1)
			if (x <= +.5)
				if (x <= +0x1.d12ed0af1a27fp-27)
					if (x < +0x1p-1022)
						if (x == 0)
							return x;
						else
							// Generate underflow and return x.
							return x * DBL_EPSILON + x;
					else
						// Generate inexact and return x.
						return (DBL_EPSILON + 1) * x;
				else
					return atani0(x);
			else if (x <= +.75)
				return +atani1(+x);
			else
				return +atani2(+x);
		else if (x <= +5 / 3.)
			if (x <= +4 / 3.)
				return +atani3(+x);
			else
				return +atani4(+x);
		else if (x <= +2)
			return +atani5(+x);
		else
			return +Tail(+x);
	}

	static float my_sin(float x)
	{
		// useful to pre-calculate
		double x2 = x * x;
		double x4 = x2 * x2;

		// Calculate the terms
		// As long as abs(x) < sqrt(6), which is 2.45, all terms will be positive.
		// Values outside this range should be reduced to [-pi/2, pi/2] anyway for
		// accuracy. Some care has to be given to the factorials. They can be
		// pre-calculated by the compiler, but the value for the higher ones will exceed
		// the storage capacity of int. so force the compiler to use unsigned long longs
		// (if available) or doubles.
		double t1 = x * (1.0 - x2 / (2 * 3));
		double x5 = x * x4;
		double t2 = x5 * (1.0 - x2 / (6 * 7)) / (1.0 * 2 * 3 * 4 * 5);
		double x9 = x5 * x4;
		double t3 = x9 * (1.0 - x2 / (10 * 11)) / (1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9);
		double x13 = x9 * x4;
		double t4 = x13 * (1.0 - x2 / (14 * 15)) /
			(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13);
		double x14 = x13 * x4;
		double t5 =
			x14 * (1.0 - x2 / (18 * 19)) /
			(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 * 16 * 17);
		double x15 = x14 * x4;
		double t6 = x15 * (1.0 - x2 / (22 * 23)) /
			(1.0 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 *
				16 * 17 * 18 * 19 * 20 * 21);
		// add some more if your accuracy requires them.
		// But remember that x is smaller than 2, and the factorial grows very fast
		// so I doubt that 2^17 / 17! will add anything.
		// Even t4 might already be too small to matter when compared with t1.

		// Sum backwards
		double result = t6;
		result += t5;
		result += t4;
		result += t3;
		result += t2;
		result += t1;

		return result;
	}

	float length_2d() { return my_sqrt((x * x) + (z * z)); }

	static float my_cos(float x) { return my_sin(x + M_PI_2); }

	static float my_asin(float x) { return my_atan2(x, my_sqrt(1.0 - (x * x))); }

	inline float calc_pitch(vector3 from, vector3 to, weapon_stats_t stats)
	{
		float dist = (to - from).length_2d();

		float dt = (dist / stats.initial_velocity);

		// float new_vel = stats.initial_velocity - ( stats.drag * stats.initial_velocity
		// * stats.initial_velocity * dt );
		float new_vel = 2 / ((stats.drag * dt) + 2) * stats.initial_velocity;

		const float y = to.y - from.y;
		const float v = new_vel;
		const float g = 9.81f * stats.gravity_modifier;
		const float r_to_deg = (180 / 3.14159265358979323f);

		if (dist == 0)
			return 0;

		const float pitch = my_atan2(
			(((v * v)) - my_sqrt((v * v * v * v) - (g * ((g * (dist * dist)) +
				(2 * y * (v * v)))))),
			(g * dist));

		return pitch * r_to_deg;
	}

	vector3 lerp(vector3 v, float x, bool clamp = true)
	{
		auto delta = (v - *this);
		if (clamp)
			delta.clamp();

		auto result = (*this + delta * x);
		if (clamp)
			result.clamp();

		return result;
	}

	vector3 forward()
	{
		float sp, sy, cp, cy;

		constexpr auto PI = 3.14159265358979323846;
		sy = my_sin(y / 180 * (float)PI);
		cy = my_cos(y / 180 * (float)PI);

		sp = my_sin(x / 180 * (float)PI);
		cp = my_cos(x / 180 * (float)PI);

		return { cp * cy, -sp, cp * sy };
	}

	template<typename T>
	T get_remainder(T val, T min, T max)
	{
		while (val > max)
			val -= max * 2;
		while (val < min)
			val += max * 2;
		return val;
	}

	vector3 clamp()
	{
		constexpr auto yaw_limit = static_cast<float>(180);
		constexpr auto pitch_limit = static_cast<float>(90);

		y = get_remainder(y, -yaw_limit, yaw_limit);
		x = get_remainder(x, -pitch_limit, pitch_limit);

		/*if ( x > 180 )
			x -= 360;
		else if ( x < -180 )
			x += 360;

		if ( y > 180 )
			y -= 360;
		else if ( y < -180 )
			y += 360;

		if ( x < -89 )
			x = -89;

		if ( x > 89 )
			x = 89;

		while ( y < -180 )
			y += 360;

		while ( y > 180 )
			y -= 360;

		z = 0;*/

		if (x != x)
			x = 0;
		if (y != y)
			y = 0;
		if (z != z)
			z = 0;

		return *this;
	}


	static float my_atan2(float y, float x)
	{
		// https://en.wikipedia.org/wiki/Atan2#Definition (A compact expression with four
		// overlapping half-planes is: ...)
		if (x == 0) {
			if (y > 0.0f)
				return M_PI_2;
			else if (y < 0.0f)
				return -M_PI_2;
			return 0;
		}
		else if (x > 0)
			return my_atan(y / x);
		else if (x < 0)
			return M_PI + my_atan(y / x);
		else if (y > 0)
			return M_PI_2 - my_atan(y / x);
		else if (y < 0)
			return -M_PI_2 - my_atan(y / x);
		return 0;
	}

	vector3 rotation()
	{
		float pitch = -my_atan2(y, my_sqrt(x * x + z * z));
		float yaw = -my_atan2(-x, z);

		yaw *= RAD_TO_DEG;
		pitch *= RAD_TO_DEG;

		return { pitch, yaw, 0 };
	}

	inline float Distance(const vector3& vector)
	{
		return my_sqrt(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}

	float dot(const vector3& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z;
	}

	float length()
	{
		return my_sqrt(dot(*this));
	}

	#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)

	float get_3d_dist(const vector3& Dst) {
		return my_sqrt( powFFFFFFFFFFFFFFFFFFFFFF(x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(y - Dst.y) + powFFFFFFFFFFFFFFFFFFFFFF(z - Dst.z));
	}

	float distance(const vector3& vector)
	{
		return my_sqrt(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z));
	}

	vector3 Normalized() {
		float len = Length();
		return vector3(x / len, y / len, z / len);
	}

	vector3 normalize()
	{
		vector3 out = *this;
		auto l = length();
		if (l == 0)
			return *this;
		;
		out.x /= l;
		out.y /= l;
		out.z /= l;
		return out;
	}

	float world_distance(const vector3& vector)
	{
		return float(sqrtf(powf(vector.x - x, 2.0) + powf(vector.y - y, 2.0) + powf(vector.z - z, 2.0)));
	}

	void rotate(float deg)
	{
		float theta = deg / 180.0f * 3.14159265358979323846f;
		float c = cos(theta);
		float s = sin(theta);
		float tx = x * c - y * s;
		float ty = x * s + y * c;
		x = tx;
		y = ty;
	}

	vector3& operator+=(const vector3& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return *this;
	}

	vector3& operator-=(const vector3& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

		return *this;
	}

	vector3& operator*=(float number)
	{
		x *= number;
		y *= number;
		z *= number;

		return *this;
	}

	vector3& operator/=(float number)
	{
		x /= number;
		y /= number;
		z /= number;

		return *this;
	}

	bool operator==(const vector3& vector) const
	{
		return x == vector.x && y == vector.y && z == vector.z;
	}

	bool operator!=(const vector3& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z;
	}

	vector3 operator+(const vector3& vector) const
	{
		return vector3(x + vector.x, y + vector.y, z + vector.z);
	}

	vector3 operator-(const vector3& vector) const
	{
		return vector3(x - vector.x, y - vector.y, z - vector.z);
	}

	vector3 operator-() const
	{
		return vector3(-x, -y, -z);
	}

	vector3 operator*(float number) const
	{
		return vector3(x * number, y * number, z * number);
	}

	vector3 operator/(float number) const
	{
		return vector3(x / number, y / number, z / number);
	}

	void angle_vectors(vector3* forward, vector3* right, vector3* up)
	{
		float sp, sy, cp, cy, sr, cr;

		constexpr auto PI = 3.14159265358979323846;
		sy = my_sin(y / 180.f * (float)PI);
		cy = my_cos(y / 180.f * (float)PI);

		sp = my_sin(x / 180.f * (float)PI);
		cp = my_cos(x / 180.f * (float)PI);

		sr = 0.f;
		cr = 1.f;

		if (forward) {
			*forward = { cp * cy, -sp, cp * sy };
		}

		if (right) {
			right->x = cp * sy;
			right->y = (cr * sp * sy + -sr * cy);
			right->z = (sr * sp * sy + cr * cy);
		}

		if (up) {
			up->x = (cr * sp * cy + -sr * -sy);
			up->y = cr * cp;
			up->z = (cr * sp * sy + -sr * cy);
		}
	}
};

class VMatrix
{
public:
	VMatrix()
		: m{ { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 },
			 { 0, 0, 0, 0 } }
	{}

	VMatrix(const VMatrix&) = default;

	VMatrix transpose() {
		VMatrix m;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				m.m[i][j] = this->m[j][i];

		return m;
	}

	void matrix_identity() {
		memset(this, 0, sizeof(VMatrix));
		m[0][0] = 1.0f;
		m[1][1] = 1.0f;
		m[2][2] = 1.0f;
		m[3][3] = 1.0f;
	}

	bool is_empty() {
		if (!m[3][0] && !m[3][1] && !m[3][2] && !m[2][1] && !m[2][0] && !m[2][2])
			return true;

		return false;
	}

	vector3 operator*(const vector3& vec) {
		VMatrix m;

		m[3][0] = vec.x;
		m[3][1] = vec.y;
		m[3][2] = vec.z;

		m[0][0] = 1;
		m[1][1] = 1;
		m[2][2] = 1;


		m[0][3] = 0.0f;
		m[1][3] = 0.0f;
		m[2][3] = 0.0f;
		m[3][3] = 1.0f;

		auto result = m * (*this);

		return vector3{ result[3][0], result[3][1], result[3][2] };
	}

	VMatrix operator*(const VMatrix& _m2) {
		auto _m = *this;

		VMatrix out;
		out[0][0] = _m[0][0] * _m2[0][0] + _m[0][1] * _m2[1][0] + _m[0][2] * _m2[2][0] + _m[0][3] * _m2[3][0];
		out[0][1] = _m[0][0] * _m2[0][1] + _m[0][1] * _m2[1][1] + _m[0][2] * _m2[2][1] + _m[0][3] * _m2[3][1];
		out[0][2] = _m[0][0] * _m2[0][2] + _m[0][1] * _m2[1][2] + _m[0][2] * _m2[2][2] + _m[0][3] * _m2[3][2];
		out[0][3] = _m[0][0] * _m2[0][3] + _m[0][1] * _m2[1][3] + _m[0][2] * _m2[2][3] + _m[0][3] * _m2[3][3];
		out[1][0] = _m[1][0] * _m2[0][0] + _m[1][1] * _m2[1][0] + _m[1][2] * _m2[2][0] + _m[1][3] * _m2[3][0];
		out[1][1] = _m[1][0] * _m2[0][1] + _m[1][1] * _m2[1][1] + _m[1][2] * _m2[2][1] + _m[1][3] * _m2[3][1];
		out[1][2] = _m[1][0] * _m2[0][2] + _m[1][1] * _m2[1][2] + _m[1][2] * _m2[2][2] + _m[1][3] * _m2[3][2];
		out[1][3] = _m[1][0] * _m2[0][3] + _m[1][1] * _m2[1][3] + _m[1][2] * _m2[2][3] + _m[1][3] * _m2[3][3];
		out[2][0] = _m[2][0] * _m2[0][0] + _m[2][1] * _m2[1][0] + _m[2][2] * _m2[2][0] + _m[2][3] * _m2[3][0];
		out[2][1] = _m[2][0] * _m2[0][1] + _m[2][1] * _m2[1][1] + _m[2][2] * _m2[2][1] + _m[2][3] * _m2[3][1];
		out[2][2] = _m[2][0] * _m2[0][2] + _m[2][1] * _m2[1][2] + _m[2][2] * _m2[2][2] + _m[2][3] * _m2[3][2];
		out[2][3] = _m[2][0] * _m2[0][3] + _m[2][1] * _m2[1][3] + _m[2][2] * _m2[2][3] + _m[2][3] * _m2[3][3];
		out[3][0] = _m[3][0] * _m2[0][0] + _m[3][1] * _m2[1][0] + _m[3][2] * _m2[2][0] + _m[3][3] * _m2[3][0];
		out[3][1] = _m[3][0] * _m2[0][1] + _m[3][1] * _m2[1][1] + _m[3][2] * _m2[2][1] + _m[3][3] * _m2[3][1];
		out[3][2] = _m[3][0] * _m2[0][2] + _m[3][1] * _m2[1][2] + _m[3][2] * _m2[2][2] + _m[3][3] * _m2[3][2];
		out[3][3] = _m[3][0] * _m2[0][3] + _m[3][1] * _m2[1][3] + _m[3][2] * _m2[2][3] + _m[3][3] * _m2[3][3];

		return out;
	}

	float* operator[](size_t i) { return m[i]; }
	const float* operator[](size_t i) const { return m[i]; }

	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};

class vector4
{
public:
	float x;
	float y;
	float z;
	float w;

	vector4()
	{}

	vector4(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	vector3 forward()
	{
		vector3  point = { 0, 0, 1 };
		float num = x * 2;
		float num2 = y * 2;
		float num3 = z * 2;
		float num4 = x * num;
		float num5 = y * num2;
		float num6 = z * num3;
		float num7 = x * num2;
		float num8 = x * num3;
		float num9 = y * num3;
		float num10 = w * num;
		float num11 = w * num2;
		float num12 = w * num3;
		vector3  result;
		result.x = (1 - (num5 + num6)) * point.x + (num7 - num12) * point.y +
			(num8 + num11) * point.z;
		result.y = (num7 + num12) * point.x + (1 - (num4 + num6)) * point.y +
			(num9 - num10) * point.z;
		result.z = (num8 - num11) * point.x + (num9 + num10) * point.y +
			(1 - (num4 + num5)) * point.z;
		return result;
	}


	inline float dot(const vector4& vector)
	{
		return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
	}

	inline float distance(const vector4& vector)
	{
		return sqrtf(
			(x - vector.x) * (x - vector.x) +
			(y - vector.y) * (y - vector.y) +
			(z - vector.z) * (z - vector.z) +
			(w - vector.w) * (w - vector.w));
	}

	bool operator==(const vector4& vector) const
	{
		return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
	}

	bool operator!=(const vector4& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
	}

	vector4 operator+(const vector4& vector) const
	{
		return vector4(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
	}

	vector4 operator-(const vector4& vector) const
	{
		return vector4(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
	}

	vector4 operator-() const
	{
		return vector4(-x, -y, -z, -w);
	}

	vector4 operator*(float number) const
	{
		return vector4(x * number, y * number, z * number, w * number);
	}

	vector4 operator/(float number) const
	{
		return vector4(x / number, y / number, z / number, w / number);
	}

	vector4& operator+=(const vector4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	vector4& operator-=(const vector4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	vector4& operator*=(float number)
	{
		x *= number;
		y *= number;
		z *= number;
		w *= number;
		return *this;
	}

	vector4& operator/=(float number)
	{
		x /= number;
		y /= number;
		z /= number;
		w /= number;
		return *this;
	}
};

struct matrix
{
	vector4 vec0;
	vector4 vec1;
	vector4 vec2;
	vector4 vec3;
};
