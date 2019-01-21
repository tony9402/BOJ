#include<iostream>

using namespace std;
int dp[1001][10] = { 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)dp[0][i] = 1;

	for (int i = 1; i < n; i++)
		for (int n = 0; n < 10; n++)
			for (int m = n; m < 10; m++)
				dp[i][n] = (dp[i][n] + dp[i - 1][m]) % 10007;

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[n - 1][i]) % 10007;

	cout << ans;
	return 0;
}