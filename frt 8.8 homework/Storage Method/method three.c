#include <stdio.h>
#include <string.h>

union FloatBytes 
{
    float f;
    char bytes[4];
};

int main() 
{
    float a = 1.23f, b = 4.56f;
    union FloatBytes u1, u2;
    char num[8];

    u1.f = a;
    u2.f = b;
    memcpy(num, u1.bytes, 4);
    memcpy(num + 4, u2.bytes, 4);

    union FloatBytes out1, out2;
    memcpy(out1.bytes, num, 4);
    memcpy(out2.bytes, num + 4, 4);

    printf("method three:a = %.2f, b = %.2f\n", out1.f, out2.f);
    return 0;
}
