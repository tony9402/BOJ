#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arr[26], arr2[26];
string input;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;
	for (auto i : input)
	{
		arr[i - 'a']++;
	}

	cin >> input;
	for (auto i : input)
	{
		arr2[i - 'a']++;
	}
	
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		ans += abs(arr[i] - arr2[i]);
	}

	cout << ans;

	return 0;
}