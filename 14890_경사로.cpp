#include <iostream>
using namespace std;

int N, L;
int arr[101][101];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
int result;


void check(int x, int y, int d, int h)
{
	if (x == N || y == N)
	{
		result++;
		return;
	}
	else if  ((d == 0 && x == N - 1) || (d == 1 && y == N - 1))
	{
		result++;
		return;
	}
	else
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		//����ĭ �� �� ������
		if (h == arr[nx][ny])
		{
			//������ ����
			check(nx, ny, d, h);
		}
		
		//����ĭ���� ��������

		if (!(x+L*dx[d] == N) && !(y+L*dy[d] == N) && (arr[x][y] == h))
		{
			for (int i = 1; i <= L; i++)
			{
				if (arr[x][y] + i/L != arr[x + i*dx[d]][y + i*dy[d]])
				{
					break;
				}
				if (i == L)
				{
					check(x + i*dx[d], y + i*dy[d], d, h+1);
				}
			}
		}

		//����ĭ���� ��������
		if (!(x + L*dx[d] == N) && !(y + L*dy[d] == N))
		{
			for (int i = 1; i <= L; i++)
			{
				if (h-1 != arr[x + i*dx[d]][y + i*dy[d]])
				{
					break;
				}
				if (i == L)
				{
					check(x + (i+1)*dx[d], y + (i+1)*dy[d], d, h-1);
				}
			}
		}
	}
}
int main()
{
	cin >> N >> L;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	int answer = 0;

	for (size_t i = 0; i < N; i++)
	{
		result = 0;
		check(0, i, 0, arr[0][i]);
		if (result != 0)
		{
			answer++;
			cout << "����" << i << "��° ���� ����" << endl;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		result = 0;
		check(i, 0, 1, arr[i][0]);
		if (result != 0)
		{
			answer++;
			cout << "����" << i << "��° ���� ����" << endl;
		}
	}

	cout << answer << endl;

	return 0;
}