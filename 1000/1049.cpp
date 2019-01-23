#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int mini1 = 10000, mini2=10000;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		mini1 = min(mini1, a);
		mini2 = min(mini2, b);
	}
	if (n < 6)return cout << min(mini1, mini2*n), 0;
	mini1 = min(mini1, mini2 * 6);
	cout << n / 6 * mini1 + min(n % 6 * mini2, mini1);
	return 0;
}