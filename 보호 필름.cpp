//�ð��ʰ�
//�࿭ �ٲٱ� or ��Ʈ�Ҷ����� �ٹٲٱ� ���� �ٲﵥ��

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
			//���� K�� �������� 0 or K
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
		//j�� ���
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


	//���α�
	simulation(x + 1, num);
	//1�� �ٲٱ�
	for (size_t i = 0; i < W; i++)
	{
		arr[x][i] = 1;
	}
	simulation(x + 1, num + 1);
	//0���� �ٲٱ�
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
		//�ܸ��� ��� ���ι��⿡ ���ؼ� ������ Ư���� ������
		//K�� �̻� ���������� �ִ� ��쿡�� ���ɰ˻縦 ����ϰ� �ȴ�.

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