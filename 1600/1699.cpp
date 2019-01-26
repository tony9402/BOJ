#include<iostream>
int dp[100001];
int main(void) {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
				dp[i] = dp[i - j * j] + 1;
		}
	}
	std::cout << dp[n];
	return 0;
}