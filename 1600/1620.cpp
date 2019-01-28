#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#define all(x) x.begin(),x.end()

using namespace std;

map<string, int> mp;
vector<pair<int, string>> list2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		string in;
		cin >> in;
		mp[in] = i;
		list2.push_back(make_pair(i, in));
	}

	for (int i = 0; i < k; i++)
	{
		string in;
		cin >> in;
		if ('0' <= in[0] && in[0] <= '9')
		{
			int num = 0;
			for (auto j : in)
			{
				num = num * 10 + j - '0';
			}
			cout << list2[num - 1].second << '\n';
		}
		else
		{
			cout << mp[in] << '\n';
		}
	}

	return 0;
}