/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int  ret, x;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x);
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		if (ret < 1)
			while(getchar()!='\n')
				;
		printf("�����д�[ret=%d x=%d],����������\n", ret, x); //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 
	}

	printf("ret=%d x=%d\n", ret, x);
	return 0;
}
