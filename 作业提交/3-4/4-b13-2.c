/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cnt = 0;
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

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
	printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
	/*cout << setw(5) << ++cnt << ':'
		<< setw(3) << n << "# "
		<< src << "-->" << dst << endl;*/
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
		printf("请输入汉诺塔的层数(1-16)\n");
		ret = scanf("%d", &n);
		if (ret == 1 && (n >= 1 && n <= 16))
			break;
		if (ret < 1)
			while (getchar() != '\n')
				;
		while (getchar() != '\n')
		//printf("输入非法，请重新输入\n"); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}
	
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
		//printf("输入非法，请重新输入\n"); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
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
					"与起始柱(%c)相同\n",dst,src);
			else
				break; 
		while (getchar() != '\n')
				;
		//printf("输入非法，请重新输入\n"); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}
	
	printf( "移动步骤为:\n");
	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);

}
