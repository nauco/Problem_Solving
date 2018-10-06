#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, result = 999;

vector<int> arr;


int t[13];//cost 최대 13

void func(int n, int cost)
{
	if (n == M)//종료조건
	{
		result = min(result, cost);
		return;
	}


	

}
int main()
{
	arr = { 2, 2, 2, 2, 6};
	M = 5;

	func(0, 0);

	if (result == 999)
	{
		result = -1;
	}
	cout << result << endl;

	
	return 0;
}