#include<iostream>
#include<cstring>

using namespace std;

int arr[100001], visit[100001], c[100001];

int dfs(int s, int now, int dep)
{
	visit[now] = dep;
	c[now] = s;

	int nt = arr[now];
	if (!visit[nt])
		return dfs(s, nt, dep + 1);
	else if (visit[nt] && s == c[nt])
		return dep - visit[nt] + 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(visit, 0, sizeof(visit));
		int ans = 0;

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++)
			if (visit[i])continue;
			else if (!visit[arr[i]])
				ans += dfs(i, i, 1);
		cout << n - ans << '\n';
	}
	return 0;
}