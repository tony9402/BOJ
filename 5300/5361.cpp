#include<iostream>

using namespace std;
typedef long long ll;

const ll list[] = { 35034,23090,19055,12530,18090 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll input, ans = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> input;
			ans += list[j] * input;
		}
		cout << fixed;
		cout.precision(2);
		cout << "$" << ans / 100.00 << '\n';
	}
	return 0;
}