#include <stdio.h>

int main()
{
    float a=1.23f, b=4.56f;
    char num[8];

    *(float*)(num) = a;
    *(float*)(num + 4) = b;

    float output1 = *(float*)(num);
    float output2 = *(float*)(num + 4);

    printf("method two:a = %.2f, b = %.2f\n", output1, output2);
    return 0;
}