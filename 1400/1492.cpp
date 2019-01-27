#include<iostream>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll a[55][55], b[55][55], c[55];

ll pow(ll a, ll b)
{
	if (!b)return 1;
	if (b == 1)return a % mod;
	ll result = pow(a, b / 2);
	if (b & 1)return (((a*result) % mod)*result) % mod;
	return (result * result) % mod;
}

int main()
{
	ll n, k;
	cin >> n >> k;

	a[0][0] = a[1][0] = a[1][1] = 1;
	for (int i = 2; i <= k + 1; i++)
	{
		a[i][0] = 1;
		for (int j = 1; j <= i; j++)
			a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % mod;
	}
	c[0] = n % mod;
	for (int j = 1; j <= k + 1; j++)
		b[0][j] = (c[0] * a[j][0]) % mod;
	for (int i = 1; i <= k; i++)
	{
		ll d = n + 1;
		for (int j = 2; j <= i + 1; j++)
			d = (d * (n + 1)) % mod;
		d--;
		if (d < 0)d += mod;
		for (int j = 0; j < i; j++)
			d = (d - b[j][i + 1] + mod) % mod;
		c[i] = (d * pow(a[i + 1][i], mod - 2)) % mod;
		for (int j = i; j <= k + 1; j++)
			b[i][j] = (c[i] * a[j][i]) % mod;
	}
	cout << c[k];
	return 0;
}