#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, K;

int arr[102][102];	//1이면 막혀있음
int visit[102][102];//1이면 방문했음

vector<int> result;
typedef pair<int, int> pp;
queue<pp> q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	cin >> M >> N >> K;
	for (size_t i = 0; i < K; i++)
	{
		int	x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (size_t j = x1; j < x2; j++)
		{
			for (size_t k = y1; k < y2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}


	int cnt = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			//아직 방문하지않았고 갈수있다면
			if (visit[i][j] == 0 && arr[i][j] == 0)
			{
				visit[i][j] = 1;
				result.push_back(1);
				q.push(pp(i, j));
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (size_t k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							continue;
						if (arr[nx][ny] == 1)
							continue;
						if (visit[nx][ny] == 0)
						{
							visit[nx][ny] = 1;
							q.push(pp(nx, ny));

							result[cnt]++;
						}
					}
				}
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	sort(result.begin(), result.end());
	for (auto& i : result)
		cout << i << " ";
	return 0;
}