#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

vector<ll> vc;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int L, P, V;
	int count = 1;
	while (1)
	{
		cin >> L >> P >> V;
		if (!V && !P && !L)return 0;
		int ans = 0;
		while (V)
		{
			if (V >= P)
			{
				ans += L;
				V -= P;
			}
			else
			{
				if (V >= L)
					ans += L;
				else
					ans += V;
				break;
			}
		}
		cout << "Case " << count++ << ": " << ans << '\n';
	}

	return 0;
}