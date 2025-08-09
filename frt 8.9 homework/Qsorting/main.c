#include <stdio.h>
#include <stdlib.h>


int compare_float(const void *a, const void *b)//比较函数
{
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    if (fa > fb) return 1;
    else if (fa < fb) return -1;
    else return 0;
}

int main()
{
    float *nums = NULL; //动态数组
    int count = 0;      //实际数量
    int capacity = 0;   //当前容量
    float temp;

    printf("请输入任意数量的浮点数，空格分隔，回车结束：\n");

    while (scanf("%f", &temp) == 1) 
    {
        if (count >= capacity) //如果数组满了，扩容
        {
            capacity = (capacity == 0) ? 4 : capacity * 2;
            float *new_nums = realloc(nums, capacity * sizeof(float));
            if (new_nums == NULL) //检查内存分配是否成功
            {
                printf("内存分配失败！\n");
                free(nums);
                return 1;
            }
            nums = new_nums;
        }

        nums[count++] = temp;

        char c = getchar();// 检查下一个字符是否是回车，识别到回车后排序输出
        if (c == '\n') break;
    }


    qsort(nums, count, sizeof(float), compare_float);// 用 qsort 排序

    
    printf("从小到大排序结果：\n");// 输出结果

    for (int i = 0; i < count; i++) 
    {
        printf("%.2f ", nums[i]);
    }
    printf("\n");

    free(nums);//释放内存空间
    return 0;
}
