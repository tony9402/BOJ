#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[10000] = { 1,1, };
string input;
const int mod = 1000000;

int main()
{;
	cin >> input;
	if (input[0] == 48)return cout << 0, 0;
	for (int i = 2; i <= input.size(); i++)
	{
		int idx = i - 1;
		if (input[i - 1] > 48)
		{
			dp[i] = dp[i - 1];
		}

		int num = input[i - 2] * 10 + input[i - 1] - 528;

		if (10 <= num && num <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	cout << dp[input.size()];
	return 0;
}