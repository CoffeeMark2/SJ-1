/*2152988 ¼Æ¿Æ ÑîâýÃú*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, b1, b2;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:" << endl;
	cin >> a;
	a1 = int(a / 10) % 10;
	a2 = int(a / 100) % 10;
	a3 = int(a / 1000) % 10;
	a4 = int(a / 10000) % 10;
	a5 = int(a / 100000) % 10;
	a6 = int(a / 1000000) % 10;
	a7 = int(a / 10000000) % 10;
	a8 = int(a / 100000000) % 10;
	a9 = int(a / 1000000000) % 10;
	a0 = int(a - a9 * pow(10, 9)) % 10;
	b = a - a9 * pow(10, 9) - a8 * pow(10, 8) - a7 * pow(10, 7)
		- a6 * pow(10, 6) - a5 * pow(10, 5) - a4 * pow(10, 4)
		- a3 * pow(10, 3) - a2 * pow(10, 2) - a1 * pow(10, 1)
		- a0 + 0.001;
	b1 = int(b * 10) % 10;
	b2 = int(b * 100) % 10;

	cout << "´óÐ´½á¹ûÊÇ:" << endl;

	int ret0 = 0;
	//ÔÚ·ÇÁãÇ°Êä³öÁã£¬½â¾ö700ºóÁ½¸öÁã²»Êä³öµÄÎÊÌâ
	int begin = 0;
	//½â¾öÀýÈç700Êä³öÎªÁãÆâ°ÛµÄÎÊÌâ


	//ÒÔÒÚ¡¢Íò¡¢¸öÎªÒ»×é½øÐÐÊä³ö£¨¾ßÌåÔ­Òò¡¤¡¤¡¤ÕýÔÚ²¹³ä£©
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a9 != 0)
		begin = 1;
	//²¹¶¡ Î»ÖÃÓ¦¸ÃÔÚÄÄ£¿
	//Ê²Ã´Ë³Ðò£¿ÎªÊ²Ã´²»ÄÜÓÃ¼¶Áª£¿

	if (a9 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a9 == 0)
		ret0 = 1;

	switch (a9) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a9)
		cout << "Ê°";

	if (begin == 0)
		ret0 = 0;
	if (a8 != 0)
		begin = 1;

	if (a8 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a8 == 0)
		ret0 = 1;

	switch (a8) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a9 || a8)
		cout << "ÒÚ";


	//Íò
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a7 != 0)
		begin = 1;

	if (a7 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a7 == 0)
		ret0 = 1;
	switch (a7) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a7)
		cout << "Çª";

	if (begin == 0)
		ret0 = 0;
	if (a6 != 0)
		begin = 1;

	if (a6 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a6 == 0)
		ret0 = 1;

	switch (a6) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a6)
		cout << "°Û";


	if (begin == 0)
		ret0 = 0;
	if (a5 != 0)
		begin = 1;

	if (a5 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a5 == 0)
		ret0 = 1;

	switch (a5) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a5)
		cout << "Ê°";

	if (begin == 0)
		ret0 = 0;
	if (a4 != 0)
		begin = 1;

	if (a4 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a4 == 0)
		ret0 = 1;

	switch (a4) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a7 || a6 || a5 || a4)
		cout << "Íò";


	//¸ö
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (a3 != 0)
		begin = 1;

	if (a3 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a3 == 0)
		ret0 = 1;
	switch (a3) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a3)
		cout << "Çª";

	if (begin == 0)
		ret0 = 0;
	if (a2 != 0)
		begin = 1;

	if (a2 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a2 == 0)
		ret0 = 1;

	switch (a2) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a2)
		cout << "°Û";

	if (begin == 0)
		ret0 = 0;
	if (a1 != 0)
		begin = 1;

	if (a1 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a1 == 0)
		ret0 = 1;

	switch (a1) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (a1)
		cout << "Ê°";

	if (begin == 0)
		ret0 = 0;
	if (a0 != 0)
		begin = 1;

	if (a0 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (a0 == 0)
		ret0 = 1;

	switch (a0) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	//if (a3||a2||a1||a0)
	//	cout << "¸ö";

	if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1 || a0)
		cout << "Ô²";



	//Ð¡Êý²¿·Ö
	ret0 = 0;

	if (begin == 0)
		ret0 = 0;
	if (b1 != 0)
		begin = 1;

	if (b1 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (b1 == 0)
		ret0 = 1;

	switch (b1) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (b1)
		cout << "½Ç";

	if (begin == 0)
		ret0 = 0;
	if (b2 != 0)
		begin = 1;

	if (b2 != 0 && ret0) {
		ret0 = 0;
		cout << "Áã";
	}
	else if (b2 == 0)
		ret0 = 1;

	switch (b2) {
		case 9:
			cout << "¾Á";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 6:
			cout << "Â½";
			break;
		case 5:
			cout << "Îé";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 3:
			cout << "Èþ";
			break;
		case 2:
			cout << "·¡";
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 0:
			//cout << "Áã";
			break;
		default:
			break;
	}
	if (b2)
		cout << "·Ö";

	//ÁãÔªÕû Ö»ÓÐËùÓÐ¶¼Îª0²ÅÄÜÊä³ö£¬·ÅÔÚ×îºó
	if (!(a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 ||
		a1 || a0 || b1 || b2))
		cout << "ÁãÔ²";
	//ÕûÓÀÔ¶ÔÚ×îºó£¬×îºóÊä³ö
	if (b2 == 0)
		cout << "Õû" << endl;

	return 0;
}

