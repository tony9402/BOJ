#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if (n & 1)return cout << 0, 0;
	ll dp[31];
	dp[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += 2*dp[j];
	}
	cout << dp[n];
	return 0;
}