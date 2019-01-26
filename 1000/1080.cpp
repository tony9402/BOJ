#include<cstdio>

bool map[100][100];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int k;
			scanf("%1d", &k);
			map[i][j] = 1 - (map[i][j] == k);
		}
	}

	int ans = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (!map[i][j])continue;
			++ans;
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++)
					map[i + k][j + l] = 1 - map[i + k][j + l];
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j])
				return !printf("%d", -1);

	printf("%d", ans);
	return 0;
}