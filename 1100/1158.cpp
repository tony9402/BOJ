#include<bits/stdc++.h>

using namespace std;

vector<int> vc;
vector<int> ans;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)vc.push_back(i + 1);
	int pointer = m - 1;
	while (vc.size() > 1)
	{
		ans.push_back(vc[pointer]);
		vc.erase(vc.begin() + pointer);
		pointer = (pointer + m - 1) % vc.size();
	}
	ans.push_back(vc[0]);
	cout << '<';
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != ans.size() - 1)
		{
			cout << ans[i] << ", ";
		}
		else
		{
			cout << ans[i];
		}
	}
	cout << '>';
	return 0;
}