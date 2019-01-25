#include<iostream>
#include<vector>

using namespace std;
int dp[10001];
vector<int> list;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > k)continue;
		dp[list[i]]++;
		for (int j = list[i] + 1; j <= k; j++)
		{
			if (j - list[i] < 0 || j - list[i] > k)continue;
			dp[j] += dp[j - list[i]];
		}
	}
	cout << dp[k];
	return 0;
}