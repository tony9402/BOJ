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

	int k;
	cin >> k;

	for (int i = 0; i < n && k > 0; i++)
	{
		int idx;
		int now = -1;
		for (int j = i, m = 0; j < n&&m <= k; j++, m++)
		{
			if (now < list[j])
			{
				now = list[j];
				idx = j;
			}
		}
		for (int j = idx; j > i&&k > 0; j--)
		{
			swap(list[j], list[j - 1]);
			k--;
		}
	}

	for (auto i : list)cout << i << ' ';

	return 0;
}
