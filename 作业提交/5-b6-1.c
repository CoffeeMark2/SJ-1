/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N  10
int cnt = 0;
int stack_a[N], stack_b[N], stack_c[N];//��¼����ջ
int top_a, top_b, top_c;//ջ��ָ�루ָ�����Ԫ�ص���һ����

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void operate(char src, char dst)
{
	if (src == 'A' && dst == 'B') {
		stack_b[top_b++] = stack_a[--top_a];
	}
	else if (src == 'A' && dst == 'C') {
		stack_c[top_c++] = stack_a[--top_a];

	}
	else if (src == 'B' && dst == 'A') {
		stack_a[top_a++] = stack_b[--top_b];

	}
	else if (src == 'B' && dst == 'C') {
		stack_c[top_c++] = stack_b[--top_b];

	}
	else if (src == 'C' && dst == 'A') {
		stack_a[top_a++] = stack_c[--top_c];

	}
	else if (src == 'C' && dst == 'B') {
		stack_b[top_b++] = stack_c[--top_c];

	}
	else
		printf( "operate error\n" );
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
  ***************************************************************************/
void output_stack(void) {
	printf( "A:");
	for (int i = 0; i < top_a; i++) {
		printf("%2d", stack_a[i]);
	}
	printf("%*s", (2 * (N - top_a)), "");
	//cout << setw(2 * (N - top_a)) << "";
	printf(" ");

	printf("B:");
	for (int i = 0; i < top_b; i++) {
		printf("%2d", stack_b[i]);
	}
	printf("%*s", (2 * (N - top_b)), "");
	printf(" ");

	printf("C:");
	for (int i = 0; i < top_c; i++) {
		printf("%2d", stack_c[i]);
	}
	printf("%*s", (2 * (N - top_c)), "");
	printf(" ");

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp);
	
	printf("��%4d ��(%2d): %c-->%c ",
		++cnt, n, src, dst);

	//cout << "��" << setw(4) << ++cnt
	//	<< " ��(" << setw(2) << n << "): "
	//	<< src << "-->" << dst << ' ';

	operate(src, dst);
	output_stack();
	printf("\n");

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int n;
	int ret;
	char src, dst, tmp;
	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-10)\n");
		ret = scanf("%d", &n);
		if (ret == 1 && (n >= 1 && n <= 10))
			break;
		if (ret < 1)
			while (getchar() != '\n')
				;		
	}
	while (getchar() != '\n')
		;

	while (1) {
		printf("��������ʼ��(A-C)\n");
		ret = scanf("%c", &src);
		if (src >= 'a' && src <= 'c')
			src -= 32;
		if (ret == 1 && (src >= 'A' && src <= 'C'))
			break;
		if (ret < 1)
			while (getchar() != '\n')
				;
	}
	while (getchar() != '\n')
		;

	while (1) {
		printf("������Ŀ����(A-C)\n");
		ret = scanf("%c", &dst);
		if (dst >= 'a' && dst <= 'c')
			dst -= 32;
		if (ret == 1 && (dst >= 'A' && dst <= 'C'))
			if (dst == src)
				printf("Ŀ����(%c)����"
					"����ʼ��(%c)��ͬ\n", dst, src);
			else
				break;
	}
	while (getchar() != '\n')
		;
	if (src == 'A') {
		for (int i = 0; i < n; i++) {
			stack_a[i] = n - i;
		}
		top_a = n;
	}
	else if (src == 'B') {
		for (int i = 0; i < n; i++) {
			stack_b[i] = n - i;
		}
		top_b = n;
	}
	else {
		for (int i = 0; i < n; i++) {
			stack_c[i] = n - i;
		}
		top_c = n;
	}

	printf("��ʼ:%16s", "");
	output_stack();
	printf("\n");

	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);
	return 0;
}