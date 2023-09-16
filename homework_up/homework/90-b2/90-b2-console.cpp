/* 2152988 ������ �ƿ� */
#include <iostream>
#include <cstring>
#include <iomanip>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

const int FONT_HEIGHT = 30, FONT_WIDTH = 30;
//���̱���ɫ��ǰ��ɫ
const int BG = COLOR_HBLACK, FG = 0;

//��Ϸ��Ϣ��ӡλ�ü�����
const int OTHER_X = BOARDER_X + 4 + 4 * (LINE_MAX - 1) + 4,
OTHER_Y = BOARDER_Y;
const int SCORE_LEN = 5;
const int NEW_X = OTHER_X, NEW_Y = OTHER_Y + 4, NEW_LEN = 3;

const int PER_LEN = 12, PER_H = COLOR_MAX + 1,
PER_X = OTHER_X, PER_Y = OTHER_Y + 8;



//�������ڴ�С
void change_boarder(const game& G,int& option,
	int& line,int& row,int& buff_r,int& buff_l)
{
	int row_n = 6 + G.row + G.row - 1;
	if (option == 4) {
		row_n -= G.row - 1;
	}
	int line_n = 35;
	if (option == 6|| option==7) {
		line_n = 70;
	}
	cct_getconsoleborder( line, row, buff_l, buff_r);
	cct_setfontsize("������", FONT_HEIGHT);
	cct_setconsoleborder(line_n+5, row_n+3,  line_n+5, row_n+3);
	cct_gotoxy(0, 0);
	cout << "��Ļ��" << row_n << "��" << line_n << "��" << "���Ҽ��˳���" << endl;
}

void prt_boarder_opt4(game& G)
{
	const int X = 0, Y = 1,POINT_X=X+2, POINT_Y=Y+1;
	const int BG = COLOR_HBLACK, FG = 0;
	int row_n = 6 + G.row;
	cct_setfontsize("������", FONT_HEIGHT);
	cct_setcolor(BG, FG);

	cct_gotoxy(X, Y);
	cout << "�X";
	for (int j = 0; j < G.line; j++) {
		cout << "�T";
	}
	cout << "�[";
	
	for (int i = 0; i < G.row; i++) {
		cct_showstr(X, Y + i + 1, "�U", BG, FG);
		cct_showstr(X + 2, Y + i + 1, "  ", BG, FG, G.line);
		cct_showstr(X+2+G.line*2, Y + i + 1, "�U", BG, FG);

	}

	cct_gotoxy(X, Y+1+G.row);
	cout << "�^";
	for (int j = 0; j < G.line; j++) {
		cout << "�T";
	}
	cout << "�a";

	for (int y = 0; y < G.row; y++) {
		for (int x = 0; x < G.line; x++) {
			if (G.board[y][x] != 0) {
				cct_showstr(POINT_X + x *2, POINT_Y + y,
					"��",  G.board[y][x],FG);
			}
		}
	}

	cct_setcolor();
}

