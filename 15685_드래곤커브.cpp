#include <iostream>
#include <vector>
using namespace std;

int N;
int x, y, d, g;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int arr[101][101];

class node
{
public:
	int x;
	int y;
	int d;
	node(int x, int y, int d) :x(x), y(y), d(d) {};
};

vector<node> v;

void nextGeneration(int n)
{
	if (n == g)
	{
		for (auto& i : v)
			arr[i.x][i.y] = 1;

		int x = v.back().x;
		int y = v.back().y;
		int d = v.back().d;
		arr[x + dx[d]][y + dy[d]] = 1;
		
	}
	else
	{
		//마지막 점
		int x = v.back().x;
		int y = v.back().y;
		int d = v.back().d;
		int dd;
		//마지막점 1증가시키고 역순으로

		int size = v.size();

		x = x + dx[d];
		y = y + dy[d];
		d = (d + 1) % 4;
		v.push_back(node(x, y, d));

		for (int i = size-1; i > 0; i--)
		{
			dd = v[i].d - v[i - 1].d;
			x = x + dx[d];
			y = y + dy[d];
			d = (d - dd + 4) % 4;
			v.push_back(node(x, y, d));
		}
		nextGeneration(n + 1);
	}
}

int findsquare()
{
	int answer = 0;
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
			{
				if (arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1)
				{
					answer++;
				}
			}
		}
	}
	return answer;
}

//0x증가-> 1y감소up 2x감소<- 3y증가down
int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{

		cin >> x >> y >> d >> g;

		v.push_back(node(x, y, d));	

		nextGeneration(0);

		v.clear();
	}


	cout << findsquare() << endl;



	return 0;
}