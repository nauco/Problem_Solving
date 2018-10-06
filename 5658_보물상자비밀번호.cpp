#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, K;
char c;

vector<int> v;

int hextodec()
{
	int answer = 0;

	for (int i = 0; i < N/4; i++)
	{
		int t = 1;

		for (int j = i+1; j < N/4; j++)
		{
			t *= 16;
		}
		answer += t*v[i];
	}
	return answer;
}

int main()
{
	cin >> T;
	for (size_t tc = 0; tc < T; tc++)
	{
		cin >> N >> K;
		v.assign(N, 0);
		vector<int> result;
		for (size_t i = 0; i < N; i++)
		{
			cin >> c;
			if (c >= '0' && c <= '9')
			{
				v[i] = (int)(c - '0');
			}
			else
			{
				v[i] = (int)(c - 'A' + 10);
			}
		}

		for (int i = 0; i < N; i++)
		{
			result.push_back(hextodec());
			rotate(v.begin(), v.begin() + 1, v.end());
		}

		sort(result.begin(), result.end(), greater<int>());
		result.erase(unique(result.begin(), result.end()), result.end());

		cout << "#" << tc + 1 << " " << result[K - 1] << endl;
	}
	return 0;
}