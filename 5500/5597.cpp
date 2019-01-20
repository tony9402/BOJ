#include<cstdio>
#include<cstdlib>
#include<cstring>

int num[30] = { 0 };

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)num[n - 1] = 1;
	for (int i = 0; i < 30; i++)if (num[i] == 0)printf("%d\n", i + 1);
}
