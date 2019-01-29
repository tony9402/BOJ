#include<iostream>
#include<vector>

using namespace std;

vector<int> list;
int output[6];

void solve(int n, int now, int k)
{
	if (!k)
	{
		for (int i = 0; i < 6; i++)
			cout << output[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = now + 1; i < n; i++)
	{
		output[6-k] = list[i];
		solve(n, i, k - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{ 
		int n;
		cin >> n;
		if (!n)break;
		list.clear();
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			list.push_back(input);
		}
		solve(n, -1, 6);
		cout << '\n';
	}
	return 0;
}
