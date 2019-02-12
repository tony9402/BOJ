#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> vc;
int indegree[10001];

int main()
{
	int n, m;
	cin >> n >> m;
	vc.resize(n);
	for (int i = 0; i < m; i++)
	{
		int k, prev;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int in;
			cin >> in;
			--in;
			if (!j)
			{
				prev = in;
				continue;
			}
			indegree[in]++;
			vc[prev].push_back(in);
			prev = in;
		}
	}

	queue<int> q, result;

	for (int i = 0; i < n; i++)
		if (!indegree[i])
			q.push(i);

	for (int i = 0; i < n; i++)
	{
		if (q.empty())
			return cout << 0, 0;
		int now = q.front();
		q.pop();
		result.push(now);
		for (auto j : vc[now])
			if (--indegree[j] == 0)
				q.push(j);
	}

	while (!result.empty())
	{
		cout << 1+result.front() << '\n';
		result.pop();
	}
	return 0;
}