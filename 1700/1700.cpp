#include<iostream>
#include<vector>

using namespace std;

vector<int> list;
int inq[1000];
int cnt[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int now = -1;
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int input;
		cin >> input;
		cnt[input]++;
		list.push_back(input);
	}

	for (int i = 0; i < k; i++)
	{
		bool check = false;
		for (int j = 0; j < n; j++)
		{
			if (list[i] == inq[j])
			{
				check = true;
				break;
			}
		}

		if (check)continue;

		for (int j = 0; j < n; j++)
		{
			if (!inq[j])
			{
				inq[j] = list[i];
				check = true;
				break;
			}
		}

		if (check)continue;

		int maxi = -1;
		int save;
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			for (int m = i + 1; m < k&&inq[j] != list[m]; m++)++cnt;
			if (maxi < cnt)
			{
				maxi = cnt;
				save = j;
			}
		}
		++ans;
		inq[save] = list[i];
	}

	cout << ans;
	return 0;
}
