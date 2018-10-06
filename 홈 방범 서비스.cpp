#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int N, M, res, K;
typedef pair<int, int> pp;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[21][21];
class node
{
public:
	int x;
	int y;
	int d;
	node(int x, int y, int d) :x(x), y(y), d(d) {};
};

void bfs(int i, int j)
{
	vector<vector<int>> visit(N, vector<int>(N, 0));
	queue<node> q;
	q.push(node(i, j, 1));
	int h = 0;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		if (arr[x][y] == 1)
		{
			h++;
		}
		if (d<K)
		{
			q.pop();
			visit[x][y] = 1;
			

			for (size_t i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] == 1)
					continue;

				q.push(node(nx, ny, d + 1));
				visit[nx][ny] = 1;
			}
			if (!q.empty() && d != q.front().d)
			{
				if (h*M >= d*d + (d - 1)*(d - 1))
				{
					res = max(res, h);
				}
			}
		}
		if (h*M >= d*d + (d - 1)*(d - 1))
		{
			res = max(res, h);
		}
		if (d==K)
		{
			return;
		}
	}
}

int main()
{
	int tc;
	cin >> tc;
	for (size_t testcase = 1; testcase <= tc; testcase++)
	{
		cin >> N >> M;
		res = 1;
		int numofhouse = 0;
		
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				numofhouse += arr[i][j];
			}
		}
		K = 1;
		while (K*K + (K - 1)*(K - 1) <= numofhouse * M)
		{
			K++;
		}

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				bfs(i, j);
			}
		}
		cout << "#" << testcase<<" " << res << endl;
	}

	return 0;
}