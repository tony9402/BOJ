#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll inf = 0x7fffffffff;

ll dp[2][2000];
ll rock[3] = { 1,3,4 };

void solve(int n)
{
	dp[0][1] = dp[0][3] = dp[0][4] = 1;
	dp[1][1] = dp[1][3] = dp[1][4] = 1;
	dp[0][2] = dp[1][2] = -1;
	for (int i = 5; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int check = 0;
			for (int k = 0; k < 3; k++)
			{
				int idx = i - rock[k];
				if (idx < 0)continue;
				if (dp[1 - j][idx] == -1)
				{
					check = 1;
					break;
				}
				check = -1;
			}
			dp[j][i] = check;
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