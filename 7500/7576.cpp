#include<iostream>
#include<queue>
#include<algorithm>
#define P pair<int, int>

using namespace std;

queue<P> q;
bool visit[1001][1001];
int map[1001][1001], ans;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
			else if (map[i][j] == -1)visit[i][j] = 1;
		}

	while (!q.empty())
	{
		int t = q.size();
		ans++;
		while (t--)
		{
			P now = q.front(); q.pop();
			int ny = now.first;
			int nx = now.second;

			for (int i = 0; i < 4; i++)
			{
				int qy = ny + dy[i];
				int qx = nx + dx[i];

				if (0 > qy || qy >= n || 0 > qx || qx >= m)continue;
				if (!visit[qy][qx] && !map[qy][qx])
				{
					q.push(make_pair(qy, qx));
					visit[qy][qx] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j])return cout << -1, 0;
	cout << ans - 1;
}