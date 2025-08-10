#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../inc/queue.h"

void QueueInit(queue *q)// 初始化队列
{
    q->front = q->rear = 0;// 将各项参数置零
    for (int i = 0; i < QUEUE_MAX_SIZE; i++)
    {
        q->data[i] = 0;
    }
}

void QueueStorage(queue *q,int data[],int size)// 数据批量入队
{
    int remain = (QUEUE_MAX_SIZE + q->front - q->rear - 1) % QUEUE_MAX_SIZE;// 计算队列剩余容量
    if(size > remain)// 判断输入数据数量是否超过队列剩余容量
    {
        printf("输入错误,数据数量超过队列剩余容量\n");
        return;
    }
    for(int i = 0; i < size; i++)//将数组数据存入队列
    {
        QueuePush(q, data[i]);// 调用入队函数
    }
}

bool QueueEmpty(queue *q)// 判断队列是否为空
{
    return (q->front == q->rear);
}

bool QueueFull(queue *q)// 判断队列是否为满
{
    return (((q->rear + 1) % QUEUE_MAX_SIZE) == q->front);// 存满后rear如果再+1就会追上front，再取模判断就可以看出是否存满
}

bool QueuePush(queue *q, int value)// 数据入队
{
    if (QueueFull(q))// 判断队列是否已满
    {
        printf("队列已满，无法添加新元素\n");
        return false;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;// rear加1后再对最大值取模,防止rear越界
    return true;
}

bool QueuePop(queue *q, int *value)// 数据出队
{
    if(QueueEmpty(q))// 判断队列是否为空
    {
        printf("队列内没有元素,无法输出!\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_MAX_SIZE;// front加1后再对最大值取模,防止front越界
    return true;
}