//��ӡ��������
void prt_other_init(game& G)
{
	cct_setcolor(BG, FG);
	//score
	cct_gotoxy(OTHER_X, OTHER_Y);
	cout << "�X";
	for (int j = 0; j < SCORE_LEN; j++) {
		cout << "�T";
	}
	cout << "�[";
	cct_showstr(OTHER_X, OTHER_Y + 1, "�U", BG, FG);
	cct_showstr(OTHER_X + 2, OTHER_Y + 1, "  ", BG, FG, SCORE_LEN);
	cct_showstr(OTHER_X + 2, OTHER_Y + 1, "�÷֣�0", BG, FG);
	cct_showstr(OTHER_X + 2 + SCORE_LEN * 2, OTHER_Y + 1, "�U", BG, FG);

	cct_gotoxy(OTHER_X, OTHER_Y + 2);
	cout << "�^";
	for (int j = 0; j < SCORE_LEN; j++) {
		cout << "�T";
	}
	cout << "�a";

	//new-ball
	const int NEW_X = OTHER_X, NEW_Y = OTHER_Y + 4, NEW_LEN = 3;
	cct_gotoxy(NEW_X, NEW_Y);
	cout << "�X";
	for (int j = 0; j < NEW_LEN; j++) {
		if (j == 0)
			cout << "�T";
		else {
			cout << "�j�T";
		}
	}
	cout << "�[";
	cct_showstr(NEW_X, NEW_Y + 1, "�U", BG, FG);
	cct_showstr(NEW_X + 2, NEW_Y + 1, "  �U", BG, FG, NEW_LEN);
	cct_gotoxy(NEW_X, NEW_Y + 2);
	cout << "�^";
	for (int j = 0; j < NEW_LEN; j++) {
		if (j == 0)
			cout << "�T";
		else {
			cout << "�m�T";
		}
	}
	cout << "�a";
	//percent
	const int PER_LEN = 12, PER_H = COLOR_MAX + 1,
		PER_X=OTHER_X,PER_Y=OTHER_Y+8;
	cct_gotoxy(PER_X, PER_Y);
	cout << "�X";
	for (int j = 0; j < PER_LEN; j++) {
		cout << "�T";
	}
	cout << "�[";
	for (int i = 0; i < PER_H; i++) {
		cct_showstr(PER_X, PER_Y + 1 +i, "�U", BG, FG);
		cct_showstr(PER_X + 2, PER_Y + 1 +i, "  ", BG, FG,PER_LEN);
		cct_showstr(PER_X + 2, PER_Y + 1 +i, "   ", BG, FG);
		cct_showstr(PER_X + 2 + PER_LEN * 2, PER_Y + 1 +i, "�U", BG, FG);
	}

	cct_gotoxy(PER_X, PER_Y + PER_H + 1);
	cout << "�^";
	for (int j = 0; j < PER_LEN; j++) {
		cout << "�T";
	}
	cout << "�a";
	prt_per(G);

	cct_setcolor();
}
//��ӡ���������
void prt_ball_gui(game& G)
{
	for (int y = 0; y < G.row; y++) {
		for (int x = 0; x < G.line; x++) {
			if (G.board[y][x] != 0) {
				cct_showstr(POINT_X + x * 4, POINT_Y + y * 2,
					"��", G.board[y][x], FG);
			}
			else {
				cct_showstr(POINT_X + x * 4, POINT_Y + y * 2,
					"  ", BG, FG);
			}
		}
	}
}
//��ʼ�����
void prt_boarder(game& G)
{
	int row_n = 6 + G.row;
	cct_setfontsize("������", FONT_HEIGHT);
	cct_setcolor(BG, FG);

	cct_gotoxy(BOARDER_X, BOARDER_Y);
	cout << "�X";
	for (int j = 0; j < G.line; j++) {
		if(j==0)
			cout << "�T";
		else {
			cout << "�j�T";
		}
	}
	cout << "�[";

	for (int i = 0; i < G.row; i++) {
		if (i != 0) {
			cct_showstr(BOARDER_X, BOARDER_Y + i * 2 , "�d", BG, FG);
			cct_showstr(BOARDER_X + 2, BOARDER_Y + i * 2 , "�T�p", BG, FG, G.line - 1);
			cct_showstr(BOARDER_X + 2 + 4 * (G.line - 1), BOARDER_Y + i * 2, "�T�g", BG, FG);

		}
		cct_showstr(BOARDER_X, BOARDER_Y + i * 2 + 1, "�U", BG, FG);
		cct_showstr(BOARDER_X + 2, BOARDER_Y + i * 2 + 1, "  �U", BG, FG,G.line);

	}

	cct_gotoxy(BOARDER_X, BOARDER_Y + G.row * 2);
	cout << "�^";
	for (int j = 0; j < G.line; j++) {
		if(j==0)
			cout << "�T";
		else {
			cout << "�m�T";
		}
	}
	cout << "�a";

	prt_ball_gui(G);


	cct_setcolor();
}

int if_avai_area(const game& G, int X, int Y, int & cur_x,int &cur_y)
{
	int ret = 0;
	for (int i = 0; i < G.row; i++) {
		for (int j = 0; j < G.line; j++) {
			if ((Y == BOARDER_Y + i * 2 + 1) 
				&& ((X == BOARDER_X + 2 + j * 4) || (X == BOARDER_X + 2 + j * 4 + 1))) {
				ret = 1;
				cur_x = j;
				cur_y = i;
				return ret;
			}
		}
	}
	return ret;
}

