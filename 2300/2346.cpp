#include<iostream>
#include<list>

using namespace std;

list<pair<int, int>> lt;
list<pair<int, int>>::iterator it;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		lt.push_back(make_pair(input, i + 1));
	}

	it = lt.begin();

	/*
	양수 3 => n-1만큼

	음수 -1 => n만큼
	*/

	while (1)
	{
		if (lt.empty())break;

		cout << (*it).second << ' ';
		int num = (*it).first;
		it = lt.erase(it);
		if (lt.size() == 1) {
			it = lt.begin();
			cout << (*it).second;
			break;
		}
		if (num > 0)
		{
			for (int i = 0; i < num - 1; i++)
			{
				if (it == lt.end())
				{
					it = lt.begin();
				}
				it++;

			}
			if (it == lt.end())it = lt.begin();
		}
		else
		{
			for (int i = 0; i < abs(num); i++)
			{
				if (it == lt.begin())
				{
					it = lt.end();
					it--;
				}
				else it--;
			}
		}
	}
	return 0;
}