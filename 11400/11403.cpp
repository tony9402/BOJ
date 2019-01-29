#include<iostream>

#define INF 12345

using namespace std;

bool visit[101][101] = { false };
int map[101][101] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, input;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			map[i][j] = input ? 1 : INF;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (map[i][j] != INF) << ' ';
		}
		cout << '\n';
	}
	return 0;
}