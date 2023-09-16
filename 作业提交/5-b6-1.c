/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N  10
int cnt = 0;
int stack_a[N], stack_b[N], stack_c[N];//记录塔的栈
int top_a, top_b, top_c;//栈顶指针（指向最后元素的下一个）

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
		return;
	hanoi(n - 1, src, dst, tmp);
	
	printf("第%4d 步(%2d): %c-->%c ",
		++cnt, n, src, dst);

	//cout << "第" << setw(4) << ++cnt
	//	<< " 步(" << setw(2) << n << "): "
	//	<< src << "-->" << dst << ' ';

	operate(src, dst);
	output_stack();
	printf("\n");

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
			2、处理输入错误时，允许使用循环
			3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int n;
	int ret;
	char src, dst, tmp;
	while (1) {
		printf("请输入汉诺塔的层数(1-10)\n");
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
		printf("请输入起始柱(A-C)\n");
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
		printf("请输入目标柱(A-C)\n");
		ret = scanf("%c", &dst);
		if (dst >= 'a' && dst <= 'c')
			dst -= 32;
		if (ret == 1 && (dst >= 'A' && dst <= 'C'))
			if (dst == src)
				printf("目标柱(%c)不能"
					"与起始柱(%c)相同\n", dst, src);
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

	printf("初始:%16s", "");
	output_stack();
	printf("\n");

	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);
	return 0;
}