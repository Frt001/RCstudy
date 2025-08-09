#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdint.h>

typedef struct MParam
{
uint8_t row;
uint8_t column;
float **data;
}*Matrix;

//声明函数
Matrix MatrixMultiply(Matrix a, Matrix b);//矩阵乘法
Matrix MatrixTranspose(Matrix a);//矩阵转置
void MatrixFree(Matrix *a);//释放矩阵内存

#endif