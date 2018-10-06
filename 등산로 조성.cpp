#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
int res, sol;
int arr[9][9];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void func(int x, int y, int d)
{
	if (d > sol)
	{
		sol = d;
	}
	for (size_t i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || ny < 1 || nx >N || ny >N)
			continue;

		if (arr[x][y] > arr[nx][ny])
			func(nx, ny, d+1);
	}
}

int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> N >> K;
		res = 0;
		for (size_t i = 1; i <= N; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{
				cin >> arr[i][j];
				res = max(res, arr[i][j]);
			}
		}
		sol = 1;
		for (size_t i = 1; i <= N; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{
				if (arr[i][j] == res)
				{
					for (size_t x = 1; x <= N; x++)
					{
						for (size_t y = 1; y <= N; y++)
						{
							if (i == x && j == y)
								continue;

							for (size_t k = 1; k <= K; k++)
							{
								arr[x][y] -= k;
								func(i, j, 1);
								arr[x][y] += k;
							}
						}
					}
				}
			}
		}
		cout << "#" << tc << " " << sol << endl;
	}
	return 0;
}