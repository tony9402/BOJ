#include<iostream>
#include<tuple>
#include<cstring>
#include<vector>
#include<algorithm>

#define GET(x,a) get<a>(x)
#define T tuple<int,int,int>
#define mt make_tuple

using namespace std;

vector<T> vc;
int tree[10001];

int find(int a)
{
	if (tree[a] < 0)
		return a;
	return find(tree[a]);
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
	{
		int a, b, c;
		cin >> a >> b >> c;
		vc.push_back(mt(c, a, b));
	}

	sort(vc.begin(), vc.end());

	int ans = 0, cnt = 0;
	for (auto i : vc)
		if (merge(GET(i, 1), GET(i, 2)))
		{
			ans += GET(i, 0);
			if (++cnt == n - 1)break;
		}

	cout << ans;
	return 0;
}