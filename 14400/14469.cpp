#include<iostream>
#include<algorithm>
#define P pair<int, int>

using namespace std;

P p[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n;i++)cin >> p[i].first >> p[i].second;
	sort(p, p + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (p[i].first < ans)
			ans += p[i].second;
		else
			ans = p[i].first + p[i].second;
	cout << ans;
	return 0;
}