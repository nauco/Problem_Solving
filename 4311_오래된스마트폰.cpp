#include <iostream>
#include <algorithm>
using namespace std;

int N, O, M, tc, goal;

int arr[10];
int op[5];

int result = 999999;

//내가 할수있는 경우의 수 N+O;
void func(int n)
{
	
}

int main()
{
	cin >> tc;
	for (size_t i = 0; i < tc; i++)
	{
		int t;
		cin >> N >> O >> M;
		for (size_t j = 0; j < N; j++)
		{
			cin >> t;
			arr[t] = 1;
		}

		for (size_t j = 0; j < O; j++)
		{
			cin >> t;
			op[t] = 1;
		}
		cin >> goal;

		func(0);

		cout << "#" << i + 1 << " " << result << endl;

		memset(arr, 0, sizeof(arr));
		memset(op, 0, sizeof(op));
	}
	return 0;
}