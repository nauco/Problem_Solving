#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

string str;
int N;
bool table[2501][2501];
int dp[2501];

bool check(int front, int end)
{
	if (front > end)
	{
		swap(front, end);
	}

	while (str[front] == str[end])
	{
		if (front == end)
		{
			return true;
		}
		if (front + 1 == end && str[front] == str[end])
		{
			return true;
		}
		front++;
		end--;


	}
	return false;
}

int func(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int& ret = dp[n];
	if (ret != -1)
		return ret;
	ret = 9999;
	for (int i = n; i >= 0; i--)
	{
		if (table[n][i])
			ret = min(ret, func(i - 1) + 1);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> str;
	N = str.size();

	for (int i = 0; i < N; i++)
	{
		table[i][i] = true;
		for (int j = 0; j < i; j++)
		{
			table[i][j] = check(j, i);
			table[j][i] = table[i][j];
		}
	}

	cout << func(N - 1) << endl;


	return 0;
}