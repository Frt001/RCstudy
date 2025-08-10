#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../inc/stack.h"

void StackInit(stack *s, int sz) // 初始化栈
{
    s->size = sz;// 设置栈的大小
    s->base = (char *)malloc(s->size * sizeof(char)); // 分配内存
    s->top = s->base; // 栈顶指针指向栈底   
    if (s->base == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    return;
}

bool StackEmpty(stack *s) // 判断栈是否为空
{
    return (s->top == s->base);
}

bool StackFull(stack *s) // 判断栈是否为满
{
    return ((s->base - s->top) >= s->size);
}

bool StackPush(stack *s, void *value, unsigned int sz) // 数据入栈
{
    if (StackFull(s)) // 判断栈是否已满
    {
        printf("栈已满，无法添加新元素\n");
        return false;
    }
    s->top -= sz;
    memcpy(s->top, value, sz); // 将数据复制到栈顶
    return true;
}

bool StackPop(stack *s, void *value, unsigned int sz) // 数据出栈
{
    if ((s->top + sz) > s->base) // 判断栈是否为空
    {
        printf("栈内没有元素,无法输出!\n");
        return false;
    }
    memcpy(value, s->top, sz); // 将栈顶数据复制到输出变量
    s->top += sz; // 栈顶指针上移
    return true;
}

void StackFree(stack *s) // 释放栈内存
{
    free(s->base); // 释放栈底指针指向的内存
    s->base = s->top = NULL; // 将指针置空
    s->size = 0; // 将栈大小置零
    return;
}