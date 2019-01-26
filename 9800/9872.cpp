#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<string>> list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<string> in;
		for (int j = 0; j < 3; j++)
		{
			string input;
			cin >> input;
			in.push_back(input);
		}
		sort(in.begin(), in.end());
		list.push_back(in);
	}

	sort(list.begin(), list.end());
	int ans = 0;

	for (int i = 0; i < list.size(); i++)
	{
		int count = 1;
		for (int j = i + 1; j < list.size(); j++)
		{
			int k;
			for (k = 0; k < 3; k++)
				if (list[i][k].compare(list[j][k]))break;
			if (k >= 3)++count;
		}
		ans = max(count, ans);
	}
	cout << ans;
	return 0;
}