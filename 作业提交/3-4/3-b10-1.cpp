/*2152988 计科 杨恺铭*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int count = 0;
	for (int a1 = 1; a1 <= 5; a1++) {
		for (int a2 = 1; a2 <= 9; a2++) {
			if (a2 == a1)
				continue;
			for (int a3 = 1; a3 <= 9; a3++) {
				if (a3 == a1 || a3 == a2)
					continue;
				int shu1 = a1 * 100 + a2 * 10 + a3;


				for (int a4 = a1 + 1; a4 <= 9; a4++) {
					if (a4 == a1 || a4 == a2 || a4 == a3)
						continue;
					for (int a5 = 1; a5 <= 9; a5++) {
						if (a5 == a1 || a5 == a2
							|| a5 == a3 || a5 == a4)
							continue;
						for (int a6 = 1; a6 <= 9; a6++) {
							if (a6 == a1 || a6 == a2
								|| a6 == a3 || a6 == a4
								|| a6 == a5)
								continue;
							int shu2 = a4 * 100 + a5 * 10 + a6;


							for (int a7 = a4 + 1; a7 <= 9; a7++) {
								if (a7 == a1 || a7 == a2
									|| a7 == a3 || a7 == a4
									|| a7 == a5 || a7 == a6)
									continue;
								for (int a8 = 1; a8 <= 9; a8++) {
									if (a8 == a1 || a8 == a2
										|| a8 == a3 || a8 == a4
										|| a8 == a5 || a8 == a6
										|| a8 == a7)
										continue;
									for (int a9 = 1; a9 <= 9; a9++) {
										if (a9 == a1 || a9 == a2
											|| a9 == a3 || a9 == a4
											|| a9 == a5 || a9 == a6
											|| a9 == a7 || a9 == a8)
											continue;
										int shu3 = a7 * 100 + a8 * 10 + a9;
										int sum = shu1 + shu2 + shu3;

										if (1953 == sum) {
											count++;
											cout << "No." << setw(3) << count 
												<< " : " << shu1 << '+' << shu2
												<< '+' << shu3 << "=1953" << endl;

										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << "total=" << count << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}
//解决重复的数，确保后面的数大于前面的数即可 ，百位大于即可
//使用continue skip重复的数 
