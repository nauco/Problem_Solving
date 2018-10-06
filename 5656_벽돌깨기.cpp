#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T, N, W, H;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<int> q;

vector< vector<int> > arr;
int result, maxbrokenblock;

void screen(vector< vector<int> > &v)
{
	system("cls");
	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < W; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int breaking(int x, int y, vector< vector<int> > &v)
{
	int c = 0;

	int blocknum = v[x][y];
	v[x][y] = 0;
	//��������
	if (blocknum == 1)
	{
		return 1;
	}
	for (size_t i = 1; i < blocknum; i++)
	{
		//4����
		for (size_t k = 0; k < 4; k++)
		{
			int nx = x + i*dx[k];
			int ny = y + i*dy[k];

			if (nx >= H || ny >= W || nx < 0 || ny < 0)
				continue;

			if (v[nx][ny] == 0)
				continue;

			if (v[nx][ny] == 1)
			{
				c++;
				v[nx][ny] = 0;
			}
			else
			{
				c += breaking(nx, ny, v);
			}
		}
	}
	return c;
}

int drop(int _y, vector< vector<int> > &v)
{
	int x = 0;
	int y = _y;

	while (v[x][y] == 0)
	{
		x++;
		if (x == H)
		{
			return 0;
		}
	}
	return breaking(x, y, v);
}


void func(int n, vector< vector<int> > v)
{

	if (n == N)
	{
		int c = 0;
		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				if (v[i][j] != 0)
				{
					c++;
				}
			}
		}
		maxbrokenblock = min(maxbrokenblock, c);

		return;
	}
	//����ĭ���� ����
	for (size_t i = 0; i < W; i++)
	{
		//i�࿡ ���� ����߸���

		vector< vector<int> > tmp = v;
		drop(i, v);

		//screen(v);

		//�μ��� �� �߷�����
		for (int j = 0; j < W; j++)
		{
			for (int k = H - 1; k >= 0; k--)
			{
				if (v[k][j] != 0)
				{
					q.push(v[k][j]);
					v[k][j] = 0;
				}
			}

			int k = H - 1;
			while (!q.empty())
			{
				v[k][j] = q.front();
				q.pop();
				k--;
			}
		}
		//screen(v);

		//������ ��������
		func(n + 1, v);

		//recovery
		v = tmp;
	}
}

//W ����  H ����
int main()
{
	cin >> T;
	for (size_t tc = 0; tc < T; tc++)
	{
		cin >> N >> W >> H;
		arr.assign(H, vector<int>(W));

		result = 0;
		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] != 0)
				{
					result++;
				}
			}
		}
		maxbrokenblock = 99999;
		func(0, arr);
		cout << "#" << tc + 1 << " " << maxbrokenblock << endl;

	}
	return 0;
}