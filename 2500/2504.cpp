#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#define p pair<int, char>
#define mp make_pair

using namespace std;

stack<pair<int, char>> st;
string input;

void cal()
{
	while (1)
	{
		int tc = st.top().second;
		int tn = st.top().first;

		if (tn == -1)break;
		st.pop();

		if (st.empty())
		{
			st.push(mp(tn, tc));
			return;
		}

		int sc = st.top().second;
		int sn = st.top().first;

		st.pop();

		if (sn == -1)
		{
			st.push(mp(sn, sc));
			st.push(mp(tn, tc));
			return;
		}
		else
		{
			st.push(mp(sn + tn, 0));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> input;

	for (auto i : input)
	{
		if (st.empty() || i == '(' || i == '[')
			st.push(mp(-1, i));
		else
		{
			char tc = st.top().second;
			int tn = st.top().first;

			if (tn == -1)
			{
				if (tc == '(' && i == ')')
				{
					st.pop();
					st.push(mp(2, 0));
					cal();
				}
				else if (tc == '[' && i == ']')
				{
					st.pop();
					st.push(mp(3, 0));
					cal();
				}
			}
			else
			{
				st.pop();
				if (st.empty())
					return cout << 0, 0;
				int sc = st.top().second;
				int sn = st.top().first;
				st.pop();
				if (i == ']')
				{
					if (sc != '[')return cout << 0, 0;
					st.push(mp(3 * tn, 0));
				}
				else if (i == ')')
				{
					if (sc != '(')return cout << 0, 0;
					st.push(mp(2 * tn, 0));
				}
				cal();
			}
		}
	}
	cal();
	if (st.size() == 1)
	{
		int ans = st.top().first;
		if (ans == -1)
			return cout << 0, 0;
		else
			cout << ans;
	}
	else
		cout << 0;
	return 0;
}