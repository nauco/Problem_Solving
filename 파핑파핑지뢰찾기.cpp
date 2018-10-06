#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int tc, res, N;
int arr[302][302];
int chk[302][302];
int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
queue<int> q;

int main()
{
	cin >> tc;
	for (int m = 1; m <= tc; m++)
	{
		char z;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> z;
				if (z=='*')
				{
					arr[i][j] = -1;
					chk[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == -1)
				{
					for (int k = 0; k < 8; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[nx][ny] == -1)
							continue;
						arr[nx][ny]++;
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 0 && chk[i][j] == 0)
				{
					q.push(i);
					q.push(j);
					chk[i][j] = 1;
					while (!q.empty())
					{
						int x = q.front(); q.pop();
						int y = q.front(); q.pop();

						for (int k = 0; k < 8; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || ny < 0 || nx >= N || ny >= N || chk[nx][ny] == 1)
								continue;
							if (arr[nx][ny] == 0)
							{
								q.push(nx);
								q.push(ny);
							}
							chk[nx][ny] = 1;	//이부분 중요 때문에 시간 줄어듬
						}
					}
					res++;
				}
			}
		}

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (chk[i][j] == 0)
				{
					res++;
				}
			}
		}
		cout << "#" << m << " " << res  << endl;
		res = 0;
		memset(chk, 0, sizeof(chk));
	}
	return 0;
}