//�����bug������������
void trans_xy(point& p)
{
	int y1 = p.x, x1 = p.y;
	p.x = x1;
	p.y = y1;
}
void prt_move(game& G, point src, point dst,int bg)
{
	const int S = 300;//��ʱ
	trans_xy(src);
	trans_xy(dst);
	//����
	cct_showstr( POINT_X + src.x * 4, POINT_Y + src.y * 2,
		"  ", BG, FG);
	//����ƶ���ȡ�е�
	cct_showstr((POINT_X + src.x * 4 + POINT_X + dst.x * 4) / 2,
		(POINT_Y + src.y * 2 + POINT_Y + dst.y * 2)/2, 
		"��", bg, FG);
	Sleep(S);
	if (src.x == dst.x) {
		cct_showstr((POINT_X + src.x * 4 + POINT_X + dst.x * 4) / 2,
			(POINT_Y + src.y * 2 + POINT_Y + dst.y * 2) / 2, 
			"�T", BG, FG);
	}
	else {
		cct_showstr((POINT_X + src.x * 4 + POINT_X + dst.x * 4) / 2,
			(POINT_Y + src.y * 2 + POINT_Y + dst.y * 2) / 2, 
			"�U", BG, FG);
	}
	//�����ƶ�tobe
	cct_showstr( POINT_X + dst.x * 4, POINT_Y + dst.y * 2,
		"��", bg, FG);
	Sleep(S);
	cct_setcolor();
}
void opt6(game& G)
{
	cct_enable_mouse();	//�����
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��

	int X = 0, Y = 0,cur_x,cur_y;//cur_x����
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	point src = { -1,-1 };

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			if (if_avai_area(G, X, Y,cur_x,cur_y) ){
				cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
				cout << "[��ǰ���]" << char(cur_y + 'A') << "��" << cur_x + 1 << "��";
				cout << setw(20) << "";
				int quit = 0;
				switch (maction) {
					case MOUSE_ONLY_MOVED:
						break;
					case MOUSE_LEFT_BUTTON_CLICK:			//�������
						if (src.x == -1 && src.y == -1) {
							if (G.board[cur_y][cur_x] != 0) {
								src.x = cur_x;
								src.y = cur_y;
								cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
									"��", G.board[src.y][src.x], FG);
								cct_setcolor();

							}
						}
						else {
							if (G.board[cur_y][cur_x] != 0) {
								cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
									"��", G.board[src.y][src.x], FG);
								cct_setcolor();
								src.x = cur_x;
								src.y = cur_y;
								cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
									"��", G.board[src.y][src.x], FG);
								cct_setcolor();

							}
							else {
								point dst = { cur_x,cur_y };
								stack path_s;
								point dst1 = dst, src1=src;
								trans_xy(dst1);
								trans_xy(src1);
								if (find_path(G, src1, dst1, path_s)) {
									cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
									cout << "[��ʾ] ���Դ�" << char(src.y + 'A')
										<< src.x + 1 << "�ƶ���"
										<< char(dst.y + 'A') << dst.x + 1;
									cout << setw(20) << "";
									int color = G.board[src1.x][src1.y];
									for (int i = path_s.top - 1; i > 0; i--) {
										
										prt_move(G, path_s.base[i],path_s.base[i-1],color);
									}
									int tmp = G.board[src1.x][src1.y];
									G.board[src1.x][src1.y] = G.board[dst1.x][dst1.y];
									G.board[dst1.x][dst1.y] = tmp;
									src = dst;
									quit = 1;
									break;
									//��Ϸ������ϸ��ȶ
								}
								else {
									cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
									cout << "[����] �޷���" << char(src.y + 'A')
										 <<src.x + 1 << "�ƶ���"
										<< char(dst.y + 'A')<<dst.x+1;
									cout << setw(20) << "";

								}
								clear_G_mark(G);
							}
						}


						break;
					case MOUSE_RIGHT_BUTTON_CLICK:	//�����Ҽ�
						return;
					default:
						break;
				}
				if (quit) {
					break;
				}
			}
		}

	}


	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
}
void prt_new(int next_color[], int NEW_BALL)
{
	for (int i = 0; i < NEW_BALL; i++) {
		cct_showstr(NEW_X + 2 + i * 4, NEW_Y + 1,
			"��", next_color[i], FG);

	}
	cct_setcolor();
}
void prt_per(game& G)
{
	cout << setiosflags(ios::fixed) << setprecision(2);
	cct_showstr(PER_X + 2, PER_Y + 1, "  ", BG, FG);
	cct_setcolor(BG, FG);
	cout << setfill('0') << setw(2)
		<< G.row * G.line - G.vertex_num << setfill(' ')
		<< "/(" << setw(5)
		<< (G.row * G.line - G.vertex_num) / float(G.row * G.line) *100
		<< "%) ����-0";
	for (int i = 1; i <= COLOR_MAX; i++) {
		cct_showstr(PER_X + 2, PER_Y + 1 + i, "��", i, FG);
		cct_setcolor(BG, FG);
		cout << setfill('0') << setw(2)
			<< G.vertex[i] << setfill(' ')
			<< "/(" << setw(5)
			<< (G.vertex[i]) / float(G.row * G.line) * 100
			<< "%) ����-" <<G.vertex_bingo[i];
	}
}

