#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;


int P, T, result=0;

vector<int> PE, TS;

int dp[5005][5005];

int func(int p, int t)
{
	if (p == P || t == T)
	{
		return 0;
	}

	int& ret = dp[p][t];

	if (ret != -1)
	{
		return ret;
	}
	ret = 0;

	//옷 줄수있는경우
	if (PE[p] <= TS[t])
		ret = max(ret, func(p + 1, t + 1)+1);

	ret = max(ret, func(p + 1, t));
	ret = max(ret, func(p, t + 1));

	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	PE = { 2,3 };
	TS = { 1, 2, 3 };
	P = 2;
	T = 3;
	cout << func(0, 0) << endl;
	cout << result << endl;
	return 0;
}