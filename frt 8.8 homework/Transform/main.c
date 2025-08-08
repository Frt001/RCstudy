#include <stdio.h>
#include <stdint.h>

int main() 
{
    uint32_t num = 0x12253647;
    printf("原始数字:0x%X\n", num);

    uint16_t test = 0x0102;//用于判断现在是什么模式
    if (*((uint8_t*)&test) == 0x02) //将test指针强制转换成1字节单位，再读取这个低地址第一个字节的值，如果是0x02说明是小端模式，反之则为大端
    {
        printf("本机是：小端模式\n");
    } 
    else 
    {
        printf("本机是：大端模式\n");
    }

    printf("本机字节序下的存储：");//打印本机字节序下的存储
    uint8_t* p = (uint8_t*)&num;//将num指针强制转换成1字节单位，然后就可以逐个字节的读取num的值
    for (int i = 0; i < 4; i++) 
    {
        printf("%02X ", p[i]);
    }
    printf("\n");

    uint32_t swapped =//利用一个辅助值进行大小端转换
        ((num >> 24) & 0x000000FF) |
        ((num >> 8)  & 0x0000FF00) |
        ((num << 8)  & 0x00FF0000) |
        ((num << 24) & 0xFF000000);

    printf("转换为另一种字节序的存储：");//打印转换后的存储
    uint8_t* q = (uint8_t*)&swapped;
    for (int i = 0; i < 4; i++) {
        printf("%02X ", q[i]);
    }
    printf("\n");

    return 0;
}