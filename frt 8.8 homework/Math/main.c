#include <stdio.h>
#include <math.h>
#include "Vector3f.h"

int main()
{
    int choice;//用于选择解决问题类型
    printf("1.求点到直线的距离\n2.求直线到平行平面的距离\n请输入你要解决的问题(1或2):");
    scanf_s("%d", &choice);
    
    if(choice == 1)
    {
        Vector3f point, linePoint1, linePoint2;//定义直线外一点和直线上两点的坐标形式

        printf("请输入点的坐标x, y, z: ");
        scanf_s("%f %f %f", &point.x, &point.y, &point.z);
        printf("请输入直线的两个点的坐标x1, y1, z1, x2, y2, z2: ");
        scanf_s("%f %f %f %f %f %f", &linePoint1.x, &linePoint1.y, &linePoint1.z, &linePoint2.x, &linePoint2.y, &linePoint2.z);

        Vector3f line, auxiliary_line, cross_result;//定义直线的向量，直线外一点与直线上一点构成的辅助线向量，辅助线与直线叉乘的结果向量
        float line_norm, cross_norm, distance;//定义直线模，叉乘结果的模，点到直线的距离

        line = vector_sub(linePoint2,linePoint1);//求直线向量
        auxiliary_line = vector_sub(point, linePoint1);//求辅助线向量
        cross_result = vector_cross(auxiliary_line, line);//求叉乘结果向量
        line_norm = vector_norm(line);//求直线模
        cross_norm = vector_norm(cross_result);//求叉乘结果模

        distance = cross_norm/line_norm;//点到直线距离公式

        printf("点到直线的距离为: %.2f\n", distance);//输出结果
    }
    
    else if(choice == 2)
    {
        Vector3f linePoint1, linePoint2, planePoint3, planePoint4, planePoint5;//定义直线的两个点和一个平面的三个点
        Vector3f line, plane_line1, plane_line2, plane_normal;//定义直线，平面上两条直线，平面法向量
        float distance, d;//distance用于存储直线到平面的距离，d用于存储平面方程中的常数项
        int judge;//judge用于判断直线和平面是否平行
        float mole, normal_norm;//mole是后续求距离公式的分子值，normal_norm是平面法向量的模

        printf("请输入直线的两个点的坐标x1, y1, z1, x2, y2, z2: ");
        scanf_s("%f %f %f %f %f %f", &linePoint1.x, &linePoint1.y, &linePoint1.z, &linePoint2.x, &linePoint2.y, &linePoint2.z);
        printf("请输入平面的三个点坐标x3, y3, z3, x4, y4, z4, x5, y5, z5: ");
        scanf_s("%f %f %f %f %f %f %f %f %f", &planePoint3.x, &planePoint3.y, &planePoint3.z, &planePoint4.x, &planePoint4.y, &planePoint4.z, &planePoint5.x, &planePoint5.y, &planePoint5.z);

        line = vector_sub(linePoint2, linePoint1);//求直线向量
        plane_line1 = vector_sub(planePoint4, planePoint3);//求平面上第一条直线向量
        plane_line2 = vector_sub(planePoint5, planePoint3);//求平面上第二条直线向量
        plane_normal = vector_cross(plane_line1, plane_line2);//求平面法向量
        judge = vector_dot(line, plane_normal);//判断直线和平面是否平行

        d = -vector_dot(plane_normal, planePoint3);//求平面方程中的常数项
        normal_norm = vector_norm(plane_normal);//求平面法向量的模
        mole = vector_dot(linePoint1, plane_normal) + d;//求分子

        if(judge==0)//如果平行
        {
            distance = fabs(mole) / normal_norm;//求直线到平面的距离
            printf("直线到平面的距离为: %.2f\n", distance);
        }
        else//不平行不存在直线到平面的距离
        {
            printf("无法计算直线到平面的距离\n");
        }
    }

    else
    {
        printf("输入错误！\n");
    }
    return 0;
}