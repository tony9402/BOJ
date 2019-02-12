#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define p pair<int, int>
#define mp make_pair

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[1001][1001];
int dp[2][1001][1001];
const int INF = 0x3f3f3f3f;
queue<p> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	p s, e;
	memset(dp, 0x3F, sizeof(dp));
	cin >> n >> m;
	cin >> s.first >> s.second;
	cin >> e.first >> e.second;
	s.first--;
	s.second--;
	e.first--;
	e.second--;
	dp[0][s.first][s.second] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	q.push(s);

	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		
		if (now == e)
			continue;
		int ny = now.first;
		int nx = now.second;
		
		for (int i = 0; i < 4; i++)
		{
			int qy = ny + dy[i];
			int qx = nx + dx[i];

			if (0 > qy || qy >= n || 0 > qx || qx >= m)
				continue;

			if (map[qy][qx])
			{
				if (dp[1][qy][qx] > dp[0][ny][nx] + 1)
				{
					dp[1][qy][qx] = dp[0][ny][nx] + 1;
					q.push(mp(qy, qx));
				}
			}
			else
			{
				if (dp[0][qy][qx] > dp[0][ny][nx] + 1)
				{
					dp[0][qy][qx] = dp[0][ny][nx] + 1;
					q.push(mp(qy, qx));
				}
				if (dp[1][qy][qx] > dp[1][ny][nx] + 1)
				{
					dp[1][qy][qx] = dp[1][ny][nx] + 1;
					q.push(mp(qy, qx));
				}
			}
		}	
	}

	int ans = min(dp[0][e.first][e.second], dp[1][e.first][e.second]);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}