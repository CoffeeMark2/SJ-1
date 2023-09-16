/* 2152988 ������ �ƿ� */
#pragma once
const int FILE_NUM_MAX = 1000, NAME_LEN = 3;
const int BOARD_COL = 150, BOARD_ROW = 40;
const int MENU_NUM_MAX = 25;

const char filename_demo[] = "Sokoban-Level-",
filename_type[] = ".txt";

struct file_list {
	char list[FILE_NUM_MAX][NAME_LEN + 1];
	int top = 0;//��ջ��
	int cur_list = 0;//���ڲ˵�����ѡ��ѡ���0����
	int cur_popmenu = 0;//ͼ�β˵����ڵ�ѡ��λ��
	int cur_popmenu_first = 0;//ͼ�β˵��ʼ��ѡ��λ�ã����ڸ��²˵���ʵ�ֹ���Ч��
	int menu_num;//�˵�����
};

void popmenu(file_list& L);
int get_filename(file_list& L);

int prt_game(const file_list& L);

void to_be_continued_end(void);