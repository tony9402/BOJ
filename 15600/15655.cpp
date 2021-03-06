#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> list;
int output[10];
bool visit[10000];
int N, K;

void solve(int n, int k)
{
	if (k == K)
	{
		for (int i = 0; i < K; i++)
		{
			cout << output[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (N < n)return;

	for (int i = n + 1; i < N; i++)
	{
		output[k] = list[i];
		solve(i, k + 1);
	}
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
	solve(-1, 0);
	return 0;
}