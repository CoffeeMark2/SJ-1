/*2152988 �ƿ� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ��˵�����
  ��    �ܣ�
  �����������
  �� �� ֵ���˵���ť
  ˵    ����ʹ�ò�������ѡ�������
***************************************************************************/
int menu(void)
{
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n"
		"2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n"
		"3.�ü�ͷ�������������ң��߽�ֹͣ\n"
		"4.�ü�ͷ�������������ң��߽����\n"
		"5.�ü�ͷ��������������(�߽�ֹͣ����ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		"6.�ü�ͷ��������������(�߽���ƣ���ʾ��дHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		"0.�˳�\n"
		"[��ѡ��0 - 6]");
	int option = _getch() - '0';
	return option;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�ʹ��ijkl���ƹ���ƶ�
  ���������if_rotate
  �� �� ֵ��void
  ˵    ��������Ϊ�棬����ת������ͷ�ͻ�ͣס
***************************************************************************/
void move_by_ijkl(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int move = _getch();
		//printf( move << '\b');
		if (move == 'l' || move == 'l' - 32) {
			if (x >= MAX_X) {
				if (if_rotate) {
					x = 1;
					//if (y != MAX_Y)
					//	++y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, ++x, y);
			}
		}
		else if (move == 'j' || move == 'j' - 32) {
			if (x <= 1) {
				if (if_rotate) {
					x = MAX_X;
					//if (y != 1)
					//	--y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, --x, y);
			}
		}
		else if (move == 'i' || move == 'i' - 32) {
			if (y <= 1) {
				if (if_rotate) {
					y = MAX_Y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, --y);
			}
		}
		else if (move == 'k' || move == 'k' - 32) {
			if (y >= MAX_Y) {
				if (if_rotate) {
					y = 1;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, ++y);
			}
		}
		else if (move == ' ') {
			printf( " \b");
		}
		else if (move == 'q' || move == 'q' - 32) {
			break;
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�ʹ��ijkl���ƹ���ƶ�
  ���������if_rotate
  �� �� ֵ��void
  ˵    ��������Ϊ�棬����ת������ͷ�ͻ�ͣס
***************************************************************************/
void move_by_arrow(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int a = _getch();
		if (a == 224) {
			int move = _getch();
			//printf( move );
			if (move == 77) {
				if (x >= MAX_X) {
					if (if_rotate) {
						x = 1;
						//if (y != MAX_Y)
						//	++y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, ++x, y);
				}
			}
			else if (move == 75) {
				if (x <= 1) {
					if (if_rotate) {
						x = MAX_X;
						//if (y != 1)
						//	--y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, --x, y);
				}
			}
			else if (move == 72) {
				if (y <= 1) {
					if (if_rotate) {
						y = MAX_Y;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, x, --y);
				}
			}
			else if (move == 80) {
				if (y >= MAX_Y) {
					if (if_rotate) {
						y = 1;
						gotoxy(hout, x, y);
					}
				}
				else {
					gotoxy(hout, x, ++y);
				}
			}

		}
		else {
			if (a == ' ') {
				printf( " \b");
			}
			else if (a == 'q' || a == 'q' - 32) {
				break;
			}
		}



	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�ʹ��ijkl���ƹ���ƶ�
  ���������if_rotate
  �� �� ֵ��void
  ˵    ��������Ϊ�棬����ת������ͷ�ͻ�ͣס
***************************************************************************/
void move_by_ijkl1(int if_rotate)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	int x = MAX_X / 2 + 1, y = MAX_Y / 2 + 1;
	gotoxy(hout, MAX_X / 2 + 1, MAX_Y / 2 + 1);
	while (1) {
		int move = _getch();
		if (move == 224) {
			_getch();
			continue;
		}
		//printf( move << '\b');
		if (move == 'l' || move == 'l' - 32) {
			if (x >= MAX_X) {
				if (if_rotate) {
					x = 1;
					//if (y != MAX_Y)
					//	++y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, ++x, y);
			}
		}
		else if (move == 'j' || move == 'j' - 32) {
			if (x <= 1) {
				if (if_rotate) {
					x = MAX_X;
					//if (y != 1)
					//	--y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, --x, y);
			}
		}
		else if (move == 'i' || move == 'i' - 32) {
			if (y <= 1) {
				if (if_rotate) {
					y = MAX_Y;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, --y);
			}
		}
		else if (move == 'k' || move == 'k' - 32) {
			if (y >= MAX_Y) {
				if (if_rotate) {
					y = 1;
					gotoxy(hout, x, y);
				}
			}
			else {
				gotoxy(hout, x, ++y);
			}
		}
		else if (move == ' ') {
			printf( " \b");
		}
		else if (move == 'q' || move == 'q' - 32) {
			break;
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	while (1) {
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
		int option = menu();
		if (option >= 1 && option <= 6) {//����ó�Ҫ����
			cls(hout);
			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);
			if (1 == option)
				move_by_ijkl(0);
			else if (2 == option)
				move_by_ijkl(1);
			else if (3 == option)
				move_by_arrow(0);
			else if (4 == option)
				move_by_arrow(1);
			else if (5 == option)
				move_by_ijkl1(0);
			else if (6 == option)
				move_by_ijkl1(1);
			//��ͣ
			//getchar();

			//�˵����⣬���ز˵�
			gotoxy(hout, 0, 23);
			printf( "��Ϸ���������س������ز˵�.");



			//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
			while (_getch() != 13)
				;

			//getchar();
		}
		else if (option == 0)
			break;

	}



	return 0;
}
//ʹ�ü�ͷ���ƹ���ƶ������¼�ͷ��ť��ʵ���϶��������� 224�Ͷ�Ӧ�ķ�����Ƽ���������պ��ǡ�K����ASCII��
// ��һ�ζ���244���������κ�������������һ��ѭ������'K'�����������ƶ�
// 
//��������п���<20������α�����������ͬ����ʱ����ͬһ���ط����������ַ������Կ�����<20.