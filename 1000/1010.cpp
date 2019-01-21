#include<cstdio>

int dp[31][31] = { 0 };

int C(int n, int k)
{
	if (k == 0 || n == k)return 1;
	if (dp[n][k] > 0)return dp[n][k];
	return dp[n][k] = C(n - 1, k - 1) + C(n - 1, k);
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", C(b, a));
	}
	return 0;
}