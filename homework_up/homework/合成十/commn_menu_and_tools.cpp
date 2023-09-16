/* 2153299 计拔 杨非凡 */

/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放菜单函数，要求显示各菜单项，读入正确的选项后返回、


	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、不允许定义静态全局变量（全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <string.h>
#include "cmd_console_tools.h"
#include "common_menu_and_tools.h"
using namespace std;

/***************************************************************************
  函数名称：common_menu
  功    能：要求显示各菜单项，读入正确的选项后返回
  输入参数：option
  返 回 值：option
  说    明：number_of_option是选项的个数
*possible_option是选项的可能字符
*content数组中是选的具体内容
***************************************************************************/
char common_menu(const int number_of_option,const char *possible_option,const char *content[])
{

	char option;
	bool loop = 1;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < number_of_option; i++) {
		cout << *(possible_option + i) << '.' << *(content + i) << endl;
	}
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
	for (;loop;) {
		option = _getch();
		for (int i = 0; i < number_of_option; i++) {
			if (option == *(possible_option + i)) { 
				loop = 0;
				break;
			}
		}
	}
	return option;//输入的参数返回给main函数

}


/***************************************************************************
函数名称：pause_end
功    能：每个选项结束时进行暂停，并要求输入end才能继续
输入参数：
返 回 值：
说    明：
***************************************************************************/
void common_pause_end()
{
	int x, y;
	char pause_end[30];
	cct_getxy(x, y);
	cct_showstr(0, y + 1, "本小题结束，请输入End继续...");
	cct_getxy(x, y);
	for (;;) {
		cin.getline(pause_end, 30);

		tj_strupr(pause_end);//判断是否输入了end（不区分大小写字母）
		if (!tj_strncmp("END", pause_end, 3))//判断是否输入了end（不区分大小写字母）
			break;
		else {
			cout << "输入错误，请重新输入";
			cct_showch(x, y, ' ', 0, 7, 30);
			cct_gotoxy(x, y);
		}
	}
}



//下面是自己写的字符串函数tj_***（指针形式实现），其中包括了对NULL的特殊处理

/***************************************************************************
  函数名称：tj_strlen
  功    能：判断一个字符串的长度
  输入参数：
  返 回 值：串的长度
  说    明：NULL返回值为0
***************************************************************************/

int tj_strlen(const char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0;
	if (str == NULL)
		return 0;

	for (; *str != '\0'; str++) {
		a++;
	}
	return a;
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将s2追加到s1后面，包含\0
  输入参数：
  返 回 值：新的S1
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* p = s1;
	if (s2 == NULL || s1 == NULL) {
		return s1;
	}

	for (s1 = s1 + tj_strlen(s1); *s2 != '\0'; s2++, s1++) {
		*s1 = *s2;
	}
	*s1 = '\0';
	s1 = p;
	return s1;


}

