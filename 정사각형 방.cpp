#include <iostream>
#include <algorithm>
using namespace std;

int N, startroom, howmanyroom;
int arr[1001][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void func(int x, int y, int s, int n)
{
	int now = arr[x][y];
	if (n>howmanyroom)//최대이동
	{
		startroom = s;
		howmanyroom = n;
	}
	else if (n == howmanyroom)
	{
		startroom = min(startroom, s);
	}

	for (size_t i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		if (arr[nx][ny] == now + 1)
		{
			func(nx, ny, s, n+1);
		}
	}
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
		startroom = N*N + 10;
		howmanyroom = 1;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				func(i, j, arr[i][j],  1);
			}
		}



		cout << "#" << tc << " " << startroom << " " << howmanyroom << endl;;
	}
	return 0;
}