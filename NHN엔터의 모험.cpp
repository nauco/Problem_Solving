#include <iostream>
using namespace std;

int N;
int arr[20][20];
int main()
{
	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}



	return 0;
}