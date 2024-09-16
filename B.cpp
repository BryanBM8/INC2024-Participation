#include <stdio.h>

int main(void)
{
	int banyak = 0, susu = 0, biskuit = 0;
	scanf("%d %d %d", &banyak, &susu, &biskuit);
	int diet[banyak + 1] = {0};
	for (int i = 0; i < banyak; i++)
	{
		scanf("%d", &diet[i]);
	}
	int i = 0;
	for (i = 0; i < banyak; i++)
	{
		int max = 0;
		int index = 0;
		susu -= diet[i];
		if (susu >= 0)
		{
			
		}
		else if (biskuit > 0)
		{
			biskuit--;
			for (int j = 0; j <= i; j++)
			{
				if (max < diet[j])
				{
					max = diet[j];
					index = j;
				}
			}
			susu += max;
			diet[index] = 0;
		}
		else
		{
			printf("%d\n", i);
			break;
		}
	}
	if (i == banyak)
	{
		printf("%d\n", banyak);
	}
}
