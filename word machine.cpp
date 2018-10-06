#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

#define LIMIT 1048575

int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	stringstream ss(S);
	string part;
	stack<int> st;
	while (getline(ss, part, ' '))
	{
		//cout << part << endl;

		if (part == "DUP")
		{
			if (!st.empty())
			{
				st.push(st.top());
			}
		}
		else if (part == "POP")
		{
			if (!st.empty())
			{
				st.pop();
			}
		}
		else if (part == "-")
		{
			int first, second;

			if (st.size()<2)
				return -1;
			first = st.top();
			st.pop();
			second = st.top();
			st.pop();

			if (first - second <0)
			{
				return -1;
			}
			st.push(first - second);

		}
		else if (part == "+")
		{
			int first, second;
			if (st.size()<2)
				return -1;
			first = st.top();
			st.pop();
			second = st.top();
			st.pop();

			if (first + second > LIMIT)
			{
				return -1;
			}
			st.push(first + second);
		}
		else
		{
			st.push(stoi(part));
		}
	}

	if (st.top() >= 0)
	{
		return st.top();
	}
	else
	{
		return -1;
	}
}


int main()
{
	string s1 = "13 DUP 4 POP 5 DUP + DUP + -";
	string s2 = "5 6 + -";
	string s3 = "3 DUP 5 - -";

	cout << solution(s1) << endl;
	cout << solution(s2) << endl;
	cout << solution(s3) << endl;

}