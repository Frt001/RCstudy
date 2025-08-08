#include <stdio.h>
#include <math.h>
#include "Vector3f.h"

Vector3f vector_add(Vector3f a, Vector3f b) //计算a b向量的和，返回值输出a+b
{
    Vector3f result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}


Vector3f vector_sub(Vector3f a, Vector3f b) //计算a b向量的差，返回值输出a-b
{
    Vector3f result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}


float vector_dot(Vector3f a, Vector3f b) //计算a b向量的点积，返回值输出a·b
{
    float dot_result = a.x * b.x + a.y * b.y + a.z * b.z;
    return dot_result;
}


float vector_norm(Vector3f a) //计算a向量的模，返回值输出|a|
{
    float norm_result = sqrt(vector_dot(a, a));
    return norm_result;
}


Vector3f vector_cross(Vector3f a, Vector3f b) //计算a b向量的叉积，返回值输出a×b
{
    Vector3f result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}


Vector3f vector_normalize(Vector3f a) //将a向量的单位化，返回值输出a/|a|
{
    float norm = vector_norm(a);
    Vector3f result;
    if (norm > 0) 
    {
        result.x = a.x / norm;
        result.y = a.y / norm;
        result.z = a.z / norm;
    }
    return result;
}


void vector_print(Vector3f a) //以向量形式输出向量
{
    printf("Vector3f(%f, %f, %f)\n", a.x, a.y, a.z);
}