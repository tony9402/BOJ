#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define p pair<int, int>
#define mp make_pair

using namespace std;
const int INF = 0x3f3f3f3f;

vector<vector<p>> map;
vector<int> cost;
queue<int> q;

int main()
{
	int T;
	cin >> T;
	for (; T--;)
	{
		int n, m, k;
		cin >> n >> m >> k;
		map.clear();
		cost.clear();
		map.resize(n + 1);
		cost.resize(n + 1);
		int cycle[555] = { 0 };
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back(mp(b, c));
			map[b].push_back(mp(a, c));
		}
		for (int j = 0; j < k; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back(mp(b, -c));
		}
		q.push(1);
		fill(cost.begin(), cost.end(), INF);
		cost[1] = 0;
		cycle[1]++;

		bool check = false;
		while (!q.empty())
		{
			int qt = q.front();
			q.pop();

			for (auto i : map[qt])
			{
				int nt = i.first;
				int nc = i.second;
				if (cost[nt] > cost[qt] + nc)
				{
					cost[nt] = cost[qt] + nc;
					cycle[nt]++;
					if (cycle[nt] < n)q.push(nt);
					else check = true;
				}
			}
		}
		cout << (check ? "YES" : "NO") << '\n';
	}
	return 0;
}