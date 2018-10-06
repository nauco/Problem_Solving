#include <iostream>
#include <algorithm>
using namespace std;

int arr[22][22];
int N, result = 9999999;
int aa[12], bb[12];

int calc()
{
	int a = 0, b = 0;

	for (size_t i = 0; i < N / 2; i++)
	{
		for (size_t j = 0; j < N / 2; j++)
		{
			a += (arr[aa[i]][aa[j]] + arr[aa[j]][aa[i]]);
			b += (arr[bb[i]][bb[j]] + arr[bb[j]][bb[i]]);
		}
	}
	return abs(a - b);
}

void func(int n, int a, int b)
{
	if (n == N)
	{
		result = min(result, calc());
		return;
	}

	if (a < N / 2)
	{
		aa[a] = n + 1;
		func(n + 1, a + 1, b);
		aa[a] = 0;
	}

	if (b < N / 2)
	{
		bb[b] = n + 1;
		func(n + 1, a, b + 1);
		bb[b] = 0;
	}

	

}

int main()
{

	cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		for (size_t j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(0, 0, 0);

	cout << result/2 << endl;




	return 0;
}