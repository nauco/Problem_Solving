#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[12][12];
int res, N, maxCore, shortLine;
//상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef pair<int, int> pp;
vector<pp> v;
int connect(int x, int y, int dir)
{
	int nx = x;
	int ny = y;
	while (nx!=0 && ny!=0 && nx!=N-1 && ny!=N-1)
	{
		nx = nx + dx[dir];
		ny = ny + dy[dir];

		if (arr[nx][ny] == 1)//다른 core가 있음
		{
			return 0;//연결 불가
		}
	}
	return 1;
}

int setLine(int x, int y, int dir, int val)
{
	int nx = x;
	int ny = y;
	int l = 0;
	while (nx != 0 && ny != 0 && nx != N - 1 && ny != N - 1)
	{
		nx = nx + dx[dir];
		ny = ny + dy[dir];
		arr[nx][ny] = val;
		l++;
	}
	return l;
}
void func(int idx, int c, int l)
{
	if (c > maxCore)
	{
		shortLine = l;
		maxCore = c;
	}
	else if ( c == maxCore)
	{
		shortLine = min(shortLine, l);
	}

	if (idx == v.size())
	{
		return;
	}

	int x = v[idx].first;
	int y = v[idx].second;

	if (x == 0 || y == 0 || x == N - 1 || y == N - 1)
	{
		func(idx + 1, c + 1, l);//가장자리
	}
	else
	{
		func(idx + 1, c, l);
		for (size_t i = 0; i < 4; i++)
		{
			if (connect(x, y, i) == 1)//연결 가능하면
			{
				int k = setLine(x, y, i, 1);
				func(idx + 1, c + 1, l+k);
				setLine(x, y, i, 0);				
			}
		}
	}
}

int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> N;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
				{
					v.push_back(pp(i, j));
				}
			}
		}

		maxCore = 1;
		shortLine = 9999;

		func(0, 0, 0);

		cout << "#" << tc << " " << shortLine << endl;
		v.clear();
	}

	return 0;
}