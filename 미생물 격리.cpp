//물어볼거 어떤식으로 진행하려고 생각했나
//벡터에 노드 넣어서
//배열을 만들어서
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, res;
//상1 하2 좌3 우4
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
class node
{
public:
	int x;
	int y;
	int num;
	int dir;
	int t;
	node(int x, int y, int num, int dir, int t) :x(x), y(y), num(num), dir(dir), t(t) {};
	void update(int nx, int ny)
	{
		x = nx;
		y = ny;
		t++;
		if (x == 0 || y == 0 || x == N-1 || y == N-1)
		{
			dir = dir - dx[dir] - dy[dir];
		}
	}
};
vector<node> v;
vector<node> table[100][100];
int t[100][100];

bool cmp(const node &a, const node &b) {
	return a.num > b.num;
}
int main()
{
	int tc;
	cin >> tc;
	for (size_t testcase = 0; testcase < tc; testcase++)
	{
		cin >> N >> M >> K;
		for (size_t i = 0; i < K; i++)
		{
			int x, y, n, d;
			cin >> x >> y >> n >> d;
			table[x][y].push_back(node(x, y, n, d, 0));
		}
		for (size_t t = 0; t < M; t++)
		{
			//돌면서 다음 위치로 이동
			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					int s = table[i][j].size();
					if (s == 0)
						continue;
					for (size_t k = 0; k < s; k++)
					{
						int x = table[i][j][0].x;
						int y = table[i][j][0].y;
						int dir = table[i][j][0].dir;
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						int tt = table[i][j][0].t;
						if (tt == t)
						{
							table[nx][ny].push_back(table[i][j][0]);
							table[nx][ny].back().update(nx, ny);
							table[i][j].erase(table[i][j].begin());
						}

					}
				}
			}

			//미생물 합쳐질 때
			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					int s = table[i][j].size();
					if (s > 1)
					{
						sort(table[i][j].begin(), table[i][j].end(), cmp);

						for (int k = s-1; k >= 1; k--)
						{
							table[i][j][0].num += table[i][j][k].num;
							table[i][j].erase(table[i][j].end()-1);
						}
					}
					if (s != 0)
					{
						if (i == 0 || j == 0 || i == N-1 || j == N-1)
						{
							table[i][j][0].num /= 2;
						}
					}
				}
			}
		}

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (table[i][j].size() != 0)
				{
					res += table[i][j][0].num;
					table[i][j].clear();
				}
			}
		}
	

		cout << "#" << testcase+1 << " " << res << endl;
		v.clear();
		res = 0;
	}
	return 0;
}