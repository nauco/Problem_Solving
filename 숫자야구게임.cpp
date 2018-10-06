#include <iostream>
using namespace std;
int tc, N, M;

long long fac(int n)
{
	long long result = 1;
	for (size_t i = 2; i <= n; i++)
	{
		result *= i;
	}

	return result;
}
int main()
{
	
	cin >> tc;
	for (size_t i = 1; i <= tc; i++)
	{
		cin >> N;

		long long result = 1;

		for (size_t j = 2; j < N; j++)
		{
			if (N%j == 0)
			{
				long long k = 1;
				for (size_t i = 0; i < N/j; i++)
				{
					k *= fac(j);
				}
				
				result += fac(N) / (k*fac(N / j));
			}
		}


		cout << "#" << i << " " << result << endl;
	}
	return 0;
}