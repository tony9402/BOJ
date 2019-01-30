#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> list;
	for (int i = 0; i < 3; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}
	sort(list.begin(), list.end());

	int f = list[2] - list[1];
	int s = list[1] - list[0];

	if (f > s)
	{
		cout << list[1] + s;
	}
	else if (f < s)
	{
		cout << list[1] - f;
	}
	else
	{
		cout << 2 * list[2] - list[1];
	}
	return 0;
}