#include<iostream>

using namespace std;

bool visit[101];

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (visit[input])++ans;
		visit[input] = true;
	}
	cout << ans;
	return 0;
}