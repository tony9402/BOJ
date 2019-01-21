#include<iostream>

using namespace std;
typedef long long ll;

ll dp[1000001] = { 0, 1, 2, 4 };
const ll mod = 1000000009;

ll solve(int n)
{
	if (n <= 0)return 0;
	if (dp[n])return dp[n];
	return dp[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3)) % mod;
}
int main()
{
	ll T, n;
	cin >> T;
	for (; T--;)
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}