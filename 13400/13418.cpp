#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define _p pair<int, int>
#define p pair<int, _p>
#define mp make_pair

using namespace std;

int s[1001];
vector<p> list;

int find(int a)
{
	if (s[a] < 0)return a;
	return s[a] = find(s[a]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)return false;
	s[b] = a;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans1=0, ans2 = 0;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		list.push_back(mp(1-c, mp(a, b)));
	}

	sort(list.begin(), list.end());
	memset(s, -1, sizeof(s));
	for (int i = 0; i < list.size(); i++)
	{
		int a = list[i].second.first;
		int b = list[i].second.second;
		int c = list[i].first;

		if (merge(a, b))
			ans1 += c;
	}
	memset(s, -1, sizeof(s));
	for (int i = list.size()-1; i >= 0; i--)
	{
		int a = list[i].second.first;
		int b = list[i].second.second;
		int c = list[i].first;

		if (merge(a, b))
			ans2 += c;
	}
	cout << abs(ans2 * ans2 - ans1 * ans1);
	return 0;
}