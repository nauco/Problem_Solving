#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[20];
int selected[20];
int visit[20];
int result;


int getResult()
{
	int a = 0;
	for (size_t i = 0; i < N-1; i++)
	{
		a += abs(selected[i] - selected[i + 1]);
	}
	return a;
}

void make(int n)
{
	if (n == N)
	{
		result = max(result, getResult());
	}
	else
	{
		for (size_t i = 0; i < N; i++)
		{
			if (visit[i])
				continue;
			visit[i] = true;
			selected[n] = arr[i];
			make(n + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	make(0);
	cout << result << endl;
	return 0;
}