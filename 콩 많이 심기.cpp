#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1002][1002];
int dp[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int func(int n, int m)
{
	if (n == N && m == M)
	{
		return 0;
	}

	int& ret = dp[n][m];

	if (ret != -1)
	{
		return ret;
	}


	ret = -9999999;//ÃÖ´ë

	if (n==N)
	{
		func(1, m + 1);
	}



	return ret;
}

int main()
{
	int tc;
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		cin >> N >> M;

		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		cout << "#" << i + 1 << " " << func(0, 1) << endl;
	}
	return 0;
}