#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int len = b.size() - a.size();
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= len; i++)
	{
		int cnt = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] != b[i + j])cnt++;
		}
		ans = min(cnt, ans);
	}
	cout << ans;
	return 0;
}