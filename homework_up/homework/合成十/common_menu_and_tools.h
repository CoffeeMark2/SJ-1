/* 2153299 计拔 杨非凡 */
#pragma once

char common_menu(const int number_of_option, const char* possible_option, const char* content[]);

void common_pause_end();

//下面是自己写的字符串函数tj_***（指针形式实现），其中包括了对NULL的特殊处理
int   tj_strlen(const char* str);
char* tj_strcat(char* s1, const char* s2);
char* tj_strncat(char* s1, const char* s2, const int len);
char* tj_strcpy(char* s1, const char* s2);
char* tj_strncpy(char* s1, const char* s2, const int len);
int   tj_strcmp(const char* s1, const char* s2);
int   tj_strcasecmp(const char* s1, const char* s2);
int   tj_strncmp(const char* s1, const char* s2, const int len);
int   tj_strcasencmp(const char* s1, const char* s2, const int len);
char* tj_strupr(char* str);
char* tj_strlwr(char* str);
int   tj_strchr(const char* str, const char ch);
int   tj_strstr(const char* str, const char* substr);
int   tj_strrchr(const char* str, const char ch);
int   tj_strrstr(const char* str, const char* substr);
char* tj_strrev(char* str);