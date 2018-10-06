#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int T;
int N, M, K, result;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

class node
{
public:
	int x;
	int y;
	int life;
	int state;//�������� -1, Ȱ������ 0, ��Ȱ������ 123
	node(int x, int y, int l, int s) :x(x), y(y), life(l), state(s) {}

};	

node* arr[1000][1000];

void tick(int time)
{
	if (time == K)
	{
		for (size_t i = 0; i < 1000; i++)
		{
			for (size_t j = 0; j < 1000; j++)
			{
				if (arr[i][j] != NULL && arr[i][j]->state >= 0)
				{
					result++;
				}
			}
		}
	}
	else
	{
		//state�� 1�� ����
		//state�� 0�� ���� 4���⿡ ���� �� -1��
		vector<node> v;
		for (size_t i = 0; i < 1000; i++)
		{
			for (size_t j = 0; j < 1000; j++)
			{
				if (arr[i][j] == NULL)
					continue;

				int s = arr[i][j]->state;

				if (s>0)
				{
					arr[i][j]->state--;
				}
				else if (s == 0)
				{
					arr[i][j]->state--;
					v.push_back(*arr[i][j]);
				}
			}
		}

		//
		for (auto& i : v)
		{
			int x = i.x;
			int y = i.y;
			int l = i.life;
			for (size_t k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (arr[nx][ny] != NULL)
				{
					//�̹� ����
					//���� Ÿ�ֿ̹� �߰���ٸ�
					//������ 
					if (arr[nx][ny]->life == arr[nx][ny]->state)//���� Ÿ�ֿ̹� �߰��� �������
					{
						if (arr[nx][ny]->life < l)//������� �� ���� ������
						{
							arr[nx][ny]->life = l;
							arr[nx][ny]->state = l;
						}
					}
					else
					{

					}
				}
				else
				{
					arr[nx][ny] = new node(nx, ny, l, l);
				}
			}
		}
		tick(time + 1);
	}
}

int main()
{
	cin >> T;
	int tmp;
	for (size_t tc = 0; tc < T; tc++)
	{
		memset(arr, 0, sizeof(arr));
		cin >> N >> M >> K;
		result = 0;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				cin >> tmp;
				if (tmp != 0)
					arr[i+500][j+500] = new node(i+500, j+500, tmp, tmp);
			}
		}
		tick(0);
		cout << "#" << tc + 1 << " " << result << endl;
	}
	return 0;
}