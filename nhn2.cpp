#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int W;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
//0 오른쪽   x증가
//1 아래		y증가
//2 왼쪽		x감소
//3 위		y감소

vector< vector<string> > v;
vector< vector<string> > result;
vector<string> tmp;
int modular(int k, int n)//한줄에 몇개
{
	int f = n*n - (n - 2)*(n - 2);//주기
	int w = W;
	while (w > f)
	{
		w -= f;
	}

	while (w<0)
	{
		w += f;
	}
	W *= -1;
	return w;
}

void curl(int k, int n)
{
	int move = modular(k, n);

	int x, y, d;
	x = k;
	y = k;
	d = 0;

	//0 오른쪽   x증가
	//1 아래		y증가
	//2 왼쪽		x감소
	//3 위		y감소
	for (int i = 0; i < n*n - (n-2)*(n-2); i++)
	{
		tmp.push_back(v[x][y]);

		if (x+dx[d] == k+n || y+dy[d] == k+n || x+dx[d] == k-1)
		{
			d++;
		}
		else if(y+dy[d] == k-1)
		{
			d = 0;
		}

		x = x + dx[d];
		y = y + dy[d];
	}

	rotate(tmp.begin(), tmp.begin() + move, tmp.end());


	x = k;
	y = k;
	d = 0;

	for (int i = 0; i < n*n - (n - 2)*(n - 2); i++)
	{
		result[x][y] = tmp[i];

		if (x + dx[d] == k+n || y + dy[d] == k+n || x + dx[d] == k-1)
		{
			d++;
		}
		else if (y + dy[d] == k-1)
		{
			d = 0;
		}

		x = x + dx[d];
		y = y + dy[d];
	}
	tmp.clear();

}

void func(int k, int n)
{
	if (n == 1 || n == 0)
	{
		if (n == 1)
		{
			result[k][k] = v[k][k];
		}
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
			
	}
	else
	{
		curl(k, n);

		func(k + 1, n - 2);
	}
}

int main()
{
	cin >> N >> W;

	v.assign(N, vector<string>(N));
	result.assign(N, vector<string>(N));
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> v[i][j];
		}
	}
	func(0, N);

	return 0;
}