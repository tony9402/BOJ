#include<iostream>

using namespace std;
typedef long long ll;

ll dp[1000];

ll solve(int n)
{
	if (n == 0)return dp[n] = 0;
	if (n <= 2)return dp[n] = 1;
	if (dp[n])return dp[n];
	return dp[n] = solve(n - 1) + solve(n - 2);
}

int main()
{
	ll n;
	cin >> n;
	cout << solve(n);
	return 0;
}