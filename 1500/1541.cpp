#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;
vector<int> list;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string input;
	cin >> input;

	int num = 0;
	bool check = false;
	for (int i = 0; i < input.size(); i++)
	{
		char j = input[i];

		if (48 <= j && j <= 57)
		{
			num = num * 10 + j-48;
		}
		if (j == '-')
		{
			if (check)
			{
				check = false;
				int a = list.back(); list.pop_back();
				list.push_back(a + num);
				num = 0;
			}
			else
			{
				list.push_back(num);
				num = 0;
			}
		}
		if (j == '+')
		{
			if (check)
			{
				int a = list.back(); list.pop_back();
				list.push_back(a + num);
				num = 0;
			}
			else
			{
				list.push_back(num);
				check = true;
				num = 0;
			}
		}
		if (i == input.size() - 1 && !check)list.push_back(num);
	}
	if (check)
	{
		int a = list.back(); list.pop_back();
		list.push_back(a + num);
	}
	int sum = list[0];

	for (int i=1;i<list.size();i++)
	{
		sum -= list[i];
	}
	cout << sum;
	return 0;
}