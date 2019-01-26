#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool prime[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 3; i < 1001; i += 2)
	{
		if (prime[i/2])continue;
		for (int j = i * i; j <= 1000001; j += i * 2)
			prime[j / 2] = 1;
	}

	while (1)
	{
		int n;
		bool check = false;
		cin >> n;
		if (!n)return 0;
		for (int i = 3;; i += 2)
		{
			if (!prime[i / 2] && !prime[(n - i) / 2])
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}
	return 0;
}