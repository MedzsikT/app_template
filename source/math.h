/* date = September 5th 2021 2:21 pm */

#ifndef MATH_H
#define MATH_H

#include "base_layer.h"

internal f32 LerpF(f32 to, f32 from, f32 step)
{
    return (from + step * (to - from));
}

//~ Vector2
typedef union v2 v2;
union v2
{
    struct { f32 x, y; };
    
    f32 elements[2];
};

internal v2 V2Init(f32 x, f32 y)
{
    v2 result;
    result.x = x;
    result.y = y;
    
    return result;
}
#define v2(...) V2Init(__VA_ARGS__)

internal void V2Print(v2 v)
{
    printf("v2 = { %f, %f };\n", v.x, v.y);
}

internal f32 V2LengthSquared(v2 v)
{
    return v.x*v.x + v.y*v.y;
}

internal v2 V2Normalize(v2 v)
{
    f32 length = SquareRoot(V2LengthSquared(v));
    v.x /= length;
    v.y /= length;
    return v;
}

internal f32 V2Dot(v2 a, v2 b)
{
    return a.x*b.x + a.y*b.y;
}

internal f32 V2Length(v2 a)
{
    return SquareRoot(V2LengthSquared(a));
}

internal v2 V2AddV2(v2 a, v2 b)
{
    v2 c = { a.x + b.x, a.y + b.y };
    return c;
}

internal v2 V2MinusV2(v2 a, v2 b)
{
    v2 c = { a.x - b.x, a.y - b.y };
    return c;
}

internal v2 V2MultiplyV2(v2 a, v2 b)
{
    v2 c = { a.x * b.x, a.y * b.y }; 
    return c;
}

internal v2 V2DivideV2(v2 a, v2 b)
{
    v2 c = { a.x / b.x, a.y / b.y }; 
    return c;
}

internal v2 V2MultiplyF32(v2 v, f32 f)
{
    v.x *= f;
    v.y *= f;
    return v;
}

internal v2 LerpV2(v2 to, v2 from, f32 step)
{
    v2 result;
    result.x = LerpF(to.x, from.x, step);
    result.y = LerpF(to.y, from.y, step);
    
    return result;
}

//~ IVector2
typedef union iv2 iv2;
union iv2
{
    struct { i32 x, y; };
    struct { i32 width, height; };
    
    i32 elements[2];
};

internal iv2 IV2Init(i32 x, i32 y)
{
    iv2 result;
    result.x = x;
    result.y = y;
    
    return result;
}
#define iv2(...) IV2Init(__VA_ARGS__)

internal void IV2Print(iv2 v)
{
    printf("iv2 = { %d, %d };\n", v.x, v.y);
}

//~ Vector3
typedef union v3 v3;
union v3
{
    struct { f32 x, y, z; };
    struct { f32 r, g, b; };
    struct { v2 xy; f32 ignored0; };
    struct { f32 ignored1; v2 yz; };
    
    f32 elements[3];
};

internal v3 V3Init(f32 x, f32 y, f32 z)
{
    v3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    
    return result;
}
#define v3(...) V3Init(__VA_ARGS__)

internal void V3Print(v3 v)
{
    printf("v3 = { %f, %f, %f };\n", v.x, v.y, v.z);
}

