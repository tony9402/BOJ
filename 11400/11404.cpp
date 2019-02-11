#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int map[101][101] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if(i!=j)
				map[i][j] = INF;

	int from, to, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to >> cost;
		map[from][to] = map[from][to] > cost ? cost : map[from][to];
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if(i!=j)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << (map[i][j] == INF ? 0 : map[i][j]) << ' ';
		cout << '\n';
	}
	return 0;
}