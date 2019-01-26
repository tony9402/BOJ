#include<iostream>
#include<algorithm>

using namespace std;

int map[1001][3] = { 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	for (int i = 1; i < n; i++)
	{
		map[i][0] += min(map[i - 1][1], map[i - 1][2]);
		map[i][1] += min(map[i - 1][0], map[i - 1][2]);
		map[i][2] += min(map[i - 1][0], map[i - 1][1]);
	}

	cout << min(min(map[n - 1][0], map[n - 1][1]), map[n - 1][2]);
	return 0;
}