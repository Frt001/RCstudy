#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../inc/queue.h"

int main()
{
    queue Bq;
    QueueInit(&Bq);// 初始化队列
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(data) / sizeof(data[0]);// 计算数组大小
    QueueStorage(&Bq, data, size);// 批量入队
    printf("队列内元素为:");
    for(int i = 0; i < size; i++)// 循环出队
    {
        int value;
        if(QueuePop(&Bq, &value))// 调用出队函数
        {
            printf("%d ", value);// 输出出队数据
        }
    }
    printf("\n");
    return 0;
}