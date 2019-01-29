#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define _P pair<int, int>
#define P pair<_P, int>
#define mp make_pair

using namespace std;

vector<vector<int> > map;
queue<P> q;
bool visit[400][400] = { 0 };

int dir[8][2] = 
{
{-1,-2},
{-2,-1},
{-2,1},
{-1,2},
{1,-2},
{2,-1},
{1,2},
{2,1} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int sy, sx, ey, ex, n;
		cin >> n >> sy >> sx >> ey >> ex;
		
		q = queue<P>();
		q.push(mp(mp(sy, sx), 0));
		memset(visit, 0, sizeof(visit));
		visit[sy][sx] = 1;

		while (!q.empty())
		{
			int ny = q.front().first.first;
			int nx = q.front().first.second;
			int cnt = q.front().second; q.pop();

			if (ny == ey && nx == ex)
			{
				cout << cnt << '\n';
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				int qy = dir[i][1] + ny;
				int qx = dir[i][0] + nx;
				if (0 > qy || qy >= n || 0 > qx || qx >= n)continue;
				if (!visit[qy][qx])
				{
					visit[qy][qx] = true;
					q.push(mp(mp(qy, qx), cnt + 1));
				}
			}
		}
	}
}