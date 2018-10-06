//shoot 어떻게 구현했는지 보여줘요오오오오오
#include <iostream>
#include <string>
using namespace std;

int H, W, N, dir, x, y;
char arr[21][21];
int dx[4] = { -1 ,1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void shoot()
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (nx >= 0 && ny >= 0 && nx < H && ny < W)
	{
		if (arr[nx][ny] == '*')
		{
			arr[nx][ny] = '.';
			break;
		}
		else if (arr[nx][ny] == '#')
		{
			break;
		}
		nx += dx[dir];
		ny += dy[dir];
	}
}
void turn(char c)
{
	if (c == 'U')
	{
		dir = 0;
	}
	else if (c == 'D')
	{
		dir = 1;
	}
	else if (c == 'L')
	{
		dir = 2;
	}
	else if (c == 'R')
	{
		dir = 3;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx >= 0 && ny >= 0 && nx < H && ny < W && arr[nx][ny] == '.')
	{
		//갈 수 있으면
		x = nx;
		y = ny;
	}

}
int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> H >> W;
		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '^')
				{
					dir = 0;
					x = i;
					y = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == 'v')
				{
					dir = 1;
					x = i;
					y = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == '<')
				{
					dir = 2;
					x = i;
					y = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == '>')
				{
					dir = 3;
					x = i;
					y = j;
					arr[i][j] = '.';
				}
			}
		}
		cin >> N;
		string str;
		cin >> str;

		for (size_t in = 0; in < N-1; in++)
		{
			if (str[in] == 'S')
			{
				shoot();
			}
			else
			{
				turn(str[in]);
			}
		}

		switch (dir)
		{
		case 0:
			arr[x][y] = '^';
			break;
		case 1:
			arr[x][y] = 'v';
			break;
		case 2:
			arr[x][y] = '<';
			break;
		case 3:
			arr[x][y] = '>';
			break;
		default:
			break;
		}

		//정답출력
		cout << "#" << tc << " ";
		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}