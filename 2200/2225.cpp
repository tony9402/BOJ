#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1000000000;
ll dp[1000][1000];

int main()
{
	for (int i = 0; i <= 200; i++)dp[0][i] = 1;
	for (int i = 1; i <= 200; i++)
		for (int j = 1; j <= 200; j++)
			for (int k = i; k >= 0; k--)
				dp[i][j] = (dp[k][j - 1] + dp[i][j]) % mod;

	int n, k;
	cin >> n >> k;
	cout << dp[n][k];
	return 0;
}