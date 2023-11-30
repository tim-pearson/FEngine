#include "matrix.h"
#include "maths/utils.h"
#include <math.h>

//mat4

mat4 mat4_identity(void){
    mat4 result = { 0 };
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;
    return result;
}

mat4 mat4_mul(mat4 a, mat4 b){
    mat4 result;
    result.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0];
    result.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1];
    result.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2];
    result.m[0][3] = a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] + a.m[0][3] * b.m[3][3];
    result.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0];
    result.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1];
    result.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2];
    result.m[1][3] = a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3];
    result.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0];
    result.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1];
    result.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2];
    result.m[2][3] = a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3];
    result.m[3][0] = a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] + a.m[3][3] * b.m[3][0];
    result.m[3][1] = a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1];
    result.m[3][2] = a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2];
    result.m[3][3] = a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3];
    return result;
}

mat4 mat4_translate(mat4 a, vec3 b){
    mat4 result = mat4_identity();
    result.m[3][0] = b.x;
    result.m[3][1] = b.y;
    result.m[3][2] = b.z;
    return mat4_mul(a, result);
}

mat4 mat4_scale(mat4 a, vec3 b){
    mat4 result = mat4_identity();
    result.m[0][0] = b.x;
    result.m[1][1] = b.y;
    result.m[2][2] = b.z;
    return mat4_mul(a, result);
}

mat4 mat4_rotate_x(mat4 a, float b){
    mat4 result = mat4_identity();
    result.m[1][1] = cosf(b);
    result.m[1][2] = -sinf(b);
    result.m[2][1] = sinf(b);
    result.m[2][2] = cosf(b);
    return mat4_mul(a, result);
}

mat4 mat4_rotate_y(mat4 a, float b){
    mat4 result = mat4_identity();
    result.m[0][0] = cosf(b);
    result.m[0][2] = sinf(b);
    result.m[2][0] = -sinf(b);
    result.m[2][2] = cosf(b);
    return mat4_mul(a, result);
}

mat4 mat4_rotate_z(mat4 a, float b){
    mat4 result = mat4_identity();
    result.m[0][0] = cosf(b);
    result.m[0][1] = -sinf(b);
    result.m[1][0] = sinf(b);
    result.m[1][1] = cosf(b);
    return mat4_mul(a, result);
}

mat4 mat4_ortho(float left, float right, float bottom, float top, float near, float far){
    mat4 result = mat4_identity();
    result.m[0][0] = 2.0f / (right - left);
    result.m[1][1] = 2.0f / (top - bottom);
    result.m[2][2] = 2.0f / (near - far);
    result.m[3][0] = (left + right) / (left - right);
    result.m[3][1] = (bottom + top) / (bottom - top);
    result.m[3][2] = (far + near) / (far - near);
    return result;
}

mat4 mat4_perspective(float fov, float aspect, float near, float far){
    mat4 result = mat4_identity();
    float q = 1.0f / tanf(fov * 0.5f * (float)M_PI / 180.0f);
    float a = q / aspect;
    float b = (near + far) / (near - far);
    float c = (2.0f * near * far) / (near - far);
    result.m[0][0] = a;
    result.m[1][1] = q;
    result.m[2][2] = b;
    result.m[2][3] = -1.0f;
    result.m[3][2] = c;
    result.m[3][3] = 0.0f;
    return result;
}

mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up){
    mat4 result;
    vec3 f = vec3_normalize(vec3_sub(center, eye));
    vec3 s = vec3_normalize(vec3_cross(f, up));
    vec3 u = vec3_cross(s, f);
    result.m[0][0] = s.x;
    result.m[0][1] = u.x;
    result.m[0][2] = -f.x;
    result.m[0][3] = 0.0f;
    result.m[1][0] = s.y;
    result.m[1][1] = u.y;
    result.m[1][2] = -f.y;
    result.m[1][3] = 0.0f;
    result.m[2][0] = s.z;
    result.m[2][1] = u.z;
    result.m[2][2] = -f.z;
    result.m[2][3] = 0.0f;
    result.m[3][0] = -vec3_dot(s, eye);
    result.m[3][1] = -vec3_dot(u, eye);
    result.m[3][2] = vec3_dot(f, eye);
    result.m[3][3] = 1.0f;
    return result;
}

mat4 mat4_transform(vec3 pos, vec3 scale, vec3 rot)
{
    mat4 m = mat4_identity();
    m = mat4_rotate_x(m, rot.x);
    m = mat4_rotate_y(m, rot.y);
    m = mat4_rotate_z(m, rot.z);
    m = mat4_translate(m, pos);
    m = mat4_scale(m, scale);
    return m;
}


//mat4

mat3 mat3_identity(void){
    mat3 result;
    result.m[0][0] = 1.0f;
    result.m[0][1] = 0.0f;
    result.m[0][2] = 0.0f;
    result.m[1][0] = 0.0f;
    result.m[1][1] = 1.0f;
    result.m[1][2] = 0.0f;
    result.m[2][0] = 0.0f;
    result.m[2][1] = 0.0f;
    result.m[2][2] = 1.0f;
    return result;
}

mat3 mat3_mul(mat3 a, mat3 b)
{
    mat3 result; 
    result.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0];
    result.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1];
    result.m[0][2] = a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2];
    result.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0];
    result.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1];
    result.m[1][2] = a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2];
    result.m[2][0] = a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0];
    result.m[2][1] = a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1];
    result.m[2][2] = a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2];
    return result;
}
mat3 mat3_translate(mat3 a, vec2 b)
{
    mat3 result = mat3_identity();
    result.m[2][0] = b.x;
    result.m[2][1] = b.y;
    return mat3_mul(a, result);
}
mat3 mat3_scale(mat3 a, vec2 b)
{
    mat3 result = mat3_identity();
    result.m[0][0] = b.x;
    result.m[1][1] = b.y;
    return mat3_mul(a, result);
}
mat3 mat3_rotate(float b)
{
    mat3 result = mat3_identity();
    result.m[0][0] = cosf(b);
    result.m[0][1] = -sinf(b);
    result.m[1][0] = sinf(b);
    result.m[1][1] = cosf(b);
    return result;
}
