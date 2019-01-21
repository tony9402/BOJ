#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll dp[2][100001] = { 0 };
ll Map[2][100001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++)
				cin >> Map[j][k];

		for (int j = 1; j <= n; j++)
		{
			dp[0][j] = max(dp[0][j - 1], dp[1][j - 1] + Map[0][j]);
			dp[1][j] = max(dp[1][j - 1], dp[0][j - 1] + Map[1][j]);
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}