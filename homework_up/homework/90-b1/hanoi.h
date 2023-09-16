/* 2152988 ������ �ƿ� */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
#define COLOR_BLACK		0	//��
#define COLOR_BLUE		1	//��
#define COLOR_GREEN		2	//��
#define COLOR_CYAN		3	//��
#define COLOR_RED		4	//��
#define COLOR_PINK		5	//��
#define COLOR_YELLOW	6	//��
#define COLOR_WHITE		7	//��
#define COLOR_HBLACK	8	//����
#define COLOR_HBLUE		9	//����
#define COLOR_HGREEN	10	//����
#define COLOR_HCYAN		11	//����
#define COLOR_HRED		12	//����
#define COLOR_HPINK		13	//����
#define COLOR_HYELLOW	14	//����
#define COLOR_HWHITE	15	//����

const int N = 10;//��ŵ��������
const int N_STACK = 3;//��ŵ����������
const int INITX = 0, INITY = 15;
//��ֱ��ӡ��ŵ��λ�ã��ӷָ��߿�ʼ��
const int PRT_X = 10, PRT_Y = 12, PRT_LEN = 25;//�����ַ���ӡ��ŵ��λ�ã����ף�
const int SLEEP = 1000;//��ʱ
const int SETX = 1, SETY = 13;//αͼ�κ�ŵ����ӡλ�ã����ף�
const int LENGTH = 23, HEIGHT = 12, GAP = 9;//αͼ�κ�ŵ���������ߣ����
const char CH = '*';        //�ַ�Ϊ*(ע�⣺����ǿո���ǰ��ɫ�޷���ʾ)

const int SET_COL_A = SETX + LENGTH / 2;//����A��x����


void to_be_continued(const char* prompt, const int X = 0, const int Y = 38);
void input(int* pn, char* psrc, char* pdst, char* ptmp, int flag_speed=0);
int menu(void);
void prt_column(int color = COLOR_HWHITE, int SETX = 1, int SETY = 13);
void prt_init_column(char src, int n, int SETX = 1, int SETY = 13);
void stack_init(char src, int n);
void stack_clear(void);
void prt_move(const char src, const char dst, const int n, int SETX = 1, int SETY = 13,int flag_game=0);
void prt_init_stack(int PRT_X, int PRT_Y);
void prt_stack_verticle(int PRT_X, int PRT_Y);
void prt_stack(void);
void operate(char src, char dst);
void hanoi(int n, char src, char tmp, char dst, int PRT_X, int PRT_Y, int option);
void game(int PRT_X, int PRT_Y,char src,char dst,int n);
void prt_title(char src, char dst, int n);
void pause(void);