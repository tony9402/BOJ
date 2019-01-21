#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

vector<int> vc;
queue<int> q;
stack<int> st;

int main()
{
	int T, Max, Min;
	int n, cm, input;
	cin >> T;
	for (; T--;)
	{
		priority_queue<int> mq;
		priority_queue<int> nq;
		cin >> cm >> n;
		vc.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			vc.push_back(input);
		}

		sort(vc.begin(), vc.end());

		for (int i = 0; i < vc.size(); i++)
		{
			Max = max(cm - vc[i], vc[i]);
			Min = min(cm - vc[i], vc[i]);
			mq.push(Max);
			nq.push(Min);
		}

		printf("%d %d\n", nq.top(), mq.top());
	}


	return 0;
}