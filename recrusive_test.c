#include <stdio.h>

int pos[8];
int flag[8][8];


void print(void)
{
	for (int i = 0; i < 8; i++)
	{
		printf("%2d", pos[i]);
	}
	printf("\n");
}

void set(int i)
{
	if (i == 8) {
		print();
		return;
	}
	for (int j = 0; j < 8; j++)
	{
		if (flag[j][i] == 0)
		{
			pos[i] = j;
			for (int k = i + 1; k < 8; k++)
			{
				flag[j][k]++;
				if (j - i + k >= 0 && j - i + k < 8)
					flag[j - i + k][k]++;
				if (j + i - k >= 0 && j + i - k < 8)
					flag[j + i - k][k]++;
			}
			
			set(i + 1);
			for (int k = i + 1; k < 8; k++) //상태를 변경한 주체가 직접 원래대로 복원해야 한다'*
			{
				flag[j][k]--;
				if (j - i + k >= 0 && j - i + k < 8)
					flag[j - i + k][k]--;
				if (j + i - k >= 0 && j + i - k < 8)
					flag[j + i - k][k]--;
			}
		}
		
			
	}
}

int main(void)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			flag[i][j] = 0;
		}
	}
	set(0);

	return 0;
}