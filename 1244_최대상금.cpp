#include <iostream>
#include <string>
#include <algorithm>	
using namespace std;
int tc, s;
int change;
string num, result;
void func(string n, int c, int l)
{
	if (l>s)
	{
		return;
	}
	if (c == change)
	{
		if (result < n)
		{
			result = n;
		}
		return;
	}
	else
	{
		for (int i = l; i < s; i++)
		{
			for (int j = i+1; j < s; j++)
			{
				swap(n[i], n[j]);
				func(n, c + 1, l+1);
				swap(n[i], n[j]);
			}
		}
	}
	
}


int main()
{
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		
		cin >> num >> change;
		result = num;
		s = num.size();
		func(num, 0, 0);
		

		cout << "#" << t + 1 << " " << result << endl;
	}
	return 0;
}