#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    float a=59.622f, b=92.6327f;
    char num[4];

    uint16_t x = (uint16_t)(a * 1000);
    uint16_t y = (uint16_t)(b * 100);

    memcpy(num, &x, 2);
    memcpy(num + 2, &y, 2);

    uint16_t c, d;
    memcpy(&c, num, 2);
    memcpy(&d, num + 2, 2);

    float f1 = c*0.001;
    float f2 = d*0.01;

    float d1, d2;
    d1 = a-f1;
    d2 = b-f2;

    printf("存入前的值:a=%.3f, b=%.4f\n", a, b);
    printf("存入后的值:f1: %.3f, f2: %.4f\n", f1, f2);
    printf("误差值:d1: %.3f, d2: %.4f\n", d1, d2);

    return 0;
}