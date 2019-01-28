#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;

bool check(int now, int cnt)
{
	int sum = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > now)return false;
		sum += list[i];
		if (now < sum)
		{
			if (cnt == 1)return false;
			cnt--;
			sum = list[i];
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		sum += input;
		list.push_back(input);
	}

	int left = 0, right = sum;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if (check(mid, k))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << right + 1;
	return 0;
}