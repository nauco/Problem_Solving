#include <iostream>
#include <string.h>
using namespace std;
//´ÙÀ½Ä­È®ÀÎÇØ¼­ Çª´Â°É·Î

char arr[22][22];
int visit[22][22][4][16];

int R, C;
//0»ó 1ÇÏ 2ÁÂ 3¿ì
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int go(int _x, int _y, int _d, int _m)
{
	int x = _x;
	int y = _y;
	int d = _d;
	int m = _m;

	if (x == R)
	{
		x = 0;
	}
	else if (x == -1)
	{
		x = R - 1;
	}
	if (y == C)
	{
		y = 0;
	}
	else if (y == -1)
	{
		y = C - 1;
	}

	while (visit[x][y][d][m] == 0)
	{


		visit[x][y][d][m] = 1;

		if (arr[x][y] == '<')
		{
			d = 2;
		}
		else if (arr[x][y] == '>')
		{
			d = 3;
		}
		else if (arr[x][y] == '^')
		{
			d = 0;
		}
		else if (arr[x][y] == 'v')
		{
			d = 1;
		}
		else if (arr[x][y] == '_')
		{
			if (m == 0)
			{
				d = 3;
			}
			else
			{
				d = 2;
			}
		}
		else if (arr[x][y] == '|')
		{
			if (m == 0)
			{
				d = 1;
			}
			else
			{
				d = 0;
			}
		}
		else if (arr[x][y] == '?')
		{
			arr[x][y] = '^';
			if (go(x+dx[0], y, 0, m) == 1)
			{
				return 1;
			}

			return go();
			arr[x][y] = 'v';
			if (go(x+dx[1], y, 1, m) == 1)
			{
				return 1;
			}
			arr[x][y] = '<';
			if (go(x, y+dy[2], 2, m) == 1)
			{
				return 1;
			}
			arr[x][y] = '>';
			if (go(x, y+dy[3], 3, m) == 1)
			{
				return 1;
			}
			return 0;
		}
		else if (arr[x][y] == '.')
		{
		}
		else if (arr[x][y] == '@')
		{
			return 1;
		}
		else if (arr[x][y] == '-')
		{
			if (m==0)
			{
				m = 15;
			}
			else
			{
				m--;
			}
		}
		else if (arr[x][y] == '+')
		{
			if (m==15)
			{
				m = 0;
			}
			else
			{
				m++;
			}
		}
		else if (arr[x][y] >= '0' && arr[x][y] <='9')
		{
			m = arr[x][y] - '0';
		}
		else
		{
			cout << "cannot here" << endl;
		}


		x = x + dx[d];
		y = y + dy[d];

		if (x == R)
		{
			x = 0;
		}
		else if (x == -1)
		{
			x = R-1;
		}

		if (y == C)
		{
			y = 0;
		}
		else if (y == -1)
		{
			y = C-1;
		}
	}
	return 0;
}


int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> R >> C;
		for (size_t i = 0; i < R; i++)
		{
			for (size_t j = 0; j < C; j++)
			{
				cin >> arr[i][j];
			}
		}
		memset(visit, 0, sizeof(visit));


		if (go(0, 0, 3, 0) == 1)
		{
			cout << "#" << tc << " YES\n";
		}
		else
		{
			cout << "#" << tc << " NO\n";
		}
	}
}