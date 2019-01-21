#include<iostream>

using namespace std;

int dp[1001] = { 0,1,3 };
const int mod = 10007;

int solve(int n)
{
	if (dp[n])return dp[n];
	return dp[n] = (solve(n - 1) + 2 * solve(n - 2)) % mod;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}