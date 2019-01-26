#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

stack<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		st.push(input);
	}

	int ans = 0;
	while (k)
	{
		int top = st.top();
		st.pop();
		if (top > k)continue;
		int cnt = k / top;
		ans += cnt;
		k = k - cnt * top;
	}
	cout << ans;
	return 0;
}