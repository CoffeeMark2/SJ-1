/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#define N  10

const char chnstr[] = "��Ҽ��������½��ƾ�";
char result[256] = ""; 
/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ������д��0~9
  ���������int num,int flag_of_zero
  �� �� ֵ��void
  ˵    ����
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	char tmp[3];
	if (num == 0 && !flag_of_zero) {
		return;
	}
	tmp[0] = chnstr[num * 2];
	tmp[1] = chnstr[num * 2 + 1];
	tmp[2] = 0;
	strcat(result, tmp);
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	printf("������[0-100��)֮�������:" "\n");
	scanf("%lf", &a);
	a1 = (int)(a / 10) % 10;
	a2 = (int)(a / 100) % 10;
	a3 = (int)(a / 1000) % 10;
	a4 = (int)(a / 10000) % 10;
	a5 = (int)(a / 100000) % 10;
	a6 = (int)(a / 1000000) % 10;
	a7 = (int)(a / 10000000) % 10;
	a8 = (int)(a / 100000000) % 10;
	a9 = (int)(a / 1000000000) % 10;
	a0 = (int)(a - a9 * pow(10, 9)) % 10;
	b = a - a9 * pow(10, 9) - a8 * pow(10, 8) - a7 * pow(10, 7)
		- a6 * pow(10, 6) - a5 * pow(10, 5) - a4 * pow(10, 4)
		- a3 * pow(10, 3) - a2 * pow(10, 2) - a1 * pow(10, 1)
		- a0 + 0.001;
	b1 = (int)(b * 10) % 10;
	b2 = (int)(b * 100) % 10;

	printf("��д�����:" "\n");

	int ret0 = 0;
	//�ڷ���ǰ����㣬���700�������㲻���������
	int begin = 0;
	//�������700���Ϊ����۵�����


	//���ڡ��򡢸�Ϊһ��������������ԭ�򡤡������ڲ��䣩
	ret0 = 0;

	//if (begin == 0)
	//	ret0 = 0;
	if (a9 != 0)
		begin = 1;
	//���� λ��Ӧ�����ģ�
	//ʲô˳��Ϊʲô�����ü�����

	if (a9 == 0 && a8 != 0 && begin) {
		ret0 = 1;
	}

	daxie(a9, ret0);
	ret0 = 0;
	if (a9)
		strcat(result, "ʰ");

	if (a8 != 0)
		begin = 1;
	//if (a8 == 0 && begin) {
	//	ret0 = 1;
	//}

	daxie(a8, ret0);
	ret0 = 0;
	if (a9 || a8)
		strcat(result, "��");

	//��
	ret0 = 0;

	if (a7 != 0)
		begin = 1;
	if (a7 == 0 && a6 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a7, ret0);
	ret0 = 0;
	if (a7)
		strcat(result, "Ǫ");

	if (a6 != 0)
		begin = 1;
	if (a6 == 0 && a5 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a6, ret0);
	ret0 = 0;

	if (a6)
		strcat(result, "��");


	if (a5 != 0)
		begin = 1;
	if (a5 == 0 && a4 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a5, ret0);
	ret0 = 0;

	if (a5)
		strcat(result, "ʰ");

	if (a4 != 0)
		begin = 1;
	//if (a4 == 0 && begin) {
	//	ret0 = 1;
	//}
	daxie(a4, ret0);
	ret0 = 0;
	if (a7 || a6 || a5 || a4)
		strcat(result, "��");


	//��

	if (a3 != 0)
		begin = 1;
	if (a3 == 0 && a2 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a3, ret0);
	ret0 = 0;
	if (a3)
		strcat(result, "Ǫ");

	if (a2 != 0)
		begin = 1;
	if (a2 == 0 && a1 != 0 && begin) {
		ret0 = 1;
	}

	daxie(a2, ret0);
	ret0 = 0;
	if (a2)
		strcat(result, "��");

	if (a1 != 0)
		begin = 1;
	if (a1 == 0 && a0 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a1, ret0);
	ret0 = 0;
	if (a1)
		strcat(result, "ʰ");

	if (a0 != 0)
		begin = 1;
	//if (a0 == 0 && begin) {
	//	ret0 = 1;
	//}
	daxie(a0, ret0);
	//if (a3||a2||a1||a0)
	//	strcat(result, "��");

	if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1 || a0)
		strcat(result, "Բ");



	//С������
	ret0 = 0;

	if (b1 != 0)
		begin = 1;
	if (b1 == 0 && b2 != 0 && begin) {
		ret0 = 1;
	}
	daxie(b1, ret0);
	ret0 = 0;
	if (b1)
		strcat(result, "��");

	if (b2 != 0)
		begin = 1;
	//if (b2 == 0 && begin) {
	//	ret0 = 1;
	//}	
	daxie(b2, ret0);
	ret0 = 0;
	if (b2)
		strcat(result, "��");

	//��Ԫ�� ֻ�����ж�Ϊ0����������������
	if (!(a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 ||
		a1 || a0 || b1 || b2))
		strcat(result, "��Բ");
	//����Զ�����������
	if (b2 == 0)
		strcat(result, "��");

	printf("%s\n", result);
	return 0;
}