internal f32 V3LengthSquared(v3 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

internal f32 V3Length(v3 a)
{
    return SquareRoot(V3LengthSquared(a));
}

internal v3 V3Normalize(v3 v)
{
    f32 length = V3Length(v);
    v3 result = {
        v.x / length,
        v.y / length,
        v.z / length,
    };
    return result;
}

internal f32 V3Dot(v3 a, v3 b)
{
    f32 dot =
        a.x * b.x + 
        a.y * b.y +
        a.z * b.z;
    return dot;
}

internal v3 V3AddV3(v3 a, v3 b)
{
    v3 c = { a.x + b.x, a.y + b.y };
    return c;
}

internal v3 V3MinusV3(v3 a, v3 b)
{
    v3 c = { a.x - b.x, a.y - b.y };
    return c;
}

internal v3 V3MultiplyV3(v3 a, v3 b)
{
    v3 c = { a.x * b.x, a.y * b.y }; 
    return c;
}

internal v3 V3DivideV3(v3 a, v3 b)
{
    v3 c = { a.x / b.x, a.y / b.y }; 
    return c;
}

internal v3 V3MultiplyF32(v3 v, f32 f)
{
    v.x *= f;
    v.y *= f;
    v.z *= f;
    return v;
}

internal v3 V3Cross(v3 a, v3 b)
{
    v3 result = {
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x,
    };
    return result;
}

internal float MinimumInV3(v3 v)
{
    float minimum = v.x;
    if(v.y < minimum) { minimum = v.y; }
    if(v.z < minimum) { minimum = v.z; }
    return minimum;
}

internal float MaximumInV3(v3 v)
{
    float maximum = v.x;
    if(v.y > maximum) { maximum = v.y; }
    if(v.z > maximum) { maximum = v.z; }
    return maximum;
}

internal v3 LerpV3(v3 to, v3 from, f32 step)
{
    v3 result;
    result.x = LerpF(to.x, from.x, step);
    result.y = LerpF(to.y, from.y, step);
    result.z = LerpF(to.z, from.z, step);
    
    return result;
}

//~ IVector3
typedef union iv3 iv3;
union iv3
{
    struct { i32 x, y, z; };
    
    i32 elements[3];
};

internal iv3 IV3Init(i32 x, i32 y, i32 z)
{
    iv3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    
    return result;
}
#define iv3(...) IV3Init(__VA_ARGS__)

internal void IV3Print(iv3 v)
{
    printf("iv3 = { %d, %d, %d };\n", v.x, v.y, v.z);
}

//~ Vector4
typedef union v4 v4;
union v4
{
    struct
    {
        f32 x, y;
        union
        {
            struct { f32 z; union { f32 w; f32 radius; }; };
            struct { f32 width, height; };
        };
    };
    
    struct { f32 r, g, b, a; };
    struct { v3 xyz; f32 ignored0; };
    struct { f32 ignored1; v3 yzw; };
    
    f32 elements[4];
};

internal v4 V4Init(f32 x, f32 y, f32 z, f32 w)
{
    v4 result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    
    return result;
}
#define v4(...) V4Init(__VA_ARGS__)

internal void V4Print(v4 v)
{
    printf("v4 = { %f, %f, %f, %f };\n", v.x, v.y, v.z,  v.w);
}

internal f32 V4LengthSquared(v4 a)
{
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

internal f32 V4Length(v4 a)
{
    return SquareRoot(V4LengthSquared(a));
}

internal v4 V4Normalize(v4 v)
{
    f32 length = V4Length(v);
    v4 result = {
        v.x / length,
        v.y / length,
        v.z / length,
        v.w / length,
    };
    return result;
}

internal f32 V4Dot(v4 a, v4 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

internal v4 V4AddV4(v4 a, v4 b)
{
    v4 c = { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
    return c;
}

internal v4 V4MinusV4(v4 a, v4 b)
{
    v4 c = { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
    return c;
}

internal v4 V4MultiplyV4(v4 a, v4 b)
{
    v4 c = { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
    return c;
}

internal v4 V4DivideV4(v4 a, v4 b)
{
    v4 c = { a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
    return c;
}

internal v4 V4MultiplyF32(v4 a, f32 f)
{
    v4 c = { a.x * f, a.y * f, a.z * f, a.w * f };
    return c;
}

internal v4 LerpV4(v4 to, v4 from, f32 step)
{
    v4 result;
    result.x = LerpF(to.x, from.x, step);
    result.y = LerpF(to.y, from.y, step);
    result.z = LerpF(to.z, from.z, step);
    result.w = LerpF(to.w, from.w, step);
    
    return result;
}

internal b32 V4RectHasPoint(v4 v, v2 p)
{
    return(p.x >= v.x && p.x <= v.x + v.width &&
           p.y >= v.y && p.y <= v.y + v.height);
}

//~ IVector4
typedef union iv4 iv4;
union iv4
{
    struct { i32 x, y, z, w; };
    
    i32 elements[4];
};

internal iv4 IV4Init(i32 x, i32 y, i32 z, i32 w)
{
    iv4 result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    
    return result;
}
#define iv4(...) IV4Init(__VA_ARGS__)

internal void IV4Print(iv4 v)
{
    printf("iv4 = { %d, %d, %d, %d };\n", v.x, v.y, v.z, v.w);
}

//~ Matrix4
typedef struct m4 m4;
struct m4
{
    f32 elements[4][4];
};

internal m4 M4Empty()
{
    m4 result = { 0 };
    return result;
}

internal m4 M4Init(f32 diagonal)
{
    m4 result = { 0 };
    result.elements[0][0] = diagonal;
    result.elements[1][1] = diagonal;
    result.elements[2][2] = diagonal;
    result.elements[3][3] = diagonal;
    
    return result;
}
#define m4(...) M4Init(__VA_ARGS__)

internal void M4Print(m4 matrix)
{
    printf("m4 =\n");
    for(int i = 0; i < 4; i++)
        printf("{ %f, %f, %f, %f }\n", matrix.elements[i][0], matrix.elements[i][1], matrix.elements[i][2], matrix.elements[i][3]);
}

internal m4 M4MultiplyF32(m4 a, f32 b)
{
    for(int j = 0; j < 4; ++j)
    {
        for(int i = 0; i < 4; ++i)
        {
            a.elements[i][j] *= b;
        }
    }
    
    return a;
}

internal v4 V4MultiplyM4(v4 v, m4 m)
{
    v4 result = {0};
    
    for(int i = 0; i < 4; ++i)
    {
        result.elements[i] = (v.elements[0]*m.elements[0][i] +
                              v.elements[1]*m.elements[1][i] +
                              v.elements[2]*m.elements[2][i] +
                              v.elements[3]*m.elements[3][i]);
    }
    
    return result;
}

internal m4 M4TranslateV3(v3 translation)
{
    m4 result = M4Init(1.f);
    result.elements[3][0] = translation.x;
    result.elements[3][1] = translation.y;
    result.elements[3][2] = translation.z;
    return result;
}

internal m4 M4ScaleV3(v3 scale)
{
    m4 result = M4Init(1.f);
    result.elements[0][0] = scale.x;
    result.elements[1][1] = scale.y;
    result.elements[2][2] = scale.z;
    return result;
}

internal m4 M4Perspective(f32 fov, f32 aspect_ratio, f32 near_z, f32 far_z)
{
    m4 result = {0};
    f32 tan_theta_over_2 = tanf(fov * (PI / 360.f));
    result.elements[0][0] = 1.f / tan_theta_over_2;
    result.elements[1][1] = aspect_ratio / tan_theta_over_2;
    result.elements[2][3] = -1.f;
    result.elements[2][2] = (near_z + far_z) / (near_z - far_z);
    result.elements[3][2] = (2.f * near_z * far_z) / (near_z - far_z);
    result.elements[3][3] = 0.f;
    return result;
}

internal m4 M4Orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near_depth, f32 far_depth)
{
    m4 result = {0};
    
    result.elements[0][0] = 2.f / (right - left);
    result.elements[1][1] = 2.f / (top - bottom);
    result.elements[2][2] = -2.f / (far_depth - near_depth);
    result.elements[3][3] = 1.f;
    result.elements[3][0] = (left + right) / (left - right);
    result.elements[3][1] = (bottom + top) / (bottom - top);
    result.elements[3][2] = (far_depth + near_depth) / (near_depth - far_depth);
    
    return result;
}

internal m4 M4LookAt(v3 eye, v3 center, v3 up)
{
    m4 result;
    
    v3 f = V3Normalize(V3MinusV3(center, eye));
    v3 s = V3Normalize(V3Cross(f, up));
    v3 u = V3Cross(s, f);
    
    result.elements[0][0] = s.x;
    result.elements[0][1] = u.x;
    result.elements[0][2] = -f.x;
    result.elements[0][3] = 0.0f;
    
    result.elements[1][0] = s.y;
    result.elements[1][1] = u.y;
    result.elements[1][2] = -f.y;
    result.elements[1][3] = 0.0f;
    
    result.elements[2][0] = s.z;
    result.elements[2][1] = u.z;
    result.elements[2][2] = -f.z;
    result.elements[2][3] = 0.0f;
    
    result.elements[3][0] = -V3Dot(s, eye);
    result.elements[3][1] = -V3Dot(u, eye);
    result.elements[3][2] = V3Dot(f, eye);
    result.elements[3][3] = 1.0f;
    
    return result;
}

internal m4 M4Inverse(m4 m)
{
    f32 coef00 = m.elements[2][2] * m.elements[3][3] - m.elements[3][2] * m.elements[2][3];
    f32 coef02 = m.elements[1][2] * m.elements[3][3] - m.elements[3][2] * m.elements[1][3];
    f32 coef03 = m.elements[1][2] * m.elements[2][3] - m.elements[2][2] * m.elements[1][3];
    f32 coef04 = m.elements[2][1] * m.elements[3][3] - m.elements[3][1] * m.elements[2][3];
    f32 coef06 = m.elements[1][1] * m.elements[3][3] - m.elements[3][1] * m.elements[1][3];
    f32 coef07 = m.elements[1][1] * m.elements[2][3] - m.elements[2][1] * m.elements[1][3];
    f32 coef08 = m.elements[2][1] * m.elements[3][2] - m.elements[3][1] * m.elements[2][2];
    f32 coef10 = m.elements[1][1] * m.elements[3][2] - m.elements[3][1] * m.elements[1][2];
    f32 coef11 = m.elements[1][1] * m.elements[2][2] - m.elements[2][1] * m.elements[1][2];
    f32 coef12 = m.elements[2][0] * m.elements[3][3] - m.elements[3][0] * m.elements[2][3];
    f32 coef14 = m.elements[1][0] * m.elements[3][3] - m.elements[3][0] * m.elements[1][3];
    f32 coef15 = m.elements[1][0] * m.elements[2][3] - m.elements[2][0] * m.elements[1][3];
    f32 coef16 = m.elements[2][0] * m.elements[3][2] - m.elements[3][0] * m.elements[2][2];
    f32 coef18 = m.elements[1][0] * m.elements[3][2] - m.elements[3][0] * m.elements[1][2];
    f32 coef19 = m.elements[1][0] * m.elements[2][2] - m.elements[2][0] * m.elements[1][2];
    f32 coef20 = m.elements[2][0] * m.elements[3][1] - m.elements[3][0] * m.elements[2][1];
    f32 coef22 = m.elements[1][0] * m.elements[3][1] - m.elements[3][0] * m.elements[1][1];
    f32 coef23 = m.elements[1][0] * m.elements[2][1] - m.elements[2][0] * m.elements[1][1];
    
    v4 fac0 = { coef00, coef00, coef02, coef03 };
    v4 fac1 = { coef04, coef04, coef06, coef07 };
    v4 fac2 = { coef08, coef08, coef10, coef11 };
    v4 fac3 = { coef12, coef12, coef14, coef15 };
    v4 fac4 = { coef16, coef16, coef18, coef19 };
    v4 fac5 = { coef20, coef20, coef22, coef23 };
    
    v4 vec0 = { m.elements[1][0], m.elements[0][0], m.elements[0][0], m.elements[0][0] };
    v4 vec1 = { m.elements[1][1], m.elements[0][1], m.elements[0][1], m.elements[0][1] };
    v4 vec2 = { m.elements[1][2], m.elements[0][2], m.elements[0][2], m.elements[0][2] };
    v4 vec3 = { m.elements[1][3], m.elements[0][3], m.elements[0][3], m.elements[0][3] };
    
    v4 inv0 = V4AddV4(V4MinusV4(V4MultiplyV4(vec1, fac0), V4MultiplyV4(vec2, fac1)), V4MultiplyV4(vec3, fac2));
    v4 inv1 = V4AddV4(V4MinusV4(V4MultiplyV4(vec0, fac0), V4MultiplyV4(vec2, fac3)), V4MultiplyV4(vec3, fac4));
    v4 inv2 = V4AddV4(V4MinusV4(V4MultiplyV4(vec0, fac1), V4MultiplyV4(vec1, fac3)), V4MultiplyV4(vec3, fac5));
    v4 inv3 = V4AddV4(V4MinusV4(V4MultiplyV4(vec0, fac2), V4MultiplyV4(vec1, fac4)), V4MultiplyV4(vec2, fac5));
    
    v4 sign_a = { +1, -1, +1, -1 };
    v4 sign_b = { -1, +1, -1, +1 };
    
    m4 inverse;
    for(u32 i = 0; i < 4; ++i)
    {
        inverse.elements[0][i] = inv0.elements[i] * sign_a.elements[i];
        inverse.elements[1][i] = inv1.elements[i] * sign_b.elements[i];
        inverse.elements[2][i] = inv2.elements[i] * sign_a.elements[i];
        inverse.elements[3][i] = inv3.elements[i] * sign_b.elements[i];
    }
    
    v4 row0 = { inverse.elements[0][0], inverse.elements[1][0], inverse.elements[2][0], inverse.elements[3][0] };
    v4 m0 = { m.elements[0][0], m.elements[0][1], m.elements[0][2], m.elements[0][3] };
    v4 dot0 = V4MultiplyV4(m0, row0);
    f32 dot1 = (dot0.x + dot0.y) + (dot0.z + dot0.w);
    
    f32 one_over_det = 1 / dot1;
    
    return M4MultiplyF32(inverse, one_over_det);
}

internal m4 M4RemoveRotation(m4 mat)
{
    v3 scale = {
        V3Length(v3(mat.elements[0][0], mat.elements[0][1], mat.elements[0][2])),
        V3Length(v3(mat.elements[1][0], mat.elements[1][1], mat.elements[1][2])),
        V3Length(v3(mat.elements[2][0], mat.elements[2][1], mat.elements[2][2])),
    };
    
    mat.elements[0][0] = scale.x;
    mat.elements[1][0] = 0.f;
    mat.elements[2][0] = 0.f;
    
    mat.elements[0][1] = 0.f;
    mat.elements[1][1] = scale.y;
    mat.elements[2][1] = 0.f;
    
    mat.elements[0][2] = 0.f;
    mat.elements[1][2] = 0.f;
    mat.elements[2][2] = scale.z;
    
    return mat;
}

internal m4 M4Rotate(f32 angle, v3 axis)
{
    m4 result = M4Init(1.f);
    
    axis = V3Normalize(axis);
    
    f32 sin_theta = SinF(angle);
    f32 cos_theta = CosF(angle);
    f32 cos_value = 1.0f - cos_theta;
    
    result.elements[0][0] = (axis.x * axis.x * cos_value) + cos_theta;
    result.elements[0][1] = (axis.x * axis.y * cos_value) + (axis.z * sin_theta);
    result.elements[0][2] = (axis.x * axis.z * cos_value) - (axis.y * sin_theta);
    
    result.elements[1][0] = (axis.y * axis.x * cos_value) - (axis.z * sin_theta);
    result.elements[1][1] = (axis.y * axis.y * cos_value) + cos_theta;
    result.elements[1][2] = (axis.y * axis.z * cos_value) + (axis.x * sin_theta);
    
    result.elements[2][0] = (axis.z * axis.x * cos_value) + (axis.y * sin_theta);
    result.elements[2][1] = (axis.z * axis.y * cos_value) - (axis.x * sin_theta);
    result.elements[2][2] = (axis.z * axis.z * cos_value) + cos_theta;
    
    return result;
}

internal float* 
M4ToFloatPtr(m4 mat)
{
    float* m = (float*)malloc(sizeof(float) * 16);
    
    //M4Print(mat);
    
    m[0]  = mat.elements[0][0];
    m[1]  = mat.elements[0][1];
    m[2]  = mat.elements[0][2];
    m[3] = mat.elements[0][3];
    m[4]  = mat.elements[1][0];
    m[5]  = mat.elements[1][1];
    m[6]  = mat.elements[1][2];
    m[7] = mat.elements[1][3];
    m[8]  = mat.elements[2][0];
    m[9]  = mat.elements[2][1];
    m[10] = mat.elements[2][2];
    m[11] = mat.elements[2][3];
    m[12]  = mat.elements[3][0];
    m[13]  = mat.elements[3][1];
    m[14] = mat.elements[3][2];
    m[15] = mat.elements[3][3];
    
    return m;
}

internal void
FloatPtrPrint(float* ptr)
{
    printf("--------------------\n");
    for(int i = 0; i < 16; i++)
    {
        printf("%f\n", ptr[i]);
    }
}

#endif //MATH_H
