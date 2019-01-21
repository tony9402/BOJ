#include<stdio.h>

char ch[1005];

int main()
{
	scanf("%s", ch);

	for (int i = 0; ch[i]; i++)
		printf("%c", (ch[i] - 'A' + 23) % 26 + 'A');
	return 0;
}