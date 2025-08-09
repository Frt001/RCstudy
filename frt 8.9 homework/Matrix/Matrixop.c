#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Matrixop.h"

Matrix MatrixMultiply(Matrix a, Matrix b)
{
    if(a->column != b->row)//检测两个矩阵能否相乘
    {
        printf("这两个矩阵无法相乘！\n");
        return NULL;
    }

    Matrix result = malloc(sizeof(struct MParam));//为结果矩阵分配内存
    if(result == NULL)//检查内存分配结果
    {
        printf("内存分配失败！\n");
        return NULL;
    }

    
    result->row = a->row;//计算结果矩阵的行列数
    result->column = b->column;
    result->data = malloc(result->row * sizeof(float*));//为结果矩阵分配内存
    if(result->data == NULL)//检查内存分配结果，分配失败释放内存
    {
        printf("内存分配失败！\n");
        free(result);
        return NULL;
    }

    int i, j, k;
    for(i = 0; i < result->row; i++)//为结果矩阵的每一行分配内存
    {
        result->data[i] = malloc(result->column * sizeof(float));
        if(result->data[i] == NULL)//检查内存分配结果，分配失败释放内存
        {
            printf("内存分配失败！\n");
            for(int m = 0; m < i; m++) 
            {
                free(result->data[m]);
            }
            free(result->data);
            free(result);
            return NULL;
        }
    }

    for(i = 0; i < result->row; i++)//初始化结果矩阵的各项元素，将其全置零
    {
        for(j=0; j < result->column; j++)
        {
            result->data[i][j] = 0;
            }
    }

    for(i = 0; i < result->row; i++)//将a b矩阵相乘后各项的元素导入结果矩阵目标位置
    {
        for(j=0; j < result->column; j++)
        {
            for(k=0; k < a->column; k++)
            {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}


Matrix MatrixTranspose(Matrix a)
{
    Matrix result = malloc(sizeof(struct MParam));//为结果矩阵分配内存
    if(result == NULL)//检查内存分配结果
    {
        printf("内存分配失败！\n");
        return NULL;
    }

    result->row = a->column;//计算结果矩阵的行列数
    result->column = a->row;
    result->data = malloc(result->row * sizeof(float*));//为结果矩阵分配内存
    if(result->data == NULL)//检查内存分配结果
    {
        printf("内存分配失败！\n");
        free(result);
        return NULL;
    }

    for(int i = 0; i < result->row; i++)//为结果矩阵的每一行分配内存
    {
        result->data[i] = malloc(result->column * sizeof(float));
        if(result->data[i] == NULL)//检查内存分配结果，分配失败释放内存
        {
            printf("内存分配失败！\n");
            for(int m = 0; m < i; m++) free(result->data[m]);
            free(result->data);
            free(result);
            return NULL;
        }
    }

    for(int i = 0; i < result->row; i++)//转置过程
    {
        for(int j = 0; j < result->column; j++)
        {
            result->data[i][j] = a->data[j][i];
        }
    }

    return result;
}


void MatrixFree(Matrix *a)
{
    if (a == NULL || *a == NULL) 
    return;//检测该矩阵所占内存是否已经为空，或是不存在

    if ((*a)->data != NULL) 
    {
        for (int i = 0; i < (*a)->row; i++) 
        {
            free((*a)->data[i]);//释放各行内存
        }
        free((*a)->data);//释放data内存
    }
    free(*a);//释放矩阵内存
    *a = NULL; 
}
