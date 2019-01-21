#include<iostream>

using namespace std;

int dp[13] = { 0 };

int main()
{
	int T;
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 0; i < 9; i++)
	{
		dp[i + 3] = dp[i + 2] + dp[i + 1] + dp[i];
	}
	cin >> T;
	for (; T--;)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}