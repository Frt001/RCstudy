#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../inc/stack.h"

int main()
{
    stack s; // 声明栈变量
    StackInit(&s, 10); // 初始化栈，设置大小为10

    int value = 42; // 要入栈的值
    if (StackPush(&s, &value, sizeof(value))) // 入栈操作
    {
        printf("入栈成功: %d\n", value);
    }

    int poppedValue; // 用于存储出栈的值
    if (StackPop(&s, &poppedValue, sizeof(poppedValue))) // 出栈操作
    {
        printf("出栈成功: %d\n", poppedValue);
    }

    StackFree(&s); // 释放栈内存
    return 0;
}