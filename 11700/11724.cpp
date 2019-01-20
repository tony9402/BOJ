#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int> > map;
vector<bool> visit;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	int from, to;
	cin >> n >> m;
	map.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		map[from].push_back(to);
		map[to].push_back(from);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		count++;
		q.push(i);
		visit[i] = true;
		while (!q.empty())
		{
			int qt = q.front();
			q.pop();

			for (int j = 0; j < map[qt].size(); j++) {
				if (!visit[map[qt][j]]) {
					q.push(map[qt][j]);
					visit[map[qt][j]] = true;
				}
			}
		}
	}

	cout << count;
}