//배열하나 더둬서 계산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C, res;
int arr[6];
int dp[6][31];
int func(int n, int h)
{
	if (n == M)
	{
		return 0;
	}
	int& ret = dp[n][h];
	if (ret != -1)
	{
		return ret;
	}
	ret = 0;
	if (h+arr[n+1]<=C)
	{
		ret = max(ret, func(n + 1, h+arr[n+1])+arr[n+1]*arr[n+1]);
	}
		ret = max(ret, func(n + 1, h));

	return ret;
}
int main()
{
	int tc;
	cin >> tc;
	for (size_t testcase = 0; testcase < tc; testcase++)
	{
		cin >> N >> M >> C;
		vector< vector<int> > v(N, vector<int>(N, 0));
		vector< vector<int> > sum(N, vector<int>(N-M+1, 0));
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				cin >> v[i][j];
			}
		}
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N-M+1; j++)
			{
				memset(dp, -1, sizeof(dp));

				for (size_t k = 0; k < M; k++)//벌통
				{
					arr[k+1] = v[i][j + k];
				}
				sum[i][j] = func(0,0);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N-M+1; j++)
			{
				for (int x = 0; x < N; x++)
				{
					for (int y = 0; y < N-M+1; y++)
					{
						if (i == x && abs(j - y) < M)
							continue;
						res = max(res, sum[i][j] + sum[x][y]);
					}
				}
			}
		}
		cout << "#" << testcase + 1 << " " << res << endl;
		
		res = 0;
	}
	return 0;
}