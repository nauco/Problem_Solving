#include <iostream>
#include <algorithm>
using namespace std;


int arr[12];
int op[4];
int N;
int maxV;
int minV;
int M;


//++ -- ** //
void func(int n, int res)
{
	if (n==M)
	{
		maxV = max(maxV, res);
		minV = min(minV, res);
	}


	if (op[0] > 0)//+
	{
		op[0]--;
		func(n + 1, res + arr[n + 1]);
		op[0]++;
	}

	if (op[1] > 0)//-
	{
		op[1]--;
		func(n + 1, res - arr[n + 1]);
		op[1]++;
	}
	if (op[2] > 0)//*
	{
		op[2]--;
		func(n + 1, res*arr[n + 1]);
		op[2]++;
	}
	if (op[3] > 0)// /
	{
		op[3]--;
		func(n + 1, res / arr[n + 1]);
		op[3]++;
	}
}

int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	M = 0;
	for (size_t i = 0; i < 4; i++)
	{
		cin >> op[i];
		M += op[i];
	}


	maxV = -1000000000;
	minV = 1000000000;

	func(0, arr[0]);

	cout << maxV << endl << minV << endl;




	return 0;
}