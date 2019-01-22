#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

vector<pair<int, int>> list;
int arr[1001];

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second != b.second)return a.second > b.second;
	else return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		list.push_back(make_pair(a, b));
	}
	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++)
	{
		int j = list[i].first;
		while (arr[j] && j-- > 0);
		if (j > 0)arr[j] = list[i].second;
	}
	int ans = 0;
	for (int i = 1; i <= 1000; i++)ans += arr[i];
	cout << ans;
	return 0;
}