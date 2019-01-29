#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[101][101], ans=0;
queue<pair<int, int>> q;

bool check(int y, int x, int n, int m)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	
	q.push(make_pair(0, 0));
	map[0][0] = 0;

	while (!q.empty())
	{
		int t = q.size();
		ans++;
		while (t--)
		{
			pair<int, int> now = q.front(); q.pop();
			if (now.first == n - 1 && now.second == m - 1)
			{
				return !printf("%d", ans);
			}
			for (int i = 0; i < 4; i++)
			{
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];

				if (!check(ny, nx, n, m))continue;

				if (map[ny][nx])
				{
					map[ny][nx] = 0;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return 0;
}