#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define p pair<int,int>
#define mp make_pair

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[1001][1001];
int dp[1001][1001];
queue<p> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2 || !map[i][j])
			{
				dp[i][j] = 0;
				if(map[i][j])
					q.push(mp(i, j));
			}
		}
	}

	while (!q.empty())
	{
		p now = q.front();
		q.pop();
		int ny = now.first;
		int nx = now.second;

		for (int i = 0; i < 4; i++)
		{
			int qy = ny + dy[i];
			int qx = nx + dx[i];

			if (0 > qy || qy >= n || 0 > qx || qx >= m)
				continue;

			if (map[qy][qx] && dp[qy][qx] > dp[ny][nx] + 1)
			{
				q.push(mp(qy, qx));
				dp[qy][qx] = dp[ny][nx] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dp[i][j] == 0x3f3f3f3f)
				cout << -1 << ' ';
			else
				cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}