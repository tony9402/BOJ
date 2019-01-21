#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
typedef long long ll;

ll dp[1001] = { 0,1,2, };
ll mod = 10007;

ll DP(ll n)
{
	if (n < 1)return 0;
	if (dp[n])return dp[n];
	return dp[n] = (DP(n - 1) + DP(n - 2)) % mod;
}

int main()
{
	int n;
	cin >> n;
	cout << DP(n);
	return 0;
}