#include<iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int map[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int f, t;
		cin >> f >> t;
		map[f][t] = map[t][f] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	int ans = INF;
	int temp;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			if (map[i][j] != INF)sum += map[i][j];
		}
		if (ans > sum)
		{
			ans = sum;
			temp = i;
		}
	}
	cout << temp;
	return 0;
}