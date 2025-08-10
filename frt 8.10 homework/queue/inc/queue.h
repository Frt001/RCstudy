#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_MAX_SIZE 21
typedef struct Queue
{
    int front;
    int rear;
    int data[QUEUE_MAX_SIZE];
}queue;


void QueueInit(queue *q);
void QueueStorage(queue *q, int data[],int size);
bool QueueEmpty(queue *q);
bool QueueFull(queue *q);
bool QueuePush(queue *q,int value);
bool QueuePop(queue *q,int *value);


#endif // QUEUE_H