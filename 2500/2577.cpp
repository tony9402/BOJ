#include<cstdio>

int num[10];

int main()
{
	int times = 1, input, div;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &input);
		times *= input;
	}
	while (times != 0) {
		div = times % 10;
		num[div]++;
		times /= 10;
	}
	for (int i = 0; i < 10; i++)printf("%d\n", num[i]);
	return 0;
}