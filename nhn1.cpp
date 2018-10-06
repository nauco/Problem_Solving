#include <iostream>
#include <vector> 
using namespace std;

int C;
int P;
int arr[1002];
vector<int> v;

void shuffle(int n, int c)
{
	//위아래 arr[n]남기고 위로
	rotate(v.begin(), v.begin() + arr[n], v.begin()+c - arr[n]);

	if (c-2*arr[n] > 2*arr[n])
	{
		shuffle(n, c - 2 * arr[n]);
	}
}
void func(int n)
{
	if (n == P)
	{
		for (size_t i = 0; i < 5; i++)
		{
			cout << v[i] + 1 << endl;
		}
	}
	else
	{
		shuffle(n, C);


		func(n + 1);
	}
}
int main()
{
	cin >> C >> P;
	for (size_t i = 0; i < P; i++)
	{
		cin >> arr[i];
	}
	for (size_t i = 0; i < C; i++)
	{
		v.push_back(i);
	}
	
	func(0);

	return 0;
}