#include<iostream>
#include<queue>
#include<algorithm>
#define p pair<int,int>
#define P pair<p,p>
#define mp make_pair

using namespace std;

queue<P> q;
int map[1001][1001];
bool visit[11][1001][1001];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,1,-1,0 };

int main()
{
	int n, m, k, ans = 10e7;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	visit[0][0][0] = true;
	q.push(mp(mp(0, 0), mp(0, 0)));
	while (!q.empty())
	{
		p now = q.front().first;
		p nn = q.front().second; q.pop();

		int ny = now.first;
		int nx = now.second;
		int nt = nn.first;
		int nc = nn.second;
		if (ny == n - 1 && nx == m - 1)
			ans = min(ans, nt);

		for (int i = 0; i < 4; i++)
		{
			int qy = ny + dy[i];
			int qx = nx + dx[i];
			if (0 > qy || qy >= n || 0 > qx || qx >= m)
				continue;

			if (!map[qy][qx] && !visit[nc][qy][qx])
			{
				visit[nc][qy][qx] = true;
				q.push(mp(mp(qy, qx), mp(nt + 1, nc)));
			}
			if (nc < k)
			{
				if (map[qy][qx] && !visit[nc + 1][qy][qx])
				{
					visit[nc + 1][qy][qx] = true;
					q.push(mp(mp(qy, qx), mp(nt + 1, nc + 1)));
				}
			}
		}
	}
	printf("%d",ans == 10e7 ? -1 : ans + 1);
	return 0;
}