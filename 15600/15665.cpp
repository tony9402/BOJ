#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> list;
int output[8];
map<int, bool> visit[10];
bool v[100];
int N, K;

void solve(int m, int n, int k)
{
	if (n == K)
	{
		for (int i = 0; i < n; i++)cout << output[i] << ' ';
		cout << '\n';
		return;
	}
	if (m > N)return;

	for (int i = 0; i < N; i++)
	{
		if (visit[n][list[i]])continue;
		visit[n][list[i]] = true;
		output[n] = list[i];
		solve(m + 1, n + 1, i);
	}
	visit[n].clear();
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		list.push_back(input);
	}
	sort(list.begin(), list.end());
	solve(0, 0, 0);
	return 0;
}