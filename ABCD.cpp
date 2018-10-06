#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(int A, int B, int C, int D) {
	//AB-CD
	//A2B2C2D2 -2(AC+BC)

	int K = A*A + B*B + C*C + D*D;

	return K - 2*(min(A*C + B*D, min(A*D + B*C, A*B + C*D)));
}


int main()
{
	cout << solution(1, 1, 2, 3) << endl;
	cout << solution(2, 4, 2, 4) << endl;

	return 0;
}