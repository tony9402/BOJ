#include<iostream>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

deque<char> dq;

int main()
{
	int n, k;
	cin >> n >> k;
	string input;
	cin >> input;

	for (auto i : input)
	{
		while (k > 0 && dq.size() && dq.back() < i)dq.pop_back(),k--;
		dq.push_back(i);
	}
	for (int i = 0; i < dq.size() - k; i++)cout << ia;
	return 0;
}