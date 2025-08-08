#ifndef VECTOR3F_H
#define VECTOR3F_H

typedef struct 
{
    float x;
    float y;
    float z;
} Vector3f;


//函数声明
Vector3f vector_add(Vector3f a, Vector3f b);//向量加法
Vector3f vector_sub(Vector3f a, Vector3f b);//向量减法
float vector_dot(Vector3f a, Vector3f b);//向量点乘
float vector_norm(Vector3f a);//向量求模
Vector3f vector_cross(Vector3f a, Vector3f b);//向量叉乘
Vector3f vector_normalize(Vector3f a);//向量单位化
void vector_print(Vector3f a); //以向量形式输出向量
#endif