#include<iostream>

using namespace std;
typedef long long ll;

double dp[50][50][50];
bool prime[100];
double a, b;

double solve(ll sa, ll sb, int time)
{
	if (time == 18)return (prime[sa] || prime[sb]);

	if (dp[sa][sb][time] > 0)return dp[sa][sb][time];
	double sum = 0;
	sum += a * b*solve(sa + 1, sb + 1, time + 1);
	sum += a * (1.0- b) * solve(sa + 1, sb, time + 1);
	sum += (1.0 - a) * b * solve(sa, sb + 1, time + 1);
	sum += (1.0 - a)*(1.0- b)*solve(sa, sb, time + 1);
	dp[sa][sb][time] = sum;
	return dp[sa][sb][time];
}

int main()
{
	for (int i = 0; i <= 50; i++)prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= 80; i++)
	{
		if (prime[i] == 0)continue;
		for (int j = i * i; j <= 80; j += i)prime[j] = 0;
	}
	cin >> a >> b;
	a /= 100.0;
	b /= 100.0;
	double result = solve(0, 0, 0);
	cout.precision(9);
	cout << result;
	return 0;
}