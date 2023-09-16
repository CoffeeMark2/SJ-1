/*2152988 计科 杨恺铭*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int  ret;
	int year ,month, week;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d%d", &year,&month);
		if (ret == 2 && (year >= 2000 && year <= 2030 &&
			month >= 1 && month <= 12))
			break;
		if (ret < 2)
			while(getchar()!='\n')
				;
		printf("输入非法，请重新输入\n"); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : "
			,year,month);
		ret = scanf("%d", &week);
		if (ret == 1 && (week >= 0 && week <= 6))
			break;
		if (ret < 1)
			while(getchar()!='\n')
				;
		printf("输入非法，请重新输入\n"); //确认一下，ret的值（即scanf的返回值）是什么含义？ 
	}

	printf("\n");
	printf("%d年%d月的月历为:\n",year,month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int daymax = 28;
	if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
		daymax += 3;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		daymax += 2;
	else
		daymax += leap;
	int count = daymax + week;//打印次数
	for (int i = 1; i <= count; i++) {
		if (i <= week)
			printf( "        ");
		else {
			printf("%4d" "    ",i-week);
		}
		if (i % 7 == 0)
			printf( "\n");
	}
	printf("\n");

	return 0;
}
