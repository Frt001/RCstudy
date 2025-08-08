#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main() {
    uint32_t result = 0; // 先初始化最后结果，将其置零
    int number;

    srand((unsigned int)time(NULL)); // 使用时间初始化随机数种子

    printf("生成的32个随机数:\n");

    for (int i = 0; i < 32; i++) 
    {
        number = rand() % 101; // 生成0~100之间的随机整数
        printf("%d ", number);

        if (number > 50) //判断生成的随机数是否大于50
        {
            result |= (1U << i); // 设置第i位为1
        }
    }

    printf("\n\n最终结果(十进制): %u\n", result);//输出这个整数

    printf("最终结果(二进制): ");//输出这个整数的32位二进制形式
    for (int i = 31; i >= 0; i--) 
    {
        printf("%d", (result >> i) & 1);
    }

    return 0;
}
