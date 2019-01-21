#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1000000000;

ll dp[200][10];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)dp[1][i] = 1;
	
	for(int i=2;i<=n;i++)
		for (int j = 0; j < 10; j++)
		{
			if (j >= 1)dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
			if (j <= 8)dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
			dp[i][j] = dp[i][j] % mod;
		}
	
	ll ans = 0;
	for (int i = 0; i < 10; i++)ans = (ans + dp[n][i]) % mod;
	cout << ans;
	return 0;
}