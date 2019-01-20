#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vc;
int dp[301][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	vc.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &vc[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (i < 3)
		{
			dp[i][0] = vc[i];
			dp[i][1] = dp[i - 1][0] + vc[i];
		}
		else
		{
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + vc[i];
			dp[i][1] = dp[i - 1][0] + vc[i];
		}
	}

	printf("%d", max(dp[n][0], dp[n][1]));
	return 0;
}