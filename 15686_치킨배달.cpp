#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int N, M;
int arr[51][51];
int visit[14];
int result = 99999;
int chickensize, homesize;
vector<int> chicken;
vector<int> house;



void func(int n, int m)
{
	if (n >= chickensize || m <= M)
	{
		return;
	}


	visit[n] = 1;

	func(n + 1, m + 1);


	int dis = 0;
	for (size_t i = 0; i < homesize; i++)
	{//집
		int tmp = 99999;

		//치킨집과 모든 집간의 거리
		int x = house[2 * i];
		int y = house[2 * i + 1];

		for (size_t j = 0; j < chickensize; j++)
		{//치킨집
			if (visit[j] == 0)
			{
				continue;
			}

			tmp = min(tmp, abs(chicken[2 * j] - x) + abs(chicken[2 * j + 1] - y));
		}
		dis += tmp;
	}

	result = min(result, dis);


	visit[n] = 0;

	func(n + 1, m);

}
int main()
{
	cin >> N >> M;
	for (size_t i = 0; i < N; i++)

	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				house.push_back(i);
				house.push_back(j);
			}
			else if (arr[i][j] == 2)
			{
				chicken.push_back(i);
				chicken.push_back(j);
			}
		}
	}
	chickensize = chicken.size() / 2;
	homesize = house.size() / 2;
	func(0, 0);

	cout << result << endl;
	return 0;
}