#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
typedef struct Stack
{
    char *top; // 栈顶指针
    char *base; // 栈底指针
    int size; // 栈的大小
} stack;

void StackInit(stack *s, int sz); // 初始化栈
bool StackEmpty(stack *s); // 判断栈是否为空
bool StackFull(stack *s); // 判断栈是否为满
bool StackPush(stack *s, void *value, unsigned int sz); // 数据入栈
bool StackPop(stack *s, void *value, unsigned int sz); // 数据出栈
void StackFree(stack *s); // 释放栈内存

#endif // STACK_H