#include<iostream>
#include<queue>
#include<tuple>
#define p pair<int, int>
#define P pair<p,p>
#define mp make_pair

using namespace std;

int map[202][202];
bool visit[202][202][30];
int dx[] = { -1,0,0,1,-1,-2,-2,-1,1,2,2,1 };
int dy[] = { 0,1,-1,0,-2,-1,1,2,2,1,-1,-2 };
queue<P> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t >> m >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int ans = -1;
	visit[0][0][0] = true;
	q.push(mp(mp(0, 0), mp(0, 0)));
	while (!q.empty())
	{
		p now = q.front().first;
		p nn = q.front().second; q.pop();

		int ny = now.first;
		int nx = now.second;
		int nk = nn.first;
		int cnt = nn.second;

		if (ny == n - 1 && nx == m - 1)
		{
			ans = nn.second;
			break;
		}
		if (nk < t)
		{
			for (int i = 5; i < 12; i++)
			{
				int qy = dy[i] + ny;
				int qx = dx[i] + nx;
				if (0 > qy || qy >= n || 0 > qx || qx >= m)continue;
				if (!map[qy][qx] && !visit[qy][qx][nk+1])
				{
					visit[qy][qx][nk+1] = true;
					q.push(mp(mp(qy, qx), mp(nk + 1, cnt + 1)));
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int qy = dy[i] + ny;
			int qx = dx[i] + nx;
			if (0 > qy || qy >= n || 0 > qx || qx >= m)continue;
			if (!map[qy][qx] && !visit[qy][qx][nk])
			{
				visit[qy][qx][nk] = true;
				q.push(mp(mp(qy, qx), mp(nk, cnt + 1)));
			}
		}
	}

	cout << ans;
	return 0;
}