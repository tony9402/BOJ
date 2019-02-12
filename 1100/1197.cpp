#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define _p pair<int, int>
#define p pair<int, _p>
#define mp make_pair

using namespace std;

p vc[100001];
int tree[10001];

int find(int a)
{
	if (tree[a] < 0)return a;
	return tree[a] = find(tree[a]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a==b)return false;
	tree[b] = a;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	memset(tree, -1, sizeof(tree));
	for (int i = 0; i < m; i++)
		cin >> vc[i].second.first >> vc[i].second.second >> vc[i].first;
	sort(vc, vc + m);

	int ans = 0, cnt = 0;
	for (auto &i : vc)
	{
		int a = i.second.first;
		int b = i.second.second;
		int c = i.first;
		if (merge(a, b))
		{
			ans += c;
			if (++cnt == n - 1)break;
		}
	}
	cout << ans;
	return 0;
}