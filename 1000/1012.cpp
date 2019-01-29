#include<iostream>
#include<cstring>
#include<queue>
#define P pair<int, int>

using namespace std;

queue<P> q;
int map[50][50];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k, cnt = 0;
		cin >> n >> m >> k;
		memset(map, 0, sizeof(map));
		int y, x;
		for (int i = 0; i < k; i++)
		{
			cin >> y >> x;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (map[i][j])
				{
					int area = 0;
					map[i][j] = 0;
					q.push(make_pair(i, j));
					++cnt;
					while (!q.empty())
					{
						P now = q.front(); q.pop();
						int ny = now.first;
						int nx = now.second;

						for (int k = 0; k < 4; k++)
						{
							int qy = ny + dy[k];
							int qx = nx + dx[k];

							if (0 > qy || qy >= n || 0 > qx || qx >= m)continue;

							if (map[qy][qx])
							{
								map[qy][qx] = 0;
								q.push(make_pair(qy, qx));
							}
						}
					}
				}
			}
		cout << cnt << '\n';
	}
}