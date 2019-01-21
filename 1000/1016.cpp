#include<cstdio>
#include<cmath>
bool vc[1000001];
int main()
{
	long long i, j, min, max, cnt = 0;
	scanf("%lld %lld", &min, &max);
	for (i = 2; i*i <= max; i++)for (j = ceil(((double)min / (i*i)))*(i*i); j <= max; j += i * i)
		if (vc[j - min] == false) {
			cnt++;
			vc[j - min] = true;
		}
	printf("%lld", max - min + 1 - cnt);
	return 0;
}