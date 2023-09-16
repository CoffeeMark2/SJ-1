/*2152988 计科 杨恺铭*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("请输入半径和高度\n");
    const double Pi = 3.14159;
    double r, h, cirC, cirS, ballS, ballV, cylV;
    scanf("%lf %lf",&r,&h);
    cirC = 2 * Pi * r;
    cirS = Pi * r * r;
    ballS = 4 * cirS;
    ballV = 4.0 / 3.0 * Pi * r * r * r;
    cylV = cirS * h;
    printf("%-11s: %.2f\n", "圆周长", cirC);
    printf("%-11s: %.2f\n", "圆面积", cirS);
    printf("%-11s: %.2f\n", "圆球表面积", ballS);
    printf("%-11s: %.2f\n", "圆球体积", ballV);
    printf("%-11s: %.2f\n", "圆柱体积", cylV);

    return 0;
}
