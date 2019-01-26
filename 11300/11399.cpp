#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;

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

	sort(list.begin(), list.end());

	int ans = 0;
	for (int i = 0; i < list.size(); i++)
	{
		ans += (list.size() - i) * list[i];
	}

	cout << ans;
	return 0;
}