#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue<int> pq;
vector<pair<int, int>> vc;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vc.push_back(make_pair(a, b));
	}
	sort(vc.begin(), vc.end());

	for (int i = 0; i < n; i++)
	{
		if (!pq.empty() && -pq.top() <= vc[i].first)pq.pop();
		pq.push(-vc[i].second);
	}

	cout << pq.size();

	return 0;
}