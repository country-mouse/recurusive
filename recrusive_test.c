#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void move(int no, int x, int y)
{
	if (no > 1)
		move(no - 1, x, 6 - x - y);
	printf("¿ø¹Ý[%d]À» %d±âµÕ¿¡¼­ %d ±âµÕÀ¸·Î ¿Å±è\n", no, x, y);
	if (no > 1)
		move(no - 1, 6 - x - y, y);
}

int main(void)
{
	int n;
	printf("number of rings' tower: ");
	scanf("%d", &n);
	move(n, 1, 3);

	return 0;
}