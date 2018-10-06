#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
class node
{
public:
	int x;
	int y;
	char c;
	node(int x, int y, int c) : x(x), y(y), c(c) {}
};

vector<node> v;
queue<node> q;
queue<char> qq;
char arr[12][6];
char visit[12][6];
//R G B P Y

bool scan()
{
	memset(visit, 0, sizeof(visit));
	char color;
	int size;
	for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			if (arr[i][j] != '.' && visit[i][j] == 0)
			{
				color = arr[i][j];
				size = 0;
				q.push(node(i, j, color));
				while (!q.empty())
				{
					int x = q.front().x;
					int y = q.front().y;
					int c = q.front().c;
					q.pop();
					visit[x][y] = 1;
					size++;
					for (size_t k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
					
						if (nx<0 || ny<0 || nx >= 12 || ny >= 6)
							continue;

						if (visit[nx][ny] == 1)
							continue;

						if (arr[nx][ny] == c)
						{
							visit[nx][ny] = 1;
							q.push(node(nx, ny, c));
 						}
					}
				}
				//cout << "size"<<size << endl;
				if (size>=4)
				{
					v.push_back(node(i, j, color));
				}
			}
		}
	}

	if (v.size()>=1)
		return true;
	return false;

}

void pop()
{
	//터트리고
	while (!v.empty())
	{
		q.push(v.back());

		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int c = q.front().c;
			q.pop();
			if (arr[x][y] == '.')
			{
				continue;
			}
			arr[x][y] = '.';

			for (size_t k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx<0 || ny<0 || nx >= 12 || ny >= 6)
					continue;

				if (arr[nx][ny] == c)
				{
					q.push(node(nx, ny, c));
				}
			}
		}
		v.pop_back();
	}

	//down
	for (int i = 0; i < 6; i++)
	{
		for (int j = 11; j >= 0; j--)
		{
			if (arr[j][i] != '.')
			{
				qq.push(arr[j][i]);
			}
		}

		while (qq.size() != 12)
		{
			qq.push('.');
		}

		for (int j = 11; j >= 0; j--)
		{
			arr[j][i] = qq.front();
			qq.pop();
		}

	}
}


int howmanychain()
{
	int num = 0;
	//scan 4이상 있으면 true
	while (scan())
	{
		pop();
		num++;
	}
	return num;
}


int main()
{
	for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << howmanychain() << endl;





	return 0;
}