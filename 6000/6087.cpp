#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#define p pair<int, int>
#define P pair<p,int>
#define _mp make_pair
#define mp(a,b,c) _mp(_mp(a,b), c)

using namespace std;

vector<string> map;
vector<p> pos;
queue<P> q;
int visit[4][101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
const int INF = 0x3F3F3F3F;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> m >> n;

	map.resize(n);
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		map[i] = input;
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'C')
				pos.push_back(_mp(i, j));
	}
	int sy = pos[0].first;
	int sx = pos[0].second;
	int ey = pos[1].first;
	int ex = pos[1].second;

	for (int i = 0; i < 4; i++)
	{
		visit[i][sy][sx] = 1;
		q.push(mp(sy, sx, i));
	}
	
	while (!q.empty())
	{
		P now = q.front(); q.pop();
		int ny = now.first.first;
		int nx = now.first.second;
		int nc = now.second;

		for (int i = 0; i < 4; i++)
		{
			int qy = ny + dy[i];
			int qx = nx + dx[i];

			if (0 > qx || qx >= m || 0 > qy || qy >= n)
				continue;

			if (map[qy][qx] != '*')
			{
				int &f = visit[i][qy][qx];
				int &s = visit[nc][ny][nx];

				if (f&&f <= s)continue;
				f = s + 1;
				if (nc == i)f--;
				q.push(mp(qy, qx, i));
			}
		}
	}

	int ans = visit[0][ey][ex];
	ans = ans ? ans : 1e8;
	for (int i = 1; i < 4; i++)
	{
		int a = visit[i][ey][ex];
		if (!a)continue;
		ans = min(a, ans);
	}
	cout << ans - 1;
	return 0;
}