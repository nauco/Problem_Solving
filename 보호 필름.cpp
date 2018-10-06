//시간초과
//행열 바꾸기 or 비트할때마다 다바꾸기 말고 바뀐데만

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int D, W, K, res;
int arr[14][21];
int t[14][21];
int check()
{
	for (size_t j = 0; j < W; j++)
	{
		int sum = 0;
		int i;
		for (i = 0; i < K; i++)
		{
			sum += arr[i][j];
			//길이 K의 구간합이 0 or K
		}
		i = 0;
		while (sum != 0 && sum != K)
		{
			if (i + K == D)
			{
				return 0;
			}
			sum -= arr[i][j];
			sum += arr[i + K][j];
			i++;
		}
		//j열 통과
	}
	return 1;
}

void simulation(int x, int num)
{
	if (num >= res)
	{
		return;
	}
	if (check() == 1)
	{
		res = min(res, num);
		return;
	}
	if (x == D)
	{
		return;
	}


	//냅두기
	simulation(x + 1, num);
	//1로 바꾸기
	for (size_t i = 0; i < W; i++)
	{
		arr[x][i] = 1;
	}
	simulation(x + 1, num + 1);
	//0으로 바꾸기
	for (size_t i = 0; i < W; i++)
	{ 
		arr[x][i] = 0;
	}
	simulation(x + 1, num + 1);
	for (size_t i = 0; i < W; i++)
	{
		arr[x][i] = t[x][i];
	}


}

int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> D >> W >> K;
		res = K;
		for (size_t i = 0; i < D; i++)
		{
			for (size_t j = 0; j < W; j++)
			{
				cin >> t[i][j];
			}
		}
		//단면의 모든 세로방향에 대해서 동일한 특성의 셀들이
		//K개 이상 연속적으로 있는 경우에만 성능검사를 통과하게 된다.

		memcpy(arr, t, sizeof(t));

		if (check() == 1)
		{
			res = 0;
		}
		else
		{
			memcpy(arr, t, sizeof(t));
			/*int whereWeGo = (1 << (D * 2));

			while (whereWeGo != 0)
			{
			memcpy(arr, t, sizeof(t));
			whereWeGo--;
			simulation(whereWeGo);
			}*/
			simulation(0, 0);
		}
		cout << "#" << tc << " " << res << endl;
	}

	return 0;
}