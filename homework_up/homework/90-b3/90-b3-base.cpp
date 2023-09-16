/* 2152988 ������ �ƿ� */
#include <iostream>
#include <io.h>
#include <cstring>
#include "cmd_console_tools.h"
#include "90-b3.h"
using namespace std;

char* tj_strcpy(char* s1, const char* s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */

	if (s1 == NULL) {
		return s1;
	}
	if (s2 == NULL) {
		*s1 = 0;
		return s1;
	}
	char* p1 = s1;
	const char* p2 = s2;

	while (*p2) {
		*p1++ = *p2++;
	}
	*p1 = 0;
	return s1;
}
char* tj_strncpy(char* s1, const char* s2, const int len)
{
	if (s1 == NULL || s2 == NULL) {
		return s1;
	}

	char* p1 = s1;
	const char* p2 = s2;

	while (*p2 && p2 - s2 < len) {
		*p1++ = *p2++;
	}
	return s1;
}
//�ļ��������ֵ���
void sort_name(file_list& L)
{
	for (int i = L.top - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(L.list[j], L.list[j + 1]) > 0) {
				char tmp[NAME_LEN + 1];
				tj_strcpy(tmp, L.list[j]);
				tj_strcpy(L.list[j], L.list[j+1]);
				tj_strcpy(L.list[j+1],tmp);
			}
		}
	}
}
//����ļ����Ƿ�Ϸ�
int check_filename(const char* tmp)
{
	int len = strlen(filename_demo);
	if (strlen(tmp) != len + NAME_LEN+4) { //4��.txt
		return 0;
	}
	if (strncmp(tmp, filename_demo, len) != 0) {
		return 0;
	}
	return 1;
}
//��ȡ�����ļ���
int get_filename(file_list& L)
{
	_finddata_t fdata;
	char path[100] = "./stage/*.txt";
	long hnd = _findfirst(path, &fdata);
	const int name_start = 14;
	if (hnd < 0) {
		//�������ӡ?
		cerr << "�޷���[./stage]Ŀ¼." << endl;
		return -1;
	}
	int ret = 0;
	L.top = 0;
	while (ret >= 0) {
		if (fdata.attrib == _A_ARCH) {
			if (check_filename(fdata.name)) {
				//�洢����
				tj_strncpy(L.list[L.top++], 
					fdata.name + name_start,NAME_LEN);
				L.list[L.top - 1][NAME_LEN] = 0;//��β��
			}
		}
		ret = _findnext(hnd, &fdata);
	}
	_findclose(hnd);
	//����˵�����
	L.menu_num = L.top >= MENU_NUM_MAX ? MENU_NUM_MAX : L.top;
	//����
	sort_name(L);
	return 0;
}