#include<stdio.h>
#include<math.h>

int main()
{
	long long n;
	long long x1, y1, r1, x2, y2, r2;
	long long dis, Min, Max;
	scanf("%lld", &n);
	for (; n--;)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if (dis == 0 && r1 == r2)
		{
			printf("-1\n");
		}
		else if (dis <= (r1 - r2)*(r1 - r2))
		{
			Min = (r1 < r2 ? r1 : r2);
			Max = (r1 > r2 ? r1 : r2);
			if (dis == (r1 - r2) * (r1 - r2))
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
		else {
			if (dis == (r1 + r2)*(r1 + r2))
			{
				printf("1\n");
			}
			else if (dis > (r1 + r2)*(r1 + r2))
			{
				printf("0\n");
			}
			else
			{
				printf("2\n");
			}
		}
	}
	return 0;
}