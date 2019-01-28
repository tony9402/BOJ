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
		if (i > m)ans += i - m;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;

	ll left =1 , right;
	for (int i = 0; i < n; i++)
	{
		ll input;
		cin >> input;
		if (!i)right = input;
		if (right < input)right = input;
		list.push_back(input);
	}

	ll ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll result = len(mid);
		if (result >= k)
		{
			ans = max(ans, mid);
			left = mid + 1;
		}
		else if (result < k)
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}