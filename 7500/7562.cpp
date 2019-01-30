#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#define p pair<int, int>

using namespace std;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
bool visit[301][301];
queue<p> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (; t--;)
	{
		int n;
		cin >> n;
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		memset(visit, 0, sizeof(visit));
		q = queue<p>();
		q.push(make_pair(sy, sx));
		visit[sy][sx] = true;
		int count = 0;
		bool check = false;
		while (!q.empty())
		{
			int qsize = q.size();
			++count;
			while (qsize--)
			{
				auto now = q.front(); q.pop();
				int ny = now.first;
				int nx = now.second;
				if (ny == ey && nx == ex)
				{
					cout << count - 1 << '\n';
					check = true;
					break;
				}
				
				for (int i = 0; i < 8; i++)
				{
					int qy = ny + dy[i];
					int qx = nx + dx[i];

					if (0 > qy || qy > n || 0 > qx || qx >= n)continue;

					if (!visit[qy][qx])
					{
						q.push(make_pair(qy, qx));
						visit[qy][qx] = true;
					}
				}
			}
			if (check)break;
		}
	}

	return 0;
}