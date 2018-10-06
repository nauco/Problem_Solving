#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int r1, c1, r2, c2;
int N;
int arr[1003][1003];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int rx, ry;
int main()
{
	cin >> r1 >> c1 >> r2 >> c2;
	N = max(r1, max(r2, max(c1, c2)));
	N = 2 * N + 1;

	int x = N;
	int y = N;
	int dir = 0;
	//0¿Þ 1À§ 2¿À 3¾Æ
	for (int i = 0; i < N*N; i++)
	{
		arr[x][y] = N*N - i;


		if (x + dx[dir] < 0 || y + dy[dir] < 0 || x + dx[dir] >= N || y + dy[dir] >= N || arr[x + dx[dir]][y + dy[dir]])
			dir = (dir + 1) % 4;

		x += dx[dir];
		y += dy[dir];
	}
	N = (N - 1) / 2;

	for (int i = -r1; i < r2; i++)
	{
		for (int j = -c1; j < c2; j++)
		{
			cout << setw(2) << arr[N - i][N - j] << " ";
		}
		cout << "\n";
	}

	return 0;
}