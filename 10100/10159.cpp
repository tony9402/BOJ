#include<iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int map[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	int from, to;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = INF;

	for (int i = 0; i < k; i++)
	{
		cin >> from >> to;
		map[from][to] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (j == k || k == i || i == j)continue;
				else if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j]==1)
				map[j][i] = 1;

	int count;
	for (int i = 1; i <= n; i++)
	{
		count = 0;
		for (int j = 1; j <= n; j++)
			if (i == j)
				continue;
			else if(map[i][j] == INF)
				count++;
		cout << count << '\n';
	}
	return 0;
}