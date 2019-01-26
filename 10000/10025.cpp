#include<iostream>
#include<algorithm>
typedef long long ll;
#define p pair<int, int>
const ll INF = 1e10;

using namespace std;

p list[100000];
ll psum[100001], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> list[i].second >> list[i].first;
	sort(list, list + n);
	for (int i = 0; i < n; ++i)
		psum[i + 1] = psum[i] + list[i].second;
	for (int i = 0; i < n; ++i)
	{
		int idx = upper_bound(list, list + n, p(list[i].first + 2*k, INF)) - list;
		ans = max(ans, psum[idx] - psum[i]);
	}
	cout << ans;
	return 0;
}