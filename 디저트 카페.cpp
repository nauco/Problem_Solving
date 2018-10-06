#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, res;
int arr[21][21];
int dx[4] = { 1, 1, -1, -1 };
int dy[4] = { 1, -1, -1, 1 };
int func(int i, int j, int x, int y)
{
	vector<int> dst(101, 0);
	//dst[arr[i][j]] = 1;
	int nx = i, ny = j;
	for (size_t i = 0; i < x; i++)
	{
		nx = nx + dx[0];
		ny = ny + dy[0];
		if (dst[arr[nx][ny]] == 1)//중복
			return -2;
		dst[arr[nx][ny]] = 1;
	}
	for (size_t i = 0; i < y; i++)
	{
		nx = nx + dx[1];
		ny = ny + dy[1];
		if (dst[arr[nx][ny]] == 1)//중복
			return -2;
		dst[arr[nx][ny]] = 1;
	}
	for (size_t i = 0; i < x; i++)
	{
		nx = nx + dx[2];
		ny = ny + dy[2];
		if (dst[arr[nx][ny]] == 1)//중복
			return -2;
		dst[arr[nx][ny]] = 1;
	}
	for (size_t i = 0; i < y; i++)
	{
		nx = nx + dx[3];
		ny = ny + dy[3];
		if (dst[arr[nx][ny]] == 1)//중복
			return -2;
		dst[arr[nx][ny]] = 1;
	}
	return 2 * (x + y);
}
int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> N;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}
		res = -1;
		int m = N - 1;
		for (int x = m - 1; x > 0; x--)// 5 4 3 2 1
		{
			for (int y = m - x; y > 0; y--)
			{
				for (int i = 0; i < N; i++)//행
				{
					for (int j = 0; j < N; j++)//열
					{
						if (j - y < 0 || j + x >= N)
							continue;
						if (i + x + y >= N)
							continue;
						if (2*(x + y) < res)
							continue;
						res = max(res, func(i, j, x, y));
					}
				}
			}
		}

		cout << "#" << tc << " " << res << endl;
	}

	return 0;
}