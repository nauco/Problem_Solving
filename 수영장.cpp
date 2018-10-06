//13302 리조트랑 비슷
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int d, m, m3, y;
int res = 987654321;
int arr[13];
int dp[13][2];

int func(int n, int cp)
{
	if (n > 12)
	{
		return 0;
	}
	int& ret = dp[n][2];

	if (ret != -1)
	{
		return ret;
	}
	ret = 987654321;

	//y살때
	ret = min(ret, func(n + 13, 0) + y);
	//m3살때
	ret = min(ret, func(n + 3, 0) + m3);
	//m살때
	//ret = min(ret, func(n + 1, 0) + m);
	//d살때
	ret = min(ret, func(n + 1, 0) + arr[n + 1] * d);


	return ret;
}

int main()
{
	int testcase;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		cin >> d >> m>> m3 >> y;

		for (size_t i = 1; i <= 12; i++)
		{
			cin >> arr[i];
		}
		memset(dp, -1, sizeof(dp));
		cout << "#" << tc << " " << func(0, 0) << endl;
	}
	return 0;
}