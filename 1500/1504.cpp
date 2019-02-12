#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define p pair<int, int>
#define mp make_pair

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
vector<vector<p>> map;

ll dijkstra(int s, int e, int n)
{
	priority_queue<p> pq;
	vector<int> cost;
	cost.resize(n + 1);
	fill(cost.begin(), cost.end(), INF);

	cost[s] = 0;
	pq.push(mp(0, s));

	while (!pq.empty())
	{
		p now = pq.top(); pq.pop();
		int qt = now.second;

		for (auto i : map[qt])
		{
			int nt = i.first;
			int nc = i.second;

			if (cost[nt] > cost[qt] + nc)
			{
				cost[nt] = cost[qt] + nc;
				pq.push(mp(-cost[nt], nt));
			}
		}
	}
	return (ll)cost[e];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(mp(b, c));
		map[b].push_back(mp(a, c));
	}
	int a, b;
	cin >> a >> b;

	ll ans = INF;
	ans = min(ans, dijkstra(1, a, n) + dijkstra(b, n, n) + dijkstra(a, b, n));
	ans = min(ans, dijkstra(1, b, n) + dijkstra(a, n, n) + dijkstra(a, b, n));

	cout << (ans == INF ? -1 : ans);
	return 0;
}