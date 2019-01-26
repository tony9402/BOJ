#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}

	sort(list.begin(), list.end());

	int ans = 0;
	int pointer= 0;
	while (1) {
		++ans;
		pointer = lower_bound(list.begin(), list.end(), list[pointer] + k) - list.begin();
		if (pointer >= n)break;
	}
	cout << ans;
}