#include<iostream>

using namespace std;

int dp[1001];

int solve(int n)
{
	if (n <= 1)return n;
	else if (dp[n])return dp[n];
	else return (dp[n] = solve(n - 1) + solve(n - 2));
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n);
	return 0;
}