#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int S;
int dp[10001][10001];
int func(int n, int clip)
{
	if (n == S)
	{
		return 0;
	}

	int& ret = dp[n][clip];

	if (ret != -1)
	{
		return ret;
	}

	ret = 999999;

	//Ŭ�����忡 ����
	if (clip != n)
	{
		ret = min(ret, func(n, n) + 1);
	}

	//�ٿ��ֱ�
	if (n<S)
		ret = min(ret, func(n + clip, clip) + 1);

	//����
	if (n>3)
	{
		ret = min(ret, func(n - 1, clip) + 1);
	}

	return ret;

}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> S;
	cout << func(1, 0) << endl;
	return 0;
}