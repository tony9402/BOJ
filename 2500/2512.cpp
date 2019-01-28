#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

vector<ll> list;

ll len(ll m)
{
	ll ans = 0;
	for (auto i : list)
	{
		if (i > m)ans += m;
		else ans += i;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll left = 1, right;
	for (int i = 0; i < n; i++)
	{
		ll input;
		cin >> input;
		if (!i)right = input;
		right = max(right, input);
		list.push_back(input);
	}

	ll k;
	cin >> k;

	ll ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll r = len(mid);

		if (r > k)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
	}
	cout << ans;
	return 0;
}