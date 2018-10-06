#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[9];
int N, res;


void func(int n, int a, int b)
{
	if (n==N)
	{
		res++;
		return;
	}

	if (a+arr[n]<=b)
	{
		func(n + 1, a + arr[n], b);

	}
	if (a<=b+arr[n])
	{
		func(n + 1, a, b + arr[n]);
	}

}

int main()
{
	int tc;
	cin >> tc;
	for (size_t test = 0; test < tc; test++)
	{
		res = 0;
		cin >> N;
		for (size_t i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		
		do
		{
			func(0, 0, 0);
		} while (next_permutation(arr,arr+N));
		

		cout << "#" << test + 1 <<" " << res << endl;
	}
	return 0;
}