/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define M 1000
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	int a, num = 0;
	int array[M];
	printf( "������ɼ������1000��������-1����" "\n");
	scanf("%d", &a);
	while (a >= 0 && num < M) {
		array[num++] = a;
		scanf("%d", &a);
	}
	if (0 == num) {
		printf( "����Ч����" "\n");
		return -1;
	}
	printf( "���������Ϊ:" "\n");
	int i;
	for (i = 0; i < num; i++) {
		printf("%d ",array[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	if ((i + 1) % 10 != 1) {
		printf("\n");
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] < array[j + 1]) {
				int t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}

	}

	printf( "�����������Ķ�Ӧ��ϵΪ:" "\n");
	int grade = array[0], cnt = 0;
	for (int i = 0; i < num; i++) {
		if (grade != array[i]) {
			printf("%d %d\n",grade,cnt);
			grade = array[i];
			cnt = 0;
		}
		cnt++;
	}
	printf("%d %d\n", grade, cnt);

	return 0;
}