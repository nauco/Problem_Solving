//substring 없이 파라미터 하나 추가해서

#include <iostream>
#include <set>
#include <string>
using namespace std;

char arr[4][4];
int res;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
set<string> s;
string str;
void func(int x, int y, int n)
{
	if (n == 7)
	{
		s.insert(str);
	}
	else
	{
		for (size_t i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >3 || ny >3)
				continue;
			str += (arr[x][y]);
			func(nx, ny, n + 1);
			str = str.substr(0, str.size() - 1);
		}
	}
}
int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				func(i, j, 0);
			}
		}

		cout << "#" << tc << " " << res << endl;
		s.clear();
	}

	return 0;
}