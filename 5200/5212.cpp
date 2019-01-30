#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<string> map;
char ans[15][15];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	map.resize(n);

	for (int i = 0; i < n; i++)
		cin >> map[i];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
			{
				int count = 0;
				int check = 0;
				for (int k = 0; k < 4; k++)
				{
					int qy = i + dy[k];
					int qx = j + dx[k];
					if (0 > qy || qy >= n || 0 > qx || qx >= m)
					{
						check++;
						continue;
					}

					if (map[qy][qx] == '.')
						++count;
				}
				if (count + check >= 3)
				{
					ans[i][j] = '.';
				}
				else
				{
					ans[i][j] = 'X';
				}
			}
			else
			{
				ans[i][j] = '.';
			}
		}
	}

	int top = 20, bottom=-1, left = 20, right = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ans[i][j] == 'X')
			{
				top = min(top, i);
				bottom = max(bottom, i);
				left = min(left, j);
				right = max(right, j);
			}
		}
	}
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}