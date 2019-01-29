#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

queue<int> q;
bool visit[100001];
int ans;

int main()
{
	int n, k;
	cin >> n >> k;
	q.push(n);

	while (!q.empty())
	{
		int t = q.size();
		++ans;
		while (t--)
		{
			int now = q.front(); q.pop();
			if (now == k)return cout << ans - 1, 0;
			if (now>0&&!visit[now - 1])
			{
				visit[now - 1] = true;
				q.push(now - 1);
			}
			if (now < 100000 && !visit[now + 1])
			{
				visit[now + 1] = true;
				q.push(now + 1);
			}
			if (now < 50001 && !visit[2 * now])
			{
				visit[2 * now] = true;
				q.push(now * 2);
			}
		}
	}

	return 0;
}