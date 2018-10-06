#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int dp[100100][3];
int arr[2][100100];

int func(int c, int status) {
	if (c == N) return 0; // base case

	int& ret = dp[c][status];
	if (ret != -1)
		return ret; // ÀÌ¹Ì °è»êµÊ

	ret = func(c + 1, 0);

	if (status != 1)
		ret = max(ret, func(c + 1, 1) + arr[0][c]);
	if (status != 2)
		ret = max(ret, func(c + 1, 2) + arr[1][c]);
	
	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t<T; t++)
	{
		cin >> N;	
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];
		
		memset(dp, -1, sizeof(dp));
		cout << func(0, 0) << endl;
	}
}