#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> map;
vector<bool> visit;
queue<int> q;

int n, m, s;

void dfs(int n)
{
	visit[n] = true;
	cout << n << ' ';
	for (int i = 0; i < map[n].size(); i++)
		if (!visit[map[n][i]])
			dfs(map[n][i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	map.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		map[y].push_back(x);
		map[x].push_back(y);
	}

	for (int i = 0; i <= n; i++)sort(map[i].begin(), map[i].end());

	dfs(s);

	cout << '\n';

	visit.clear();
	visit.resize(n + 1);

	q.push(s);
	visit[s] = true;

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		cout << now << ' ';
		for (auto i : map[now])
		{
			if (!visit[i])
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}
