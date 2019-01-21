#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
vector<pair<int, int>> list;
int dp[100000];

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first != b.second)return a.first > b.first;
	return a.second > b.second;
}

int solve(int m) // k==start_poiner, m == now_money
{
	fill(dp, dp + 100000, 0);
	for (int i = 0; i < m; i++)
	{
		for (auto j : list)
		{
			dp[i + j.first] = max(dp[i + j.first], dp[i] + j.second);
		}
	}

	return dp[m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	double money;
	while (1)
	{
		cin >> n >> money;
		if (n == 0 && money == 0.0)break;
		list.clear();
		for (int i = 0; i < n; i++)
		{
			int k;
			double m;
			cin >> k >> m;
			int im = (int)(m * 100 + 0.5);
			list.push_back(make_pair(im, k));
		}
		sort(list.begin(), list.end(), compare);

		cout << solve((int)(100*money+0.5)) << '\n';
	}



	return 0;
}