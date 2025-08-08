#include <stdio.h>
#include <string.h>

int main()
{
    float a=1.23f, b=4.56f;
    char num[8];

    memcpy(num, &a, 4);
    memcpy(num+4, &b, 4);

    float output1, output2;
    memcpy(&output1, num, 4);
    memcpy(&output2, num+4, 4);

    printf("method one:a = %.2f, b = %.2f\n", output1, output2);
    return 0;
}