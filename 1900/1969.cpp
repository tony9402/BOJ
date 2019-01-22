#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string input;
int cnt[5][1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int k = 0;k<input.size();k++)
		{
			char j = input[k];
			switch (j)
			{
			case 'A':
				cnt[0][k]++;
				break;
			case 'C':
				cnt[1][k]++;
				break;
			case 'G':
				cnt[2][k]++;
				break;
			case 'T':
				cnt[3][k]++;
				break;
			}
		}
	}

	const char save[] = { 'A','C','G','T' };
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int maxi = 0, idx = 0;
		for (int j = 0; j < 4; j++)
		{
			if (maxi < cnt[j][i])
			{
				maxi = cnt[j][i];
				idx = j;
			}
		}
		ans += n - maxi;
		cout << save[idx];
	}
	cout << '\n' << ans;
	return 0;
}