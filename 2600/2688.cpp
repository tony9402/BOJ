#include<iostream>

using namespace std;
typedef long long ll;

ll dp[100][100] = { 0 };

int main()
{
	int T, input;
	ll sum = 0, ans = 0;;
	cin >> T;
	for (int i = 0; i <= 9; i++)dp[1][0] = 1;
	for (; T--;)
	{
		ans = 0;
		cin >> input;
		for (int i = 1; i <= input; i++)
		{
			if (dp[i + 1][0] != 0)continue;
			for (int j = 0; j <= 9; j++)
			{
				sum = 0;
				for (int k = 0; k <= j; k++)
					sum += dp[i][k];
				dp[i + 1][j] = sum;
			}
		}
		for (int i = 0; i <= 9; i++)
			ans += dp[input + 1][i];
		cout << ans << '\n';
	}
	return 0;
}