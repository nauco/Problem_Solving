#include <iostream>
using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
// 1 2 3 4 5 6 7 6 5  4  3  2  1  0 -1 -2 -3 -2 -1 -
//               7 8  9  0  1
//               1 2  3  4  5  6

int pingpong(int n)
{
	if (n <= 7)
		return n;
	else
	{
		int d = (n - 1) % 10;
		int prev = pingpong(n - 1);
		int pprev = pingpong(n - 2);
		if (d == 7)
		{
			if (pprev<prev)
			{
				return prev - 1;
			}
			else
			{
				return prev + 1;
			}
		}
		else
		{
			if (pprev<prev)
			{
				return prev + 1;
			}
			else
			{
				return prev - 1;
			}
		}
	}
}

int main()
{
	for (int i = 1; i < 100; i++)
		cout << pingpong(i) << " ";



	return 0;
}
