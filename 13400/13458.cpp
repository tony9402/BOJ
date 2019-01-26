#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

vector<ll> list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll input;
		cin >> input;
		list.push_back(input);
	}
	ll a, b;
	cin >> a >> b;

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll now = list[i] - a;
		ans++;
		if (now < 0)continue;
		if (now % b == 0)ans += now / b;
		else ans = ans + now / b + 1;
	}
	cout << ans;
	return 0;
}