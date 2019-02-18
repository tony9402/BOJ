#include<iostream>

using namespace std;
typedef long long ll;
const int MAX = 1e6 + 5;
ll Tree[MAX], add[MAX], mul[MAX];
ll input[MAX];
int n,m,k;

void update(int l, ll mu, ll ad)
{
	for (int i = l; i <= n; i += i & -i)
	{
		add[i] += ad;
		mul[i] += mu;
	}
}

void range_update(int l, int r, ll x)
{
	update(l, x, (l - 1)*-x);
	update(r + 1, -x, x*r);
}

ll Sum(int k)
{
	ll reta = 0, retm = 0;
	for (int i = k; i; i -= i & -i)
	{
		retm += mul[i];
		reta += add[i];
	}
	return retm * k + reta;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
		range_update(i, i, input[i]);
	}

	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		ll d;
		cin >> a >> b >> c;
		if (a == 1)
		{
			cin >> d;
			range_update(b, c, d);
		}
		else
		{
			cout << Sum(c) - Sum(b - 1) << '\n';
		}
	}
	return 0;
}