#include <iostream>
#include <algorithm>
using namespace std;

int L, C, A, B;
char arr[30];
char v[30];

void func(int n, int t, int a, int b)//개수
{
	if (n == L && a >= 1 && b >= 2)
	{
		for (size_t i = 0; i < L; i++)
		{
			cout << v[i];
		}
		cout << endl;
	}
	else
	{
		//체크
		if (n < L)
		{
			v[n] = arr[t];
			if (arr[t] == 'a' || arr[t] == 'e' || arr[t] == 'o' || arr[t] == 'i' || arr[t] == 'u')
				func(n + 1, t + 1, a + 1, b);
			else
				func(n + 1, t + 1, a, b + 1);
		}

		//패스
		if (L - n < C - t)
		{
			func(n, t + 1, a, b);
		}

	}

}

int main()
{
	cin >> L >> C;
	for (size_t i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);
	func(0, 0, 0, 0);

	return 0;
}