/***************************************************************************
  函数名称：tj_strncat
  功    能：将s2的前len个字符追加到s1后面，并添加\0（若s2的长度小于len，则追加s2即可，包含\0）
  输入参数：
  返 回 值：新的s1
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	char* p = s1;
	if (s2 == NULL || s1 == NULL) {
		return s1;
	}
	if (len >= tj_strlen(s2)) {
		tj_strcat(s1, s2);
	}
	else {
		for (s1 = s1 + tj_strlen(s1); i < len; s1++, s2++, i++) {
			*s1 = *s2;
		}
		*s1 = '\0';
		s1 = p;
	}
	return s1;

}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：s2复制到s1中，覆盖原来内容，复制时包含\0
  输入参数：
  返 回 值：
  说    明：新的s1
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* p = s1;
	if (s1 == NULL) {
		return s1;
	}
	else if (s2 == NULL) {
		*s1 = '\0';
		return s1;
	}
	else {
		for (; *s2 != '\0'; s1++, s2++) {
			*s1 = *s2;
		}
		*s1 = '\0';
		s1 = p;
		return s1;
	}
}
/***************************************************************************
  函数名称：tj_strncmp
  功    能：将s2的前len个字符复制到s1中，复制不含\0，若s2的长度小于len，则复制s2即可，不含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
	char* p = s1;
	if (s1 == NULL) {
		return s1;
	}
	else if (s2 == NULL) {
		return s1;
	}
	else {
		for (; *s2 != '\0' && s1 - p < len; s1++, s2++) {
			*s1 = *s2;
		}
		s1 = p;
		return s1;
	}
}
/***************************************************************************
  函数名称：tj_strcmp
  功    能：比价字符串s1和s2的大小，字母要区分大小写
  输入参数：
  返 回 值：相等为0；不相等为第一个不相等字符ASCII码的相差值
  说    明：有NULL返回-1或1
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0;
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL) {
		return 1;
	}
	else {
		for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++) {
			if (*s1 != *s2) {
				a = *s1 - *s2;
				break;
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：比价字符串s1和s2的大小，字母不区分大小写
  输入参数：
  返 回 值：返回第一个不相等的位置的ascii的差值（若不相等的为两个字母，统一转为小写后比较；若为大写字母和其它字符，将大写字母转为小写字母后比较）
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0, b1 = 0, b2 = 0;
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL) {
		return 1;
	}
	else {
		for (; (*s1 != '\0') || (*s2 != '\0'); s1++, s2++) {
			b1 = 0;
			b2 = 0;
			if (*s1 >= 65 && *s1 <= 90) {
				b1 = 32;
			}
			if (*s2 >= 65 && *s2 <= 90) {
				b2 = 32;
			}
			if ((*s1 + b1) != (*s2 + b2)) {
				a = (*s1 + b1) - (*s2 + b2);
				break;
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较s1和s2的前len个字符，区分大小写，若len大于较短的串的长度，则比较到较短的串的\0
  输入参数：
  返 回 值：第一个不同的字符的ascii差值
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0, i = 0;
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL) {
		return 1;
	}
	else {
		for (; ((*s1 != '\0') || (*s2 != '\0')) && (i < len); s1++, s2++, i++) {
			if (*s1 != *s2) {
				a = *s1 - *s2;
				break;
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较s1和s2的前len个字符，不区分大小写，若len大于较短的串的长度，则比较到较短的串的\0
  输入参数：
  返 回 值：第一个不同的字符的ascii差值（若不相等的为两个字母，统一转为小写后比较；若为大写字母和其它字符，将大写字母转为小写字母后比较）
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0, a = 0, b1 = 0, b2 = 0;
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL) {
		return 1;
	}
	else {
		for (; ((*s1 != '\0') || (*s2 != '\0')) && (i < len); s1++, s2++, i++) {
			b1 = 0;
			b2 = 0;
			if (*s1 >= 65 && *s1 <= 90) {
				b1 = 32;
			}
			if (*s2 >= 65 && *s2 <= 90) {
				b2 = 32;
			}
			if ((*s1 + b1) != (*s2 + b2)) {
				a = (*s1 + b1) - (*s2 + b2);
				break;
			}

		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strupr
  功    能：将一个字符串中的所有小写字母转为大写字母
  输入参数：
  返 回 值：转换后的串
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* p = str;
	if (str == NULL)
		return str;
	else {
		for (; *str != '\0'; str++) {
			if (*str >= 97 && *str <= 122)
				*str = *str - 32;
		}
		str = p;
		return str;
	}
}

/***************************************************************************
  函数名称：tj_strlwr
  功    能：将一个字符串中的所有大写字母转为小写字母
  输入参数：
  返 回 值：转换后的串
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char* p = str;
	if (str == NULL)
		return str;
	else {
		for (; *str != '\0'; str++) {
			if (*str >= 65 && *str <= 90)
				*str = *str + 32;
		}
		str = p;
		return str;
	}
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：在字符串str中寻找ch字符第一次出现的位置，从左到右
  输入参数：
  返 回 值：若找到，返回位置1-n（位置从1开始）；找不到返回0
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0, i = 0;
	const char* p = str;
	if (str == NULL)
		return 0;
	else {
		for (; i < tj_strlen(p); str++, i++) {
			if (*str == ch) {
				a = i + 1;
				break;
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：在字符串str中寻找substr字符串第一次出现的位置，从左到右
  输入参数：
  返 回 值：若找到，返回位置1-n（位置从1开始）；找不到返回0
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0;
	const char* i = str, * j = substr, * k;
	if (str == NULL || substr == NULL)
		return 0;
	else {
		for (; str - i < tj_strlen(i); str++) {
			if ((*str == *j) && (str - i + tj_strlen(j) <= tj_strlen(i))) {
				k = str;
				for (substr = j; substr - j < tj_strlen(j); substr++, k++) {
					if (*k != *substr) {
						break;
					}
					if ((substr - j == tj_strlen(j) - 1) && (a == 0)) {
						a = str - i + 1;
					}
				}
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strrchr
  功    能：在字符串str中寻找ch字符第一次出现的位置，从右到左
  输入参数：
  返 回 值：若找到，返回位置1-n（位置从1开始）；找不到返回0
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0, i = 0;
	const char* p = str;
	if (str == NULL)
		return 0;
	else {
		for (; i < tj_strlen(p); str++, i++) {
			if (*str == ch) {
				a = i + 1;
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strrstr
  功    能：在字符串str中寻找substr字符串第一次出现的位置，从右到左
  输入参数：
  返 回 值：若找到，返回位置1-n（位置从1开始）；找不到返回0
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int a = 0;
	const char* i = str, * j = substr, * k;
	if (str == NULL || substr == NULL)
		return 0;
	else {
		for (; str - i < tj_strlen(i); str++) {
			if ((*str == *j) && (str - i + tj_strlen(j) <= tj_strlen(i))) {
				k = str;
				for (substr = j; substr - j < tj_strlen(j); substr++, k++) {
					if (*k != *substr) {
						break;
					}
					if (substr - j == tj_strlen(j) - 1) {
						a = str - i + 1;
					}
				}
			}
		}
		return a;
	}
}

/***************************************************************************
  函数名称：tj_strrev
  功    能：字符串反转
  输入参数：
  返 回 值：反转后的串
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	char a;
	int i = 0;
	char* p = str;
	if (str == NULL) {
		return str;
	}
	else {
		for (; str + 1 <= p + tj_strlen(p) / 2; str++) {
			a = *str;
			*str = *(p + tj_strlen(p) - 1 - (str - p));
			*(p + tj_strlen(p) - 1 - (str - p)) = a;
		}
		str = p;
		return str;
	}
}

//要注意对NULL的特殊处理