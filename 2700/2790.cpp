#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;

bool compare(int &a, int &b)
{
	return a > b;
}

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

	sort(list.begin(), list.end(), compare);

	int t = 0;
	int ans = 0;
	for (int i = 0; i < list.size(); i++)
	{
		ans = ans + (list[i] + n >= t);
		t = max(t, list[i] + i + 1);
	}
	cout << ans;
	return 0;
}