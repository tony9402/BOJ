#include<iostream>
#include<cstdio>

#define min(x,y) (x)>(y)?(y):(x)

using namespace std;

int dp[1000001] = { 0 };
const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	cin >> n;
	fill(dp, dp + n + 1, INF);
	dp[n] = 0;
	for (int i = n; i > 0; i--)
	{
		if (dp[i] == INF)continue;
		if (i % 3 == 0)
		{
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		}
		if (i >= 2)
		{
			dp[i - 1] = min(dp[i - 1], dp[i] + 1);
		}
	}
	printf("%d", dp[1]);
	return 0;
}