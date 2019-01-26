#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list, ans;

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

	for (int i = n - 1; i >= 0; i--)ans.insert(ans.begin() + list[i], i + 1);
	for (auto i : ans)cout << i << ' ';
	return 0;
}