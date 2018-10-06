#include <iostream>
using namespace std;

int N, M, H;
//N개의 세로선, H 가로선 놓을수 있는 수
//N최대 10 , H 최대 30 
int result;


int arr[31][12]; //HN

bool go()
{
	for (int i = 1; i <= N; i++)
	{
		int n = i;
		int h = 1;
		while (h != H + 1)
		{
			if (arr[h][n] == 1)
			{
				h++;
				n++;
			}
			else if (arr[h][n-1] == 1)
			{
				h++;
				n--;
			}
			else
			{
				h++;
			}
		}

		if (i != n)
		{
			return false;
		}
	}
	return true;
}


bool check()
{
	for (int i = 1; i <= N; i++) /* i번째 세로선 */
	{
		int current = i; /* current : 현재 위치(세로선) */
		for (int j = 1; j <= H; j++) /* j번째 행 */
		{
			if (arr[j][current] == 1)
				current += 1;
			else if (current - 1 > 0 && arr[j][current - 1] == 1)
				current -= 1;
		}

		if (i == current)
			continue;
		else
			return false;
	}

	return true;
}

void func(int h, int depth, int goal)
{
	if (result != 0)
	{
		return;
	}
	if (depth == goal)
	{
		if (check())
		{
			result = depth;
		}	
		return;
	}
	for (int i = h; i <= H; i++)
	{
		for (int j = 1; j<N; j++)
		{
			if (arr[i][j] == 0)
			{
				if (arr[i][j - 1] == 0 && arr[i][j + 1] == 0) 
				{

					arr[i][j] = 1;

					func(i, depth + 1, goal);

					arr[i][j] = 1;
				}
			}
		}
	}
}


int main()
{
	cin >> N >> M >> H;
	for (size_t i = 0; i < M; i++)
	{
		int		a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	if (check())
	{
		cout << 0 << endl;
		return 0;
	}
	result = 0;

	for (int i = 1; i < 4; i++)
	{
		func(1, 0, i);
		if (result != 0)
		{
			break;
		}
	}
	if (result == 0)
	{
		result = -1;
	}
	cout << result << endl;
	return 0;
}