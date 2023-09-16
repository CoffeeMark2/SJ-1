/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
using namespace std;

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
	cout << setw(2) << n << "# " 
		<< src << "-->" << dst << endl;
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
	char src, dst,tmp;
	while (1) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (n >= 1 && n <= 10) {
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (src >= 'a' && src <= 'c')
			src -= 32;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if ((src >= 'A' && src <= 'C')){
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	while (1) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		dst = (dst >= 'a' && dst <= 'c') ? dst - 32 : dst;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if ((dst >= 'A' && dst <= 'C')) {
			if (dst == src)
				cout << "目标柱(" << dst
				<< ")不能与起始柱(" << src << ")相同\n";
			else
				break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "移动步骤为:" << endl;
	tmp = 'B' * 3 - src - dst;
	hanoi(n, src, tmp, dst);

}