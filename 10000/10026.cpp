#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

vector<string> map;
vector<vector<bool>> visit;
queue<pair<int, int>> q;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool check(int y, int x, int n)
{
	return (0 <= y && y < n && 0 <= x && x < n);
}

int bfs(int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				ans++;
				char now = map[i][j];

				q.push(make_pair(i, j));
				visit[i][j] = true;

				while (!q.empty())
				{
					pair<int, int> nw = q.front();
					q.pop();
					int ny = nw.first;
					int nx = nw.second;

					for (int k = 0; k < 4; k++)
					{
						int qy = ny + dy[k];
						int qx = nx + dx[k];

						if (!check(qy, qx, n))continue;
						if (!visit[qy][qx] && map[qy][qx] == now)
						{
							q.push(make_pair(qy, qx));
							visit[qy][qx] = 1;
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
	int n;
	cin >> n;
	visit.resize(n);
	for (int i = 0; i < n; i++)
	{
		visit[i].resize(n);
		string input;
		cin >> input;
		map.push_back(input);
	}

	cout << bfs(n) << ' ';

	visit.clear();
	visit.resize(n);
	for (int i = 0; i < n; i++)
		visit[i].resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G')map[i][j] = 'R';
		}
	}
	cout << bfs(n);
	return 0;
}