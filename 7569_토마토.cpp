#include <iostream>
#include <queue>
using namespace std;

int M, N, H, result;
int arr[102][102][102];	//1익은 0익지않은 -1없는

int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };


class node
{
public:
	int x;
	int y;
	int z;
	int day;
	node(int x, int y, int z, int d) :x(x), y(y), z(z), day(d) {};
};
queue<node> q;

int main()
{
	cin >> M >> N >> H;

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			for (size_t k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
				{
					q.push(node(i, j, k, 0));
				}
			}
		}
	}

	result = -1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int d = q.front().day;
		result = d;
		q.pop();

		for (size_t i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= H || ny >= N || nz >= M)
				continue;

			if (arr[nx][ny][nz] == 0)//익지않은 토마토가 있으면
			{
				q.push(node(nx, ny, nz, d + 1));
				arr[nx][ny][nz] = 1;
			}

		}
	}


	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			for (size_t k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0)
				{
					result = -1;
				}
			}
		}
	}

	cout << result << endl;



	return 0;
}