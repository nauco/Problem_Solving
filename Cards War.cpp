#include <iostream>
#include <string>
using namespace std;


int solution(string &A, string &B) {
	// write your code in C++14 (g++ 6.2.0)
	//23456789JQKA
	//23456789AJKQ
	//K->R
	//A->S
	int result = 0;
	int sz = A.size();
	for (size_t i = 0; i < sz; i++)
	{
		if (A[i] == 'K')
			A[i] = 'R';
		if (B[i] == 'K')
			B[i] = 'R';

		if (A[i] == 'A')
			A[i] = 'S';
		if (B[i] == 'A')
			B[i] = 'S';

		if (A[i]>B[i])
		{
			result++;
		}
	}
	return result;
}


int main()
{
	string s[4] = { "A586QK", "JJ653K" ,"23A84Q", "K2Q25J" };

	cout << solution(s[0], s[1]) << endl;
	cout << solution(s[2], s[3]) << endl;


	return 0;
}