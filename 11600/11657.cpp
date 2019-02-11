#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define mp make_pair
#define p pair<int, int>

using namespace std;

const int INF = 0x3f3f3f3f;
vector<vector<p>> map;
queue<int> q;
vector<int> cost;
vector<int> cycle;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map.resize(n + 1);
	cost.resize(n + 1);
	cycle.resize(n + 1);
	fill(cost.begin(), cost.end(), INF);
	fill(cycle.begin(), cycle.end(), 0);
	int f, e, c;
	for (int i = 0; i < m; i++)
	{
		cin >> f >> e >> c;
		int j;
		for (j = 0; j < map[f].size(); j++)
		{
			if (map[f][j].first == e)
			{
				if (map[f][j].second > c)
				{
					map[f][j].second = c;
				}
				break;
			}
		}
		if (j >= map[f].size())
		{
			map[f].push_back(make_pair(e, c));
		}
	}

	q.push(1);
	cycle[1]++;
	cost[1] = 0;

	bool cycle_check = false;
	while (!q.empty())
	{
		int qt = q.front();
		q.pop();

		for (int i = 0; i < map[qt].size(); i++)
		{
			int nt = map[qt][i].first;
			int nc = map[qt][i].second;
			if (cost[nt] > cost[qt] + nc)
			{
				cost[nt] = cost[qt] + nc;
				cycle[nt]++;
				if (cycle[nt] < n)q.push(nt);
				else cycle_check = true;
			}
		}
	}

	if (cycle_check)
		return cout << -1, 0;

	for (int i = 2; i <= n; i++)
		cout << (cost[i] >= INF ? -1 : cost[i]) << '\n';

	return 0;
}