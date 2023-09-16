/*21529988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
int main()
{
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	printf("请输入[0-100亿)之间的数字:" "\n");
	scanf("%lf",&a);
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

	if (begin == 0)
		ret0 = 0;
	if (a9 != 0)
		begin = 1;
	//补丁 位置应该在哪？
	//什么顺序？为什么不能用级联？

	if (a9 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a9 == 0)
		ret0 = 1;

	switch (a9) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a9)
		printf("拾");

	if (begin == 0)
		ret0 = 0;
	if (a8 != 0)
		begin = 1;

	if (a8 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a8 == 0)
		ret0 = 1;

	switch (a8) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a9 || a8)
		printf("亿");


	//万
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a7 != 0)
		begin = 1;

	if (a7 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a7 == 0)
		ret0 = 1;
	switch (a7) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a7)
		printf("仟");

	if (begin == 0)
		ret0 = 0;
	if (a6 != 0)
		begin = 1;

	if (a6 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a6 == 0)
		ret0 = 1;

	switch (a6) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a6)
		printf("佰");


	if (begin == 0)
		ret0 = 0;
	if (a5 != 0)
		begin = 1;

	if (a5 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a5 == 0)
		ret0 = 1;

	switch (a5) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a5)
		printf("拾");

	if (begin == 0)
		ret0 = 0;
	if (a4 != 0)
		begin = 1;

	if (a4 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a4 == 0)
		ret0 = 1;

	switch (a4) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a7 || a6 || a5 || a4)
		printf("万");


	//个
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a3 != 0)
		begin = 1;

	if (a3 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a3 == 0)
		ret0 = 1;
	switch (a3) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a3)
		printf("仟");

	if (begin == 0)
		ret0 = 0;
	if (a2 != 0)
		begin = 1;

	if (a2 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a2 == 0)
		ret0 = 1;

	switch (a2) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a2)
		printf("佰");

	if (begin == 0)
		ret0 = 0;
	if (a1 != 0)
		begin = 1;

	if (a1 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a1 == 0)
		ret0 = 1;

	switch (a1) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (a1)
		printf("拾");

	if (begin == 0)
		ret0 = 0;
	if (a0 != 0)
		begin = 1;

	if (a0 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (a0 == 0)
		ret0 = 1;

	switch (a0) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	//if (a3||a2||a1||a0)
	//	printf("个");

	if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1 || a0)
		printf("圆");



	//小数部分
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (b1 != 0)
		begin = 1;

	if (b1 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (b1 == 0)
		ret0 = 1;

	switch (b1) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (b1)
		printf("角");

	if (begin == 0)
		ret0 = 0;
	if (b2 != 0)
		begin = 1;

	if (b2 != 0 && ret0) {
		ret0 = 0;
		printf("零");
	}
	else if (b2 == 0)
		ret0 = 1;

	switch (b2) {
		case 9:
			printf("玖");
			break;
		case 8:
			printf("捌");
			break;
		case 7:
			printf("柒");
			break;
		case 6:
			printf("陆");
			break;
		case 5:
			printf("伍");
			break;
		case 4:
			printf("肆");
			break;
		case 3:
			printf("叁");
			break;
		case 2:
			printf("贰");
			break;
		case 1:
			printf("壹");
			break;
		case 0:
			//printf("零");
			break;
		default:
			break;
	}
	if (b2)
		printf("分");

	//零元整 只有所有都为0才能输出，放在最后
	if (!(a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 ||
		a1 || a0 || b1 || b2))
		printf("零圆");
	//整永远在最后，最后输出
	if (b2 == 0)
		printf("整" "\n");

	return 0;
}
