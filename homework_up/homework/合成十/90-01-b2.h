/* 2153299 �ư� ��Ƿ� */
#pragma once

//M��N��ʾ���Ķ�ά��������У�����ʹ���顰��һȦ�����ں�������
const int M = 10;
const int N = 12;


//�ṹ��Ķ���
//number[M][N]������ʾ���֣�sign[M][N]�������б��
struct shuzu {
	int number[M][N] = { 0 };
	char sign[M][N];
};


/*************************

			  90-b2-base�е��ڲ������йصĺ���

									 *************************/

 //���ݾ����е����ֵ�������µ����ֵ
void random_number_generation(struct shuzu* array, int max_of_number, int row, int column);


//��������ѡ�������
bool coordinate_judge(struct shuzu* array, int row, int column, int x, int y, int canshu);
void input_coordinate(struct shuzu* array, int row, int column, int* cooddinate_x, int* coordinate_y);

//����������Ӧ�˵ݹ�ͷǵݹ���ʽ�£�ÿһ��Ѱ�����ڵ���ֵͬ
void search_recursion(struct shuzu* array, int row, int column, int x, int y);
void search_no_recursion(struct shuzu& array, int row, int column);

//���������ֱ�����������־���ͷ��ž���
void output_array_number(struct shuzu* array, int row, int column, int canshu, int max, const char* const prompt);
void output_array_sign(struct shuzu* array, int row, int column);

//��������������ɾ����һ�������ı仯��ʾ
void array_change_zero_fall(struct shuzu* array, int row, int column);
void array_change(struct shuzu* array, int row, int column, int x, int y, int* score, int* target, int* max_of_number);

//ȷ���Ƿ�����ڵ���ֵͬ���кϳ�
void array_change_confirm(char* confirm, int x, int y);

//Ѱ�����־����е����ֵ
int search_max_of_number(struct shuzu* array, int row, int column);

//���ַ������ʼ��
void initialization_array_sign(struct shuzu* array);

//ÿһ�α仯�����Ƿ�ﵽ�ϳ�Ŀ�꣬�Լ��Ƿ��ܲ���
void initial_judge(char option, struct shuzu* array, int row, int column, int max_of_number, int* target, int* judge_of_end);



/*************************

			  90-b2-console�е�αͼ���йصĺ���

									 *************************/
									 //����������������ӡ��ʼ�ı���ÿ��С����
void console_output_original_array(struct shuzu* array, int row, int column, char option);
void console_output_original_form(int row, int column, char option);

//�������ͼ��̵�״̬
void choose_ketboard_and_mouse(char option, struct shuzu* array, int row, int column, int* max_of_number, int* score, int* target, int* loop_q);

//�жϹ���λ���Ƿ���ĳ��С�����ڲ�
int mouse_area_judge(int row, int column, int MX, int MY, int* x, int* y);

//���������������Զ�������ͼ��̵�״̬ת����ͼ�ν�����
void display_of_choose(char option, int* loop, struct shuzu* array, int* coordinate_x,
	int* coordinate_y, int row, int column, int MX, int MY, int MAction, int keycode1, int keycode2);
void display_of_choose2(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);


//������һЩ�Ƚ϶�С�Ĺ��ܺ���

//ȷ���Ƿ�ѡ��ǰ����˸�ķ���
void console_confirm(const char* const prompt, int row);

//����ÿһ��С����ͻ����ʾ������ͨ��ʾ
void display(int canshu, struct shuzu* array, int coordinate_x, int coordinate_y);

//�����ںϳ�ʱ����˸����
void flash(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);

//��Ӧαͼ���з���ֵ����ʱ�Ķ�����ʾ
void move1(struct shuzu* array, int row, int column, int coordinate_x, int coordinate_y);
void move_2(struct shuzu* array, int coordinate_x, int coordinate_y);



/*************************

			  90-b2-tools�еĹ��õĹ����ͺ���

									 *************************/

									 //������ �� �Լ��ϳ�Ŀ��
void input_row_and_column(int* row, int* column, int* target, char option);


void tj_charupr(char* a);


//���ָ�����ַ�������Ҫ�󰴻س������ܼ���
void wait_for_enter(const char* const prompt);
