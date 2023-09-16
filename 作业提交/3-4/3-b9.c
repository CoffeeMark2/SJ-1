/*2152988 јЖїЖ СовэГъ*/
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main()
{
	for (int row = 1; row <= 9; row++) {
		for (int line = 1; line <= row; line++) {
			printf("%dx%d=%d", line, row, line * row);
			printf(line * row < 10 ? "   " : "  ");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

