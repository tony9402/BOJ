#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> DAG;
priority_queue<int, vector<int>, greater<int>> pq;
int indegree[32001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	DAG.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		DAG[a].push_back(b);
		++indegree[b];
	}

	for (int i = 1; i <= n; i++)
		if (!indegree[i])
			pq.push(i);

	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();

		cout << now << ' ';
		for (auto i : DAG[now])
			if (--indegree[i] == 0)
				pq.push(i);
	}
	return 0;
}