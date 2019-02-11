#include<iostream>
#include<queue>
#include<vector>
#define p pair<int, int>
#define mp make_pair

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;

vector<vector<p>> map;
priority_queue<p> pq;

ll city[1001], city2[1001];
bool visit[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, start;
	int from, to, time;
	cin >> n >> m >> start;
	map.resize(n + 1);
	for (int i = 0; i <= n; i++)
		city2[i] = city[i] = INF;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> time;
		int j;
		for (j=0; j < map[from].size(); j++)
		{
			if (map[from][j].first == to)
			{
				map[from][j].second = map[from][j].second > time ? time : map[from][j].second;
				break;
			}
		}
		if (j >= map[from].size())
			map[from].push_back(mp(to, time));
	}

	pq.push(mp(0,start));
	city[start] = 0;
	while (!pq.empty())
	{
		int qt = pq.top().second;
		pq.pop();
		for (auto i : map[qt])
		{
			if (city[i.first] > city[qt] + i.second)
			{
				city[i.first] = city[qt] + i.second;
				pq.push(mp(-city[i.first],i.first));
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		pq.push(mp(0,i));
		for (int j = 0; j <= n; j++)city2[j] = INF;
		city2[i] = 0;
		while (!pq.empty())
		{
			int qt = pq.top().second;
			pq.pop();
			for (auto k : map[qt])
			{
				if (city2[k.first] > city2[qt] + k.second)
				{
					city2[k.first] = city2[qt] + k.second;
					pq.push(mp(-city2[k.first],k.first));
				}
			}
		}
		city[i] += city2[start];
	}

	ll maxi = 0;
	for (int i = 1; i <= n; i++)
		maxi = max(city[i], maxi);
	cout << maxi;
	return 0;
}