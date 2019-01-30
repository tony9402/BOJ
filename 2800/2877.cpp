#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

stack<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	n++;
	for (; n;)
	{
		st.push(n % 2);
		n /= 2;
	}
	st.pop();
	while (!st.empty())
	{
		if (st.top() == 0)
		{
			cout << 4;
		}
		else
		{
			cout << 7;
		}
		st.pop();
	}
	return 0;
}