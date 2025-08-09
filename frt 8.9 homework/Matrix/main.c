#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Matrixop.h"

int main()
{
    Matrix a = malloc(sizeof(struct MParam));//定义矩阵a
    if(a == NULL)//检查内存分配结果
    {
        printf("内存分配失败！\n");
        return -1;
    }

    unsigned int x, y;//读取a的行列数
    printf("请输入矩阵A的行数和列数(空格隔开):");
    scanf("%u %u", &x, &y);
    a->row = x;
    a->column = y;

    a->data = malloc(a->row * sizeof(float*));//为矩阵a分配内存
    if(a->data == NULL)//检查内存分配结果
    {
        printf("内存分配失败！\n");
        free(a);
        return -1;
    }

    for(int i = 0; i < a->row; i++)//为矩阵每一行分配内存
    {
        a->data[i] = malloc(a->column * sizeof(float));
        if(a->data[i] == NULL)//检查内存分配结果
        {
            printf("内存分配失败！\n");
            for(int j = 0; j < i; j++)
            {
                free(a->data[j]);
            }
            free(a->data);
            free(a);
            return -1;
        }
    }

    printf("请输入矩阵A的元素(按行输入):\n");//存入a的元素
    for(int i = 0; i < a->row; i++)
    {
        printf("请输入第%d行的元素(空格隔开):", i + 1);
        for(int j = 0; j < a->column; j++)
        {
            scanf("%f", &a->data[i][j]);
        }
    }

    Matrix at = MatrixTranspose(a);//转置矩阵a
    Matrix final = MatrixMultiply(a, at);//计算a与其转置矩阵的乘积

    if(final != NULL)
    {
        printf("矩阵A与其转置矩阵的乘积为:\n");
        for(int i = 0; i < final->row; i++)
        {
            for(int j = 0; j < final->column; j++)
            {
                printf("%.2f ", final->data[i][j]);
            }
            printf("\n");
        }
    }

    MatrixFree(&a);//运行完成释放内存
    MatrixFree(&at);
    MatrixFree(&final);

    return 0;
}