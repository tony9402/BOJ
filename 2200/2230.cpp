#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

vector<ll> list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		ll input;
		cin >> input;
		list.push_back(input);
	}

	sort(list.begin(), list.end());

	ll ans = 0x7FFFFFFFFFFFFFFF;
	for (int i = 0; i < list.size(); i++)
	{
		int idx = upper_bound(all(list), list[i] + m - 1) - list.begin();
		if (idx >= list.size())break;
		ans = min(ans, list[idx] - list[i]);
	}
	cout << ans;
	return 0;
}