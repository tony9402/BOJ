#include<iostream>
#include<queue>
#include<algorithm>
#define p pair<int, int>
#define P pair<p, int>
#define mp make_pair

using namespace std;

queue<P> q;
int map[301][301];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int solve(int n, int m)
{
	int ans = 0;
	bool visit[301][301] = { false };
	queue<p> vq;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				++ans;
				vq.push(make_pair(i, j));
				visit[i][j] = true;
				while (!vq.empty())
				{
					int ny = vq.front().first;
					int nx = vq.front().second;
					vq.pop();

					for (int k = 0; k < 4; k++)
					{
						int qy = ny + dy[k];
						int qx = nx + dx[k];

						if (0 > qy || qy >= n || 0 > qx || qx >= m)
							continue;

						if (map[qy][qx] && !visit[qy][qx])
						{
							visit[qy][qx] = true;
							vq.push(make_pair(qy, qx));
						}
					}
				}
			}
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int count, ans=0;
	int f = solve(n, m);
	if (f > 1)return cout << 0, 0;

	int s = f;
	while (s == f)
	{
		++ans;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j])
				{
					count = 0;
					for (int k = 0; k < 4; k++)
					{
						int qy = i + dy[k];
						int qx = j + dx[k];
						if (0 > qy || qy >= n || 0 > qx || qx >= m)
							continue;
						if (!map[qy][qx])
							++count;
					}
					if (count)
						q.push(mp(mp(i, j), count));
				}
		
		while (!q.empty())
		{
			int ny = q.front().first.first;
			int nx = q.front().first.second;
			int nc = q.front().second;
			q.pop();
			map[ny][nx] = max(0, map[ny][nx] - nc);
		}
		s = solve(n, m);
		if (!s)return cout << 0, 0;
	}
	cout << ans;
	return 0;
}