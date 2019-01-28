#include<iostream>
#include<vector>
#include<algorithm>

#define all(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

vector<ll> list;
vector<ll> ans;

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
	sort(list.begin(), list.end());
	cin >> n;

	for (int i=0;i<n;i++)
	{
		ll input;
		cin >> input;
		cout << upper_bound(all(list), input) - lower_bound(all(list), input);
		cout << ' ';
	}

	return 0;
}