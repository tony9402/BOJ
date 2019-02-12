#include<iostream>
#include<tuple>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

#define GET(x,a) get<a>(x)
#define T tuple<int,int,int>
#define mt make_tuple

using namespace std;

priority_queue<T, vector<T>, greater<T>> pq;
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
		pq.push(mt(c, a, b));
	}

	int ans = 0, cnt = 0;
	while (!pq.empty())
	{
		T now = pq.top(); pq.pop();
		if (merge(GET(now, 1), GET(now, 2)))
		{
			ans += GET(now, 0);
			if (++cnt == n - 1)break;
		}
	}
	cout << ans;
	return 0;
}