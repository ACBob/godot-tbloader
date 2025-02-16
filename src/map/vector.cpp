#include "vector.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "libmap_math.h"
#include "matrix.h"

bool vec3_equals(const vec3 &lhs, const vec3 &rhs) {
	return vec3_length(vec3_sub(lhs, rhs)) < CMP_EPSILON;
}

vec3 vec3_add(const vec3 &lhs, const vec3 &rhs) {
	return {
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	};
}

vec3 vec3_sub(const vec3 &lhs, const vec3 &rhs) {
	return {
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	};
}

vec3 vec3_mul(const vec3 &lhs, const vec3 &rhs) {
	return {
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	};
}

vec3 vec3_div(const vec3 &lhs, const vec3 &rhs) {
	return {
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z
	};
}

double vec3_sqlen(const vec3 &v) {
	return vec3_dot(v, v);
}

double vec3_length(const vec3 &v) {
	double sqlen = vec3_sqlen(v);
	return (double)sqrt(vec3_sqlen(v));
}

vec3 vec3_normalize(const vec3 &v) {
	double len = vec3_length(v);
	return vec3_div_double(v, len);
}

double vec3_dot(const vec3 &lhs, const vec3 &rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

vec3 vec3_cross(const vec3 &lhs, const vec3 &rhs) {
	return {
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x,
	};
}

vec3 vec3_rotate(const vec3 &v, const vec3 &axis, double angle) {
	mat4 mat = rotation_matrix(axis, angle);
	return mat4_mul_vec3(mat, v);
}

vec3 vec3_add_double(const vec3 &lhs, const double rhs) {
	vec3 result = { lhs.x + rhs, lhs.y + rhs, lhs.z + rhs };
	return result;
};

vec3 vec3_sub_double(const vec3 &lhs, const double rhs) {
	vec3 result = { lhs.x - rhs, lhs.y - rhs, lhs.z - rhs };
	return result;
};

vec3 vec3_mul_double(const vec3 &lhs, const double rhs) {
	vec3 result = { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
	return result;
};

vec3 vec3_div_double(const vec3 &lhs, const double rhs) {
	vec3 result = { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
	return result;
};

// BAOB: TODO: Locale?

vec3 vec3_parse(const char *str, vec3 defaults) {
	vec3 ret = defaults;
	sscanf(str, "%lf %lf %lf", &ret.x, &ret.y, &ret.z);
	return ret;
}

vec2 vec2_parse(const char *str, vec2 defaults) {
	vec2 ret = defaults;
	sscanf(str, "%lf %lf", &ret.x, &ret.y);
	return ret;
}

vec4 vec4_parse(const char *str, vec4 defaults) {
	vec4 ret = defaults;
	sscanf(str, "%lf %lf %lf %lf", &ret.x, &ret.y, &ret.z, &ret.w);
	return ret;
}
