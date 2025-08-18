#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main(void)
{
	int x, y;
	printf("enter int a: ");
	scanf("%d", &x);
	printf("enter int b: ");
	scanf("%d", &y);
	printf("%d", gcd(x, y));

	return 0;
}