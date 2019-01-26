#include<iostream>
#include<algorithm>

using namespace std;

int dp[2][2000];
const int r[3] = { 1,3,4 };

void solve(int n)
{
	dp[0][1] = -1;
	dp[1][1] = -1;

	for (int i = 2; i <= n; i++)
	{
		if (dp[0][i])continue;
		for (int j = 0; j < 2; j++)
		{
			int check = 0;
			for (int k = 0; k < 3; k++)
			{
				int idx = i - r[k];
				if (idx <= 0)continue;
				check = dp[1 - j][idx];
				if (check == -1)break;
			}
			dp[j][i] = -check;
		}
	}
	if (dp[0][n] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
}

int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}