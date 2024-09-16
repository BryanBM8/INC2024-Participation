#include <stdio.h>
#include <string.h>

int main(void)
{
	int team = 0, top = 0, ticket = 0;
	scanf("%d %d %d", &team, &top, &ticket);
	char nama[101][11];
	char univ[11] = "";
	char univ_lolos[101][11];
	int lolos = 0;
	int banyak = 0;
	int index[101] = {0};
	for (int i = 0; i < team; i++)
	{
		scanf("%s %s", nama[i], univ);
		if (top > 0)
		{
			top--;
			strcpy(univ_lolos[lolos], univ);
			lolos++;
		}
		else
		{
			if (ticket > 0)
			{
				int ada = 0;
				for (int j = 0; j < lolos; j++)
				{
					if (strcmp(univ, univ_lolos[j]) == 0)
					{
						ada = 1;
					}
				}
				if (ada != 1)
				{
					index[banyak] = i;
					strcpy(univ_lolos[lolos], univ);
					lolos++;
					banyak++;
					ticket--;
				}
			}
		}
	}
	printf("%d\n", banyak);
	for (int i = 0; i < banyak; i++)
	{
		printf("%s\n", nama[index[i]]);
	}
}
