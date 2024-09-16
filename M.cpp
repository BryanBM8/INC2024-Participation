#include<stdio.h>

int main(void)
{
	long long int n , m , k;
	scanf("%lld %lld %lld", &n, &m, &k);
	
	if (n * m == k)
	{
		printf("0\n");
		return 0;
	}
	if (k % n == 0 || k % m == 0)
	{
		printf("1\n");
		return 0;
	}
	if (m > n)
	{
		long long int temp = n;
		n  = m;
		m = temp;
	}
	for (int i = 1; i < n; i++)
	{
		if (k % i == 0 && k <= m * i)
		{
			printf("2\n");
			return 0;
		}
	}
	k = n * m - k;
	for (int i = 1; i < n; i++)
	{
		if (k % i == 0 && k <= m * i)
		{
			printf("2\n");
			return 0;
		}
	}
	printf("3\n");
}
