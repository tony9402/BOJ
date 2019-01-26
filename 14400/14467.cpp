#include<iostream>
#include<cstring>

using namespace std;

int visit[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(visit, -1, sizeof(visit));
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		--a;
		if (visit[a] < 0)visit[a] = b;
		else if (visit[a] != b)visit[a] = b, count++;
	}
	cout << count;
	return 0;
}