void game_gui(game& G)
{
	//��ղ���ʼ��Ϸ
	G.score = 0;
	clear_G_mark(G);

	cct_enable_mouse();	//�����
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��


	const int NEW_BALL = 3;
	int next_color[NEW_BALL] = { 0 };
	int flag_new = 1;
	point src = { -1,-1 };
	while (1) {
		if (G.vertex_num >= G.row * G.line) {
			cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
			cout << "�޿�λ���ƶ�����Ϸ����!" << endl;
			break;
		}
		//��������ɫ
		generate_color(next_color, NEW_BALL, flag_new);
		//��ӡ����ɫ
		prt_new(next_color, NEW_BALL);

		int X = 0, Y = 0, cur_x, cur_y;//cur_x����
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		while (loop) {
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
			if (ret == CCT_MOUSE_EVENT) {
				if (if_avai_area(G, X, Y, cur_x, cur_y)) {
					cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
					cout << "[��ǰ���]" << char(cur_y + 'A') << "��" << cur_x + 1 << "��";
					cout << setw(20) << "";
					int quit = 0;
					switch (maction) {
						case MOUSE_ONLY_MOVED:
							break;
						case MOUSE_LEFT_BUTTON_CLICK:			//�������
							if (src.x == -1 && src.y == -1) {
								if (G.board[cur_y][cur_x] != 0) {
									src.x = cur_x;
									src.y = cur_y;
									cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
										"��", G.board[src.y][src.x], FG);
									cct_setcolor();

								}
							}
							else {
								if (G.board[cur_y][cur_x] != 0) {
									cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
										"��", G.board[src.y][src.x], FG);
									cct_setcolor();
									src.x = cur_x;
									src.y = cur_y;
									cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
										"��", G.board[src.y][src.x], FG);
									cct_setcolor();

								}
								else {
									point dst = { cur_x,cur_y };
									stack path_s;
									point dst1 = dst, src1 = src;
									trans_xy(dst1);
									trans_xy(src1);
									if (find_path(G, src1, dst1, path_s)) {
										cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
										cout << "[��ʾ] ���Դ�" << char(src.y + 'A')
											<< src.x + 1 << "�ƶ���"
											<< char(dst.y + 'A') << dst.x + 1;
										cout << setw(14) << "";
										//�ƶ����̴�ӡ
										int color = G.board[src1.x][src1.y];
										for (int i = path_s.top - 1; i > 0; i--) {

											prt_move(G, path_s.base[i], path_s.base[i - 1], color);
										}

										//Ĭ�ϲ�������
										flag_new = 0;

										//swap
										int tmp = G.board[src1.x][src1.y];
										G.board[src1.x][src1.y] = G.board[dst1.x][dst1.y];
										G.board[dst1.x][dst1.y] = tmp;
										src = dst;
										
										//��Ϸ������ϸ��ȶ
										
										//������
										int bingo_n = bingo(G);
										//δ�����ɹ�
										if (!bingo_n) { 
											//��������
											flag_new = 1;
											gen_ball(G, next_color, NEW_BALL);
											prt_ball_gui(G);
											//��ʾ��ѡ�е���

											cct_showstr(POINT_X + src.x * 4, POINT_Y + src.y * 2,
												"��", G.board[src.y][src.x], FG);
											cct_setcolor();

										}
										else {//�����ɹ�
											//���·���
											cct_gotoxy(OTHER_X + 2 + 6, OTHER_Y + 1);
											cct_setcolor(BG, FG);
											cout << G.score;
											cct_setcolor();

											//״̬���ص���ʼֵ
											src.x = -1;
											src.y = -1;
											prt_ball_gui(G);
										}


										
										//���µ�ǰ����
										prt_per(G);
										//option6
										quit = 1;
										break;

									}
									else {
										
										cct_gotoxy(0, BOARDER_Y + G.row * 2 + 1);
										cout << "[����] �޷���" << char(src.y + 'A')
											<< src.x + 1 << "�ƶ���"
											<< char(dst.y + 'A') << dst.x + 1;
										cout << setw(14) << "";


									}
									clear_G_mark(G);
								}
							}


							break;
						case MOUSE_RIGHT_BUTTON_CLICK:	//�����Ҽ�
							return;
						default:
							break;
					}
					//option6
					if (quit) {
						break;
					}
				}
			}

		}

	}


	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��

}