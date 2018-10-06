#include <iostream>
#include <string.h>
using namespace std;

int T, N;
long long dp[66][10];

long long func(int n, int digit)
{
	if (n == 1)
	{
		return 1;
	}

	long long& ret = dp[n][digit];

	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	for (int i = 0; i <= digit; i++)
	{
		ret += func(n - 1, i);
	}

	return ret;
}


int main()
{
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		cin >> N;
		memset(dp, -1, sizeof(dp));
		cout << func(N+1, 9) << endl;
	}
	return 0;
}