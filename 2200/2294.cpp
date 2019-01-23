#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;
int dp[20000];
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, 0x3f, sizeof(dp));
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}
	sort(list.begin(), list.end());

	dp[0] = 0;
	for (int i = 0; i <= 10000; i++)
	{
		if (dp[i] == INF)continue;
		for (auto j : list)
		{
			if (i + j > 10000)continue;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}

	if (dp[k] == INF)cout << -1;
	else cout << dp[k];
	
	return 0;
}