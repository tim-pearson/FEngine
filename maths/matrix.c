#include "matrix.h"
#include "maths/utils.h"
#include <math.h>

//mat4

mat4 mat4Identity(void){
    mat4 result = { 0 };
    result.m[0][0] = 1.0f;
    result.m[1][1] = 1.0f;
    result.m[2][2] = 1.0f;
    result.m[3][3] = 1.0f;
    return result;
}

mat4 mat4Mul(mat4 a, mat4 b){
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

mat4 mat4Translate(mat4 a, vec3 b){
    mat4 result = mat4Identity();
    result.m[3][0] = b.x;
    result.m[3][1] = b.y;
    result.m[3][2] = b.z;
    return mat4Mul(a, result);
}

mat4 mat4Scale(mat4 a, vec3 b){
    mat4 result = mat4Identity();
    result.m[0][0] = b.x;
    result.m[1][1] = b.y;
    result.m[2][2] = b.z;
    return mat4Mul(a, result);
}

mat4 mat4RotateX(mat4 a, float b){
    mat4 result = mat4Identity();
    result.m[1][1] = cosf(b);
    result.m[1][2] = -sinf(b);
    result.m[2][1] = sinf(b);
    result.m[2][2] = cosf(b);
    return mat4Mul(a, result);
}

mat4 mat4RotateY(mat4 a, float b){
    mat4 result = mat4Identity();
    result.m[0][0] = cosf(b);
    result.m[0][2] = sinf(b);
    result.m[2][0] = -sinf(b);
    result.m[2][2] = cosf(b);
    return mat4Mul(a, result);
}

mat4 mat4RotateZ(mat4 a, float b){
    mat4 result = mat4Identity();
    result.m[0][0] = cosf(b);
    result.m[0][1] = -sinf(b);
    result.m[1][0] = sinf(b);
    result.m[1][1] = cosf(b);
    return mat4Mul(a, result);
}

mat4 mat4Ortho(float left, float right, float bottom, float top, float near, float far){
    mat4 result = mat4Identity();
    result.m[0][0] = 2.0f / (right - left);
    result.m[1][1] = 2.0f / (top - bottom);
    result.m[2][2] = 2.0f / (near - far);
    result.m[3][0] = (left + right) / (left - right);
    result.m[3][1] = (bottom + top) / (bottom - top);
    result.m[3][2] = (far + near) / (far - near);
    return result;
}

mat4 mat4Perspective(float fov, float aspect, float near, float far){
    mat4 result = mat4Identity();
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

mat4 mat4Look_at(vec3 eye, vec3 center, vec3 up){
    mat4 result;
    vec3 f = vec3Normalize(vec3Sub(center, eye));
    vec3 s = vec3Normalize(vec3Cross(f, up));
    vec3 u = vec3Cross(s, f);
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
    result.m[3][0] = -vec3Dot(s, eye);
    result.m[3][1] = -vec3Dot(u, eye);
    result.m[3][2] = vec3Dot(f, eye);
    result.m[3][3] = 1.0f;
    return result;
}

mat4 mat4Transform(transform t)
{
    mat4 m = mat4Identity();
    m = mat4RotateX(m, t.rot.x);
    m = mat4RotateY(m, t.rot.y);
    m = mat4RotateZ(m, t.rot.z);
    m = mat4Translate(m, t.pos);
    m = mat4Scale(m, t.scale);
    return m;
}

mat4 viewMatrix(vec3 pos, vec3 rot)
{
    mat4 m = mat4Identity();
    m = mat4RotateX(m, rot.x);
    m = mat4RotateY(m, rot.y);
    m = mat4RotateZ(m, rot.z);
    m = mat4Translate(m, vec3Scale(pos, -1.0f));
    return m;
}

//mat4

mat3 mat3Identity(void){
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

mat3 mat3Mul(mat3 a, mat3 b)
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
mat3 mat3Translate(mat3 a, vec2 b)
{
    mat3 result = mat3Identity();
    result.m[2][0] = b.x;
    result.m[2][1] = b.y;
    return mat3Mul(a, result);
}
mat3 mat3Scale(mat3 a, vec2 b)
{
    mat3 result = mat3Identity();
    result.m[0][0] = b.x;
    result.m[1][1] = b.y;
    return mat3Mul(a, result);
}
mat3 mat3Rotate(float b)
{
    mat3 result = mat3Identity();
    result.m[0][0] = cosf(b);
    result.m[0][1] = -sinf(b);
    result.m[1][0] = sinf(b);
    result.m[1][1] = cosf(b);
    return result;
}
