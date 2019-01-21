#include<cstdio>
#include<vector>

using namespace std;

typedef long long ll;
vector<int> vc;

ll gcd(ll a, ll b)
{
	if (!b)return a;
	else return gcd(b, a%b);
}

int main()
{
	ll n, t, input;
	ll ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ans = 0;
		vc.clear();
		scanf("%lld", &t);
		for (; t--; )
		{
			scanf("%lld", &input);
			vc.push_back(input);
		}
		for (int j = 0; j < vc.size() - 1; j++)
		{
			for (int k = j + 1; k < vc.size(); k++)
			{
				ans += gcd(vc[j], vc[k]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}