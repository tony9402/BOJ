#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;
int dp[3][100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}

	dp[0][0] = dp[1][0] = list[0];
	dp[0][1] = list[0] + list[1];
	dp[1][1] = list[1];
	dp[2][1] = list[0];
	for (int i = 2; i < n; i++)
	{
		dp[0][i] = dp[1][i - 1] + list[i];
		dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]);
		dp[1][i] = max(dp[1][i], dp[2][i - 2]) + list[i];
		dp[2][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
	}
	cout << max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);
	return 0;
}