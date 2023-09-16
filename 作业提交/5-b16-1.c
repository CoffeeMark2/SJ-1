/*2152988 计科 杨恺铭*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 10
#define NUM 8
#define NAME 9

void input(char num[N][NUM], char name[N][NAME], int grade[N])
{
	for (int i = 0; i < N; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i+1);
		scanf("%s", num[i]);
		scanf("%s", name[i]);
		scanf("%d", &grade[i]);
	}
}

void sort(char num[N][NUM], char name[N][NAME], int grade[N])
{
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (strcmp(num[j], num[j + 1]) < 0){
				int tmp = grade[j];
				grade[j] = grade[j + 1];
				grade[j + 1] = tmp;

				char s1[NUM], s2[NAME];
				strcpy(s1, num[j]);
				strcpy(num[j], num[j + 1]);
				strcpy(num[j + 1], s1);

				strcpy(s2, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], s2);
			}
		}
	}
}

void output(char num[N][NUM], char name[N][NAME], int grade[N])
{
	printf("\n");
	printf("及格名单(学号降序):\n");
	for (int i = 0; i <N; i++) {
		if (grade[i] >= 60) {
			printf("%s ", &name[i]);
			printf("%s ", &num[i]);
			printf("%d\n", grade[i]);

		}
	}
}

int main()
{
	char num[N][NUM];
	char name[N][NAME];
	int grade[N];
	input(num, name, grade);
	sort(num, name, grade);
	output(num, name, grade);
	return 0;
}