#include <iostream>
#include <string.h>
using namespace std;
int T, n;
int answer;
int arr[100001];
int visit[100001];
int selected[100001];

void dfs(int n)
{
	visit[n] = true;
	answer++;
	selected[arr[n]]--;
	if (!visit[arr[n]] && !selected[arr[n]])
	{
		dfs(arr[n]);
	}
}

int main()
{
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		answer = 0;
		cin >> n;
		memset(visit, 0, sizeof(visit));
		memset(selected, 0, sizeof(selected));
		for (size_t j = 1; j <= n; j++)
		{
			cin >> arr[j];
			++selected[arr[j]];
		}

		for (size_t j = 1; j <= n; j++)
		{
			if (!visit[j] && !selected[j])
				dfs(j);
		}
		cout << answer << endl;
	}

	return 0;
}