#include<iostream>
#include<queue>
#include<algorithm>
#define p pair<int,int>
#define mp make_pair

using namespace std;

int map[501][501];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<p> q;
int n, m;

bool available(int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int cnt = 0, ans=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j])
			{
				++cnt;
				int area = 0;
				q.push(mp(i, j));
				map[i][j] = 0;

				while (!q.empty())
				{
					area++;
					p now = q.front(); q.pop();
					int ny = now.first;
					int nx = now.second;

					for (int k = 0; k < 4; k++)
					{
						int qy = ny + dy[k];
						int qx = nx + dx[k];

						if (available(qy, qx))
						{
							if (map[qy][qx])
							{
								map[qy][qx] = 0;
								q.push(mp(qy, qx));
							}
						}
					}
				}
				ans = max(ans, area);
			}
	
	cout << cnt << '\n' << ans << '\n';
	return 0;
}