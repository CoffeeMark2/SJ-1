/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#define N  10

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖";
char result[256] = ""; 
/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：int num,int flag_of_zero
  返 回 值：void
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int main()
{
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	printf("请输入[0-100亿)之间的数字:" "\n");
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

	printf("大写结果是:" "\n");

	int ret0 = 0;
	//在非零前输出零，解决700后两个零不输出的问题
	int begin = 0;
	//解决例如700输出为零柒佰的问题


	//以亿、万、个为一组进行输出（具体原因···正在补充）
	ret0 = 0;

	//if (begin == 0)
	//	ret0 = 0;
	if (a9 != 0)
		begin = 1;
	//补丁 位置应该在哪？
	//什么顺序？为什么不能用级联？

	if (a9 == 0 && a8 != 0 && begin) {
		ret0 = 1;
	}

	daxie(a9, ret0);
	ret0 = 0;
	if (a9)
		strcat(result, "拾");

	if (a8 != 0)
		begin = 1;
	//if (a8 == 0 && begin) {
	//	ret0 = 1;
	//}

	daxie(a8, ret0);
	ret0 = 0;
	if (a9 || a8)
		strcat(result, "亿");

	//万
	ret0 = 0;

	if (a7 != 0)
		begin = 1;
	if (a7 == 0 && a6 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a7, ret0);
	ret0 = 0;
	if (a7)
		strcat(result, "仟");

	if (a6 != 0)
		begin = 1;
	if (a6 == 0 && a5 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a6, ret0);
	ret0 = 0;

	if (a6)
		strcat(result, "佰");


	if (a5 != 0)
		begin = 1;
	if (a5 == 0 && a4 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a5, ret0);
	ret0 = 0;

	if (a5)
		strcat(result, "拾");

	if (a4 != 0)
		begin = 1;
	//if (a4 == 0 && begin) {
	//	ret0 = 1;
	//}
	daxie(a4, ret0);
	ret0 = 0;
	if (a7 || a6 || a5 || a4)
		strcat(result, "万");


	//个

	if (a3 != 0)
		begin = 1;
	if (a3 == 0 && a2 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a3, ret0);
	ret0 = 0;
	if (a3)
		strcat(result, "仟");

	if (a2 != 0)
		begin = 1;
	if (a2 == 0 && a1 != 0 && begin) {
		ret0 = 1;
	}

	daxie(a2, ret0);
	ret0 = 0;
	if (a2)
		strcat(result, "佰");

	if (a1 != 0)
		begin = 1;
	if (a1 == 0 && a0 != 0 && begin) {
		ret0 = 1;
	}
	daxie(a1, ret0);
	ret0 = 0;
	if (a1)
		strcat(result, "拾");

	if (a0 != 0)
		begin = 1;
	//if (a0 == 0 && begin) {
	//	ret0 = 1;
	//}
	daxie(a0, ret0);
	//if (a3||a2||a1||a0)
	//	strcat(result, "个");

	if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1 || a0)
		strcat(result, "圆");



	//小数部分
	ret0 = 0;

	if (b1 != 0)
		begin = 1;
	if (b1 == 0 && b2 != 0 && begin) {
		ret0 = 1;
	}
	daxie(b1, ret0);
	ret0 = 0;
	if (b1)
		strcat(result, "角");

	if (b2 != 0)
		begin = 1;
	//if (b2 == 0 && begin) {
	//	ret0 = 1;
	//}	
	daxie(b2, ret0);
	ret0 = 0;
	if (b2)
		strcat(result, "分");

	//零元整 只有所有都为0才能输出，放在最后
	if (!(a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 ||
		a1 || a0 || b1 || b2))
		strcat(result, "零圆");
	//整永远在最后，最后输出
	if (b2 == 0)
		strcat(result, "整");

	printf("%s\n", result);
	return 0;
}