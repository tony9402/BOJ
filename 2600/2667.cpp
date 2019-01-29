#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define P pair<int, int>
#define all(x) x.begin(), x.end()

using namespace std;

queue<P> q;
int map[25][25];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> ans;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			if (map[i][j])
			{
				int area = 0;
				map[i][j] = 0;
				q.push(make_pair(i, j));
				while (!q.empty())
				{
					++area;
					P now = q.front(); q.pop();
					int ny = now.first;
					int nx = now.second;

					for (int k = 0; k < 4; k++)
					{
						int qy = ny + dy[k];
						int qx = nx + dx[k];

						if (0 > qy || qy >= n || 0 > qx || qx >= n)continue;

						if (map[qy][qx])
						{
							map[qy][qx] = 0;
							q.push(make_pair(qy, qx));
						}
					}
				}
				ans.push_back(area);
			}
		}
	
	sort(all(ans));
	printf("%d\n", ans.size());
	for (auto i : ans)
		printf("%d\n", i);
}