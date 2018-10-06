#include <iostream>
#include <algorithm>
using namespace std;

int N, result = 99999;
int arr[20][20];
int tmp[20][20];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


void click(int x, int y)
{
	arr[x][y] = (arr[x][y]) ? 0 : 1;

	for (size_t i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		arr[nx][ny] = (arr[nx][ny]) ? 0 : 1;
	}
}

void clickt(int x, int y)
{
	tmp[x][y] = (tmp[x][y]) ? 0 : 1;

	for (size_t i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;

		tmp[nx][ny] = (tmp[nx][ny]) ? 0 : 1;
	}
}
bool check()//모두 꺼져있으면 true
{

	for (size_t i = 0; i < N; i++)
	{
		if (arr[N - 1][i] == 1)

			return false;
	}
	return true;
}

void solve(int n, int c)
{
	int cc = c;
	//n번째 줄을 끈다
	if (n == N)
	{
		if (check())//모두 꺼진경우
			result = min(result, c);
	}
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			if (arr[n - 1][i] == 1)//내 윗칸이 켜져있으면
			{
				click(n, i);
				cc++;
			}
		}
		solve(n + 1, cc);
	}


}

void simulation(int n, int c)
{
	if (n == N)
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				arr[i][j] = tmp[i][j];
			}
		}

		solve(1, c);
	}
	else
	{
		//클릭하지않는다
		simulation(n + 1, c);

		clickt(0, n);
		//클릭한다
		simulation(n + 1, c + 1);

		clickt(0, n);
	}
}


//0 OFF   1 ON
int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> tmp[i][j];
		}
	}

	simulation(0, 0);


	if (result == 99999)
	{
		result = -1;
	}
	cout << result << endl;


	return 0;
}