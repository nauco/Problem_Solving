#include <iostream>
using namespace std;

int N, M, H, T, result;
int arr[32][12];

bool go()
{
	for (int i = 1; i <= N; i++)
	{
		int x = i;
		int y = 1;
		while (y!=H+1)
		{
			if (arr[y][x] == 1)
			{
				x++;
				y++;
			}
			else if(arr[y][x-1] == 1)
			{
				x--;
				y++;
			}
			else
			{
				y++;
			}
		}

		if (i != x)
		{
			return false;
		}
	}
	return true;
}


//일단 선 한개만 추가했을 때 확인
void func(int n, int _x, int _y)
{
	if (n==T)
	{
		if (go())
		{
			cout << n << endl;
			exit(0);
		}
		else
		{
			return ;
		}
	}
	for (int x = _x; x <= N; x++)
	{
		for (int y = _y; y <= H; y++)
		{
			if (arr[y][x] == 1)
			{
				continue;
			}

			//가로선 추가
			arr[y][x] = 1;

			if (y == H)
			{
				if (x == N)
				{
					return;
				}
				func(n + 1, x + 1, 1);
			}
			else
			{
				func(n + 1, x, y + 1);
			}

			//백트래킹
			arr[y][x] = 0;
		}
	}	
}


int main()
{
	cin >> N >> M >> H;
	for (size_t i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	result = -2;
	
	for (size_t i = 0; i <= 3; i++)
	{
		T = i;
		func(0, 1, 1);
		if (result == i)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;



	return 0;
}