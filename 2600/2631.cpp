#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;
int dp[10000];

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

	vector<int> check;
	check.push_back(list[0]);
	for (int i = 1; i < n; i++)
	{
		if (check.back() < list[i])
			check.push_back(list[i]);
		else
			check[lower_bound(check.begin(), check.end(), list[i]) - check.begin()] = list[i];
	}
	cout << list.size() - check.size();
	return 0;
}
