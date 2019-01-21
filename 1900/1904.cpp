#include<iostream>

using namespace std;
typedef long long ll;

ll dp[1000001] = { 0,1,2 };
const ll mod = 15746;

ll solve(int n)
{
	if (dp[n])return dp[n];
	return dp[n] = (solve(n - 1) + solve(n - 2)) % mod;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}