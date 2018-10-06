#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
//위 오 아래 왼
//N E	S	W
//0 1 2 3

int A, B;
int N, M;
int x, y;
char d;

int arr[102][102];

class node
{
public:
	int x;
	int y;
	int d;

	void turnLeft()
	{
		if (d == 0)
		{
			d = 3;
		}
		else
		{
			d--;
		}
	}

	void turnRight()
	{
		if (d == 3)
		{
			d = 0;
		}
		else
		{
			d++;
		}
	}

	node(int x, int y, char _d) :x(x), y(y)
	{
		if (_d == 'N')
		{
			d = 0;
		}
		else if (_d == 'E')
		{
			d = 1;
		}
		else if (_d == 'S')
		{
			d = 2;
		}
		else if (_d == 'W')
		{
			d = 3;
		}
	}
};

vector<node> v;

int func(int robot, char inst)
{
	//robot은 -1해서 사용
	if (inst =='L')
	{
		v[robot - 1].turnLeft();
	}
	else if (inst =='R')
	{
		v[robot - 1].turnRight();
	}
	else if (inst =='F')
	{
		//여기서 충돌 가능
		int x = v[robot - 1].x;
		int y = v[robot - 1].y;
		int d = v[robot - 1].d;

		//벽이면
		if (x+dx[d] == 0 || y+dy[d] == 0 || x+dx[d] == A+1 || y+dy[d] == B+1)
		{
			return -1;
		}

		//로봇이면
		if (arr[x+dx[d]][y+dy[d]] != 0)
		{
			return arr[x + dx[d]][y + dy[d]];
		}
		else
		{
			arr[x][y] = 0;
			v[robot - 1].x = x + dx[d];
			v[robot - 1].y = y + dy[d];
			arr[x + dx[d]][y + dy[d]] = robot;
		}
	}
	return 0;
}
int main()
{
	cin >> A >> B >> N >> M;

	for (size_t i = 1; i <= N; i++)
	{
		cin >> x >> y >> d;
		v.push_back(node(x, y, d));
		arr[x][y] = i;
	}

	for (size_t i = 0; i < M; i++)
	{
		cin >> x >> d >> y;

		//x로봇 d명령어 y번반복
		
		for (size_t j = 0; j < y; j++)
		{
			//0은 잘 통과한거
			int crash = func(x, d);
			if (crash != 0)
			{
				//-1은 벽
				if (crash == -1)
				{
					cout << "Robot " << x << " crashes into the wall" << endl;
				}
				else
				{
					cout << "Robot " << x << " crashes into robot " << crash << endl;
				}
				return 0;
			}
		}
	}
	cout << "OK" << endl;
	return 0;
}