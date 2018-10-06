#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M, R, C, L, res;
int arr[51][51];
int visit[51][51];
int type[8][2] = { {},{},{ 0, 1 },{ 2, 3 },{ 0, 3 },{ 1, 3 },{ 1, 2 },{ 0, 2 } };
//0╩С 1го 2аб 3©Л
//0		1, 2, 4, 7
//1		1, 2, 5, 6
//2		1, 3, 6, 7
//3		1, 3, 4, 5
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
class node
{
public:
	int x;
	int y;
	int l;
	node(int x, int y, int l) :x(x), y(y), l(l) {};
};
queue<node> q;

int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		memset(visit, 0, sizeof(visit));
		cin >> N >> M >> R >> C >> L;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				cin >> arr[i][j];
			}
		}
		res = 0;
		q.push(node(R, C, 1));
		visit[R][C] = 1;
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int l = q.front().l;

			q.pop();
			int t = arr[x][y];
			if (t == 1)
			{
				for (size_t i = 0; i < 4; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					int k = arr[nx][ny];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
						continue;
					if ((i == 0) && !(k == 1 || k == 2 || k == 5 || k == 6))
						continue;
					if ((i == 1) && !(k == 1 || k == 2 || k == 4 || k == 7))
						continue;
					if ((i == 2) && !(k == 1 || k == 3 || k == 4 || k == 5))
						continue;
					if ((i == 3) && !(k == 1 || k == 3 || k == 6 || k == 7))
						continue;
					if (visit[nx][ny] != 0 && visit[nx][ny] <= l)
						continue;
					q.push(node(nx, ny, l + 1));
					visit[nx][ny] = l + 1;
				}
			}
			else
			{
				for (size_t i = 0; i < 2; i++)
				{
					int nx = x + dx[type[t][i]];
					int ny = y + dy[type[t][i]];
					int k = arr[nx][ny];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
						continue;
					if ((type[t][i] == 0) && !(k == 1 || k == 2 || k == 5 || k == 6))
						continue;
					if ((type[t][i] == 1) && !(k == 1 || k == 2 || k == 4 || k == 7))
						continue;
					if ((type[t][i] == 2) && !(k == 1 || k == 3 || k == 4 || k == 5))
						continue;
					if ((type[t][i] == 3) && !(k == 1 || k == 3 || k == 6 || k == 7))
						continue;
					if (visit[nx][ny] != 0 && visit[nx][ny] <= l)
						continue;
					q.push(node(nx, ny, l + 1));
					visit[nx][ny] = l + 1;
				}
			}
		}

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (visit[i][j] != 0  && visit[i][j] <= L)
				{
					res++;
				}
			}
		}
		cout << "#" << tc << " " << res << endl;
	}

	return 0;
}