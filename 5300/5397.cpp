//1. 스택 이용
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

stack<char> First, Second;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string a;
	for (; n--;)
	{
		cin >> a;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '<')
			{
				if (!First.empty())
				{
					Second.push(First.top()); First.pop();
				}
			}
			else if (a[i] == '>')
			{
				if (!Second.empty())
				{
					First.push(Second.top()); Second.pop();
				}
			}
			else if (a[i] == '-')
			{
				if (!First.empty())
				{
					First.pop();
				}
			}
			else
			{
				First.push(a[i]);
			}
		}
		while (!First.empty())
		{
			Second.push(First.top());
			First.pop();
		}
		while (!Second.empty())
		{
			cout << Second.top();
			Second.pop();
		}
		cout << '\n';
	}

	return 0;
}