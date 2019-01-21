#include<iostream>
#include<algorithm>

using namespace std;

int input[1000];
int dp[1000][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> input[i];

	for (int i = 1; i <= n; i++)
		if (i < 3)
		{
			dp[i][0] = input[i];
			dp[i][1] = dp[i - 1][0] + input[i];
		}
		else
		{
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + input[i];
			dp[i][1] = dp[i - 1][0] + input[i];
		}

	cout << max(dp[n][0], dp[n][1]);
	return 0;
}