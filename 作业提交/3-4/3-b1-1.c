/*2152988 �ƿ� ������*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    printf("������뾶�͸߶�\n");
    const double Pi = 3.14159;
    double r, h, cirC, cirS, ballS, ballV, cylV;
    scanf("%lf %lf",&r,&h);
    cirC = 2 * Pi * r;
    cirS = Pi * r * r;
    ballS = 4 * cirS;
    ballV = 4.0 / 3.0 * Pi * r * r * r;
    cylV = cirS * h;
    printf("%-11s: %.2f\n", "Բ�ܳ�", cirC);
    printf("%-11s: %.2f\n", "Բ���", cirS);
    printf("%-11s: %.2f\n", "Բ������", ballS);
    printf("%-11s: %.2f\n", "Բ�����", ballV);
    printf("%-11s: %.2f\n", "Բ�����", cylV);

    return 0;
}
