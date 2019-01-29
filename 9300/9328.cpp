#include<bits/stdc++.h>

using namespace std;

char input[105][105] = { 0 };
char key_input[27] = { 0 };
int key[27] = { 0 };
bool visit[105][105] = { 0 };
bool used[105][105] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<pair<int, int>> road;
vector<pair<int, int>> vc;

int w, h;

void init()
{
	memset(visit, 0, sizeof(visit));
	road = queue<pair<int, int>>();
	for (int i = 0; i < h; i++) {
		road.push(make_pair(i, -1));
		road.push(make_pair(i, w));
	}
	for (int i = 0; i < w; i++)
	{
		road.push(make_pair(-1, i));
		road.push(make_pair(h, i));
	}
	return;
}

int main()
{
	int ans = 0;
	int TestCase;
	char temp;
	cin >> TestCase;
	for (; TestCase--;)
	{
		ans = 0;
		memset(visit, 0, sizeof(visit));
		memset(used, 0, sizeof(used));
		memset(key, 0, sizeof(key));
		scanf("%d %d", &h, &w);
		for (int i = 0; i < h; i++)scanf("%s", input[i]);
		scanf("%s", key_input);


		for (int i = 0; key_input[i]; i++)
		{
			if (key_input[i] == '0')break;
			key[key_input[i] - 'a']++;
		}

		init();

		int qsize = 0;
		bool reset_check = false;
		while (!road.empty()) {
			while (!road.empty())
			{
				qsize = road.size();
				while (qsize--) {
					pair<int, int> now = road.front();
					road.pop();

					for (int i = 0; i < 4; i++)
					{
						if (now.first + dy[i] < 0 || now.first + dy[i] >= h || now.second + dx[i] < 0 || now.second + dx[i] >= w)continue;
						if (input[now.first + dy[i]][now.second + dx[i]] == '.'	 && visit[now.first + dy[i]][now.second + dx[i]] == 0)
						{
							visit[now.first + dy[i]][now.second + dx[i]] = 1;
							road.push(make_pair(now.first + dy[i], now.second + dx[i]));
						}
						else if (input[now.first + dy[i]][now.second + dx[i]] == '$' && visit[now.first + dy[i]][now.second + dx[i]] == 0)
						{
							input[now.first + dy[i]][now.second + dx[i]] = '.';
							visit[now.first + dy[i]][now.second + dx[i]] = 1;
							ans++;
							road.push(make_pair(now.first + dy[i], now.second + dx[i]));
						}
						else if ('a' <= input[now.first + dy[i]][now.second + dx[i]] && input[now.first + dy[i]][now.second + dx[i]] <= 'z')
						{
							key[input[now.first + dy[i]][now.second + dx[i]] - 'a'] = 1;
							input[now.first + dy[i]][now.second + dx[i]] = '.';

							visit[now.first + dy[i]][now.second + dx[i]] = 1;
							road.push(make_pair(now.first + dy[i], now.second + dx[i]));
							reset_check = true;
						}
						else if ('A' <= input[now.first + dy[i]][now.second + dx[i]] && input[now.first + dy[i]][now.second + dx[i]] <= 'Z' && key[input[now.first + dy[i]][now.second + dx[i]] - 'A'] != 0)
						{
							input[now.first + dy[i]][now.second + dx[i]] = '.';
							visit[now.first + dy[i]][now.second + dx[i]] = 1;
							road.push(make_pair(now.first + dy[i], now.second + dx[i]));
						}
					}
				}
			}
			if (reset_check == true) {
				init();
				reset_check = false;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}