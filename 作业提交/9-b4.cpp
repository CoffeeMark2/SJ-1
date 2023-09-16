/*2152988 计科 杨恺铭*/

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int i1 = 0, i2 = 0;//第一次选课or第二次选课
	friend class stu_list;
public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* 允许按需加入private数据成员和成员函数 */
	int n = 0;
public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */
	void sort();
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
char* tj_strcpy(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

	if (s1 == NULL) {
		return s1;
	}
	if (s2 == NULL) {
		*s1 = 0;
		return s1;
	}
	char* p1 = s1;
	const char* p2 = s2;

	while (*p2) {
		*p1++ = *p2++;
	}
	*p1 = 0;
	return s1;
}
int stu_list::read(const char* filename, const int append)
{
	if (append == 0) {
		n = 0;
	}
	ifstream in(filename, ios::in);
	if (!in.is_open()) {
		cerr << "文件["<<filename<< "]打开失败!" << endl;
		return -1;
	}
	//算法不太好
	while (in.peek() != EOF) {
		//当成buff来读，不用一行一行的读
		int no;
		char name[MAX_NAME_LEN];
		in >> no >> name;
		if (in.fail()) {
			//最后有endl无法从while那里退出
			//cerr << "读取错误" << endl;
			in.clear();
			in.close();
			return 0;
		}
		int i = 0;
		if (append) {
			for (i = 0; i < n; i++) {
				if (no == stu[i].stu_no) {
					stu[i].i2 = 1;
					break;
				}
			}
		}	
		if (append==0 || i == n) {
			stu[n].stu_no = no;
			tj_strcpy(stu[n].stu_name, name);
			if (append == 0) {
				stu[n].i1 = 1;
			}
			++n;
		}
	}
	if (append == 1) {
		sort();
	}
	in.close();
	return 0;
}
void stu_list::sort()
{
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (stu[j].stu_no > stu[j + 1].stu_no) {
				stu_info tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}

		}
	}
}
int stu_list::print(const char* prompt )
{
	cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
	cout << "===========================================================" << endl;
	cout << setiosflags(ios::left);
	for (int i = 0; i < n; ++i) {
		cout << setw(4) << i + 1;
		cout << ' ';
		cout << setw(7) << stu[i].stu_no;
		cout << ' ';
		cout << setw(MAX_NAME_LEN) << stu[i].stu_name;
		cout << ' ';
		
		if (stu[i].i1) {
			cout << setw(7) << "Y";
			if (stu[i].i2) {
				cout << "Y";
			}
			else {
				cout << "退课";
			}
		}
		else {
			cout << setw(7) << "/";
			cout << "补选";
		}
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 0;
}//打印当前读入的选课名单

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}