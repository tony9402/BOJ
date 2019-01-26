#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> vc;

int dp[501][501] = { 0 };

int solve(int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{
		dp[i][i] = 0;
	}
	for (int dia = 1; dia <= n - 1; dia++)
	{
		for (int i = 1; i <= n - dia; i++)
		{
			j = i + dia;
			int maxi = 0x3f3f3f3f;
			for (int k = i; k <= j - 1; k++)
				maxi = min(maxi, dp[i][k] + dp[k + 1][j] + vc[i - 1] * vc[k] * vc[j]);
			dp[i][j] = maxi;
		}
	}
	return dp[1][n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input, trash;
		cin >> input >> trash;
		vc.push_back(input);
		if (i == n - 1)vc.push_back(trash);
	}

	cout << solve(n);

	return 0;
}