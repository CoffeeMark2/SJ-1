/* 2152988 杨恺铭 计科 */
#pragma once
const int FILE_NUM_MAX = 1000, NAME_LEN = 3;
const int BOARD_COL = 150, BOARD_ROW = 40;
const int MENU_NUM_MAX = 25;

const char filename_demo[] = "Sokoban-Level-",
filename_type[] = ".txt";

struct file_list {
	char list[FILE_NUM_MAX][NAME_LEN + 1];
	int top = 0;//堆栈顶
	int cur_list = 0;//现在菜单数组选中选项，从0计数
	int cur_popmenu = 0;//图形菜单所在的选项位置
	int cur_popmenu_first = 0;//图形菜单最开始的选项位置，便于更新菜单，实现滚动效果
	int menu_num;//菜单数量
};

void popmenu(file_list& L);
int get_filename(file_list& L);

int prt_game(const file_list& L);

void to_be_continued_end(void);