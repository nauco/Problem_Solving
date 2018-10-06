//������ ����, ������ �� �������� ��� �Ǵ��ϼ̽���
//1 �ϴ� ���������� ��� ����
//2 ����üũ
//3 ?����
// .....���ִ°�
// ������ ������
// 13, 15
//@�� �����ؼ� ©�� �������
#include <iostream>
#include <string.h>
using namespace std;

int R, C, N;
char arr[21][21];
int visit[21][21][4][16];
int dx[4] = { -1 ,1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


int move(int m, char c)
{
	if (c == '<')
	{
		return 2;
	}
	else if (c == '>')
	{
		return 3;
	}
	else if (c == '^')
	{
		return 0;
	}
	else if (c == 'v')
	{
		return 1;
	}
	else if (c == '_')
	{
		if (m == 0)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
	else if (c == '|')
	{
		if (m == 0)
		{
			return 1;
		}
		else
		{
			return  0;
		}
	}
	else
	{
		cout << "here" << endl;
	}
}

int go(int a, int b, int m, int d)
{
	int x = a;
	int y = b;
	int memory = m;
	int dir = d;

	while (true)
	{
		if (arr[x][y] >= '0' && arr[x][y] <= '9')
		{
			memory = arr[x][y] - '0';
		}
		else if (arr[x][y] == '@')
		{
			return 1;
		}
		else if (arr[x][y] == '.')
		{
			if (visit[x][y][dir][memory]==0)
			{
				visit[x][y][dir][memory] = 1;
			}
			else//�ߺ���
			{
				return 0;
			}
		}
		else if (arr[x][y] == '+')
		{
			memory = (memory == 15) ? 0 : memory + 1;
		}
		else if (arr[x][y] == '-')
		{
			memory = (memory == 0) ? 15 : memory - 1;
		}
		else if (arr[x][y] == '?')
		{
			arr[x][y] = '^';
			
			if (go(x, y, memory, 0) == 1)
				return 1;

			arr[x][y] = '>';
			if (go(x, y, memory, 3) == 1)
				return 1;

			arr[x][y] = '<';
			if (go(x, y, memory, 2) == 1)
				return 1;

			arr[x][y] = 'v';
			return go(x, y, memory, 1);

		}
		else
		{
			if (visit[x][y][dir][memory] == 0)
			{
				visit[x][y][dir][memory] = 1;
				dir = move(memory, arr[x][y]);
			}
			else//�ߺ���
			{
				return 0;
			}
		}
		x = x + dx[dir];
		y = y + dy[dir];

		if (x == -1)
		{
			x = R-1;
		}
		else if (x == R)
		{
			x = 0;
		}
		if (y == -1)
		{
			y = C - 1;
		}
		else if (y == C)
		{
			y = 0;
		}
	}
}
int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> R >> C;
		int at = 0;
		for (size_t i = 0; i < R; i++)
		{
			for (size_t j = 0; j < C; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					at++;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		int canStop = 0;
		if (at == 0)
		{
			//���� �� ����
		}
		else
		{
			canStop = go(0, 0, 0, 3);
		}

		if (canStop == 1)
		{
			cout << "#" << tc << " YES\n";
		}
		else
		{
			cout << "#" << tc << " NO\n";
		}
	}

	return 0;
}