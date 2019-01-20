#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

vector<vector<int>> Map;
map<int, char> mp;
pair<int, int> head;
queue<pair<int, int>> tail;

bool check(pair<int, int> now, int n)
{
	int y = now.first;
	int x = now.second;
	return (0 <= y && y < n && 0 <= x && x < n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	Map.resize(n);
	head = make_pair(0, 0);
	tail.push(make_pair(0, 0));
	for (int i = 0; i < n; i++)Map[i].resize(n);
	for (; k--;)
	{
		int y, x;
		cin >> x >> y;
		Map[x - 1][y - 1] = 1;
	}

	int input_time;
	char Dir;

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> input_time >> Dir;
		mp[input_time] = Dir;
	}

	int time = 1;
	int dir = 0;
	while (check(head, n))
	{
		int &ny = head.first;
		int &nx = head.second;
		ny += dy[dir];
		nx += dx[dir];
		tail.push(make_pair(ny, nx));
		if (!check(make_pair(ny, nx), n))break;
		if (Map[ny][nx] == 2)
		{
			cout << time;
			return 0;
		}
		else if (Map[ny][nx] != 1)
		{
			int ty = tail.front().first;
			int tx = tail.front().second;
			tail.pop();

			Map[ty][tx] = 0;
		}
		Map[ny][nx] = 2;
		if (mp.find(time) != mp.end())
		{
			if (mp[time] == 'D')
			{
				dir = (dir + 1) % 4;
			}
			else if (mp[time] == 'L')
			{
				dir = (dir + 3) % 4;
			}
		}
		time++;
	}
	cout << time;
	return 0;
}