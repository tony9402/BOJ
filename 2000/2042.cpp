#include<stdio.h>

typedef long long ll;
const int MAX = 1e6 + 5;

ll Tree[MAX], input[MAX];

void update(int k, int n, ll num)
{
	for (int i = k; i <= n; i += i & -i)
		Tree[i] += num;
}

ll Sum(int k, int n)
{
	ll ret = 0;
	for (int i = k; i; i -= i & -i)
		ret += Tree[i];
	return ret;
}

int main()
{
	ll n, m, k;
	
	scanf("%lld %lld %lld", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		scanf("%lld", &input[i]), update(i,n,input[i]);
	
	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
			update(b, n, c - input[b]), input[b] = c;
		else
			printf("%lld\n", Sum(c,n) - Sum(b - 1,n));
	}
	return 0;
}