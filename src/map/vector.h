#ifndef LIBMAP_VECTOR_H
#define LIBMAP_VECTOR_H
// TODO: Can we use Godot's vector types here?

struct vec3 {
	double x;
	double y;
	double z;
};

bool vec3_equals(const vec3 &lhs, const vec3 &rhs);
vec3 vec3_add(const vec3 &lhs, const vec3 &rhs);
vec3 vec3_sub(const vec3 &lhs, const vec3 &rhs);
vec3 vec3_mul(const vec3 &lhs, const vec3 &rhs);
vec3 vec3_div(const vec3 &lhs, const vec3 &rhs);

vec3 vec3_add_double(const vec3 &lhs, double rhs);
vec3 vec3_sub_double(const vec3 &lhs, double rhs);
vec3 vec3_mul_double(const vec3 &lhs, double rhs);
vec3 vec3_div_double(const vec3 &lhs, double rhs);

double vec3_dot(const vec3 &lhs, const vec3 &rhs);
vec3 vec3_cross(const vec3 &lhs, const vec3 &rhs);
double vec3_sqlen(const vec3 &v);
double vec3_length(const vec3 &v);
vec3 vec3_normalize(const vec3 &v);
vec3 vec3_rotate(const vec3 &v, const vec3 &axis, double angle);

vec3 vec3_parse(const char *str, vec3 defaults = { 0 });

struct vec2 {
	double x;
	double y;
};

vec2 vec2_parse(const char *str, vec2 defaults = { 0 });

struct vec4 {
	double x;
	double y;
	double z;
	double w;
};
vec4 vec4_parse(const char *str, vec4 defaults = { 0 });

#endif
