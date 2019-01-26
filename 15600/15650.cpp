#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int output[10];
int N, K;

void solve(int n, int k)
{
	if (k == K)
	{
		for (int i = 0; i < K; i++)cout << output[i] << ' ';
		cout << '\n';
		return;
	}
	if (N < n)return;

	for (int i = n + 1; i <= N; i++)
	{
		output[k] = i;
		solve(i, k + 1);
	}
}

int main()
{
	cin >> N >> K;
	solve(0, 0);
	return 0;
}