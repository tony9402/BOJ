#include<iostream>
#include<queue>
#include<algorithm>
#define all(x) x.begin(), x.end()

using namespace std;

int map[105][105];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int> ans;
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = 1;

	for (; t--;)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				map[i][j] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j])
			{
				int area = 0;
				q.push(make_pair(i, j));
				map[i][j] = 0;
				while (!q.empty())
				{
					++area;
					auto now = q.front(); q.pop();

					for (int k = 0; k < 4; k++)
					{
						int ny = now.first + dy[k];
						int nx = now.second + dx[k];
						if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;

						if (map[ny][nx])
						{
							map[ny][nx] = 0;
							q.push(make_pair(ny, nx));
						}
					}
				}
				ans.push_back(area);
			}
		}
	}

	sort(all(ans));
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
