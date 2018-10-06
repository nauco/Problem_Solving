#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int days;
int price[10001];
int dp[1001][1001];

int func(int n, int coin)
{
	if (n == days)
	{
		return 0;
	}

	int& ret = dp[n][coin];

	if (ret != -1)
	{
		return ret;
	}
	ret = 0;

	//산다
	ret = max(ret, func(n + 1, coin + 1) - price[n]);

	//판다
	ret = max(ret, func(n + 1, 0) + (price[n] * coin) - 1);

	//쉰다
	ret = max(ret, func(n + 1, coin));


	return ret;
}

int main()
{
	cin >> days;
	for (size_t i = 0; i < days; i++)
	{
		cin >> price[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << func(0, 0) << endl;



	return 0;
}