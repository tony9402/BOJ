#include<iostream>
using namespace std;
bool visit[2000000];
int num[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> num[i];
	for (int i = 0; i < n; i++)
		for (int j = num[i]; j <= k; j += num[i])
			visit[j] = 1;
	int ans = 0;
	for (int i = 0; i <= k; i++)
		if (visit[i])++ans;
	cout << ans;
	return 0;
}