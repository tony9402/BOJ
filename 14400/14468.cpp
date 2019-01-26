#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool visit[26];
int ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string input;
	cin >> input;
	for (int i=0;i<input.size();i++)
	{
		int idx = input[i] - 'A';
		if (!visit[idx])visit[idx] = true;
		else
		{
			visit[idx] = false;
			int j = i;
			while (--j >= 0)
			{
				if (input[i] == input[j])break;
				if (visit[input[j] - 'A'])++ans;
			}
		}
	}
	cout << ans;
	return 0;
}