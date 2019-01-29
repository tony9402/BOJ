#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#define P pair<int, pair<int, int>>

using namespace std;

queue<P> q;
vector<vector<string>> map;
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		bool escape = false;
		int n, m, k;
		cin >> k >> n >> m;
		if (!k && !n && !m)break;
		map.clear();
		q = queue<P>();
		map.resize(k);
		bool check = false;
		for (int i = 0; i < k; i++)
		{
			map[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				string input;
				cin >> input;
				map[i][j] = input;
				if (!check)
					for (int a = 0; a < m; a++)
						if (map[i][j][a] == 'S')
							q.push(make_pair(i, make_pair(j, a)));
			}
		}

		int ans = 0;
		while (!q.empty())
		{
			int t = q.size();
			ans++;
			while (t--)
			{
				P now = q.front(); q.pop();
				int nz = now.first;
				int ny = now.second.first;
				int nx = now.second.second;

				for (int i = 0; i < 6; i++)
				{
					int qz = nz + dz[i];
					int qy = ny + dy[i];
					int qx = nx + dx[i];

					if (0 > qz || 0 > qy || 0 > qx || qz >= k || qy >= n || qx >= m)continue;

					if (map[qz][qy][qx] == 'E')
					{
						cout << "Escaped in " << ans << " minute(s).\n";
						escape = true;
						break;
					}

					if (map[qz][qy][qx] == '.')
					{
						map[qz][qy][qx] = '#';
						q.push({ qz,{qy,qx} });
					}
				}
				if (escape)break;
			}
			if (escape)break;
		}
		if (escape)continue;
		cout << "Trapped!\n";
	}
}