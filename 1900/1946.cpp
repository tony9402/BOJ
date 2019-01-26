#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > vc;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (; T--;)
	{
		int n;
		cin >> n;
		vc.clear();
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			vc.push_back(make_pair(a,b));
		}

		sort(vc.begin(), vc.end());

		int now = vc[0].second;
		int ans = 1;

		for (int i = 1; i < n; i++)
		{
			if (now > vc[i].second)
			{
				now = vc[i].second;
				ans++;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}