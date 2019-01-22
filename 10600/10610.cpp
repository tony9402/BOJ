#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string input;

int main()
{
	cin >> input;
	int sum = 0;
	bool check = false;
	for (int i = 0; i < input.size(); i++)
	{
		sum += input[i] - '0';
		if (!(input[i] - '0'))check = true;
	}
	if (sum % 3 != 0 || !check)
	{
		cout << -1;
		return 0;
	}

	sort(input.begin(), input.end());
	reverse(input.begin(), input.end());
	cout << input;
	return 0;
}