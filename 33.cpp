#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int H, I;
int NUM;
vector<int> healths;
vector<vector<int>> items;
vector<int> answer;
int itempick[5005];
int dp[10001][5005];

bool func(int n)
{
	//itempick을 가지고 가능한지 판별

	vector<int> tmp;
	for (size_t i = 0; i < I; i++)
	{
		if (itempick[i] == 1)
		{
			tmp.push_back(items[i][1]);
		}
	}

	sort(tmp.begin(), tmp.end(), greater<int>());

	for (size_t i = 0; i < n; i++)
	{
		if (healths[i] - tmp[i] < 100)
		{
			return false;
		}
	}
	return true;
}

void itemSimulation(int idx, int num)
{
	if (idx == I && num <= H)
	{
		if (func(num))
		{
			for (size_t i = 0; i < I; i++)
			{
				if (itempick[i] == 1)
				{
					answer.push_back(items[i][2]);
				}
			}
			sort(answer.begin(), answer.end());

		}
	}
	else
	{
		itempick[idx] = 1;
		itemSimulation(idx + 1, num + 1);
		if (!answer.empty())
		{
			return;
		}

		itempick[idx] = 0;
		itemSimulation(idx + 1, num);
		if (!answer.empty())
		{
			return;
		}
	}
}

int main()
{
	items = { {30, 100}, {500, 30}, {100, 400} };
	healths = { 200, 120, 150 };
	I = items.size();
	H = healths.size();

	int num = 1;
	for (auto& i : items)
	{
		i.push_back(num++);
	}

	sort(healths.begin(), healths.end(), greater<int>());
	sort(items.begin(), items.end(), greater<vector<int>>());

	itemSimulation(0, 0);

	

	return 0;
}