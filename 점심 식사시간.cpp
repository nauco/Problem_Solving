#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc, N, res;
vector<int> v;

class node
{
public:
	int x;
	int y;
	int t1;
	int t2;
	node(int x, int y) :x(x), y(y) {};
	void setDistance()
	{
		t1 = abs(x - v[0]) + abs(y - v[1]);// + v[2];
		t2 = abs(x - v[3]) + abs(y - v[4]);// + v[5];
	}
};
vector<node> people;


bool cmp1(const node &a, const node &b) {
	return a.t1 < b.t1;
}
bool cmp2(const node &a, const node &b) {
	return a.t2 < b.t2;
}
void simulation(int flag)
{
	int current = 0;
	vector<node> q1;
	vector<node> q2;
	int s = people.size();
	for (size_t i = 0; i < s; i++)
	{
		if (flag & 1)
		{
			q1.push_back(people[i]);
		}
		else
		{
			q2.push_back(people[i]);
		}
		flag >>= 1;
	}
	sort(q1.begin(), q1.end(), cmp1);
	sort(q2.begin(), q2.end(), cmp2);


	if (q1.size() != 0)
	{
		while (q1.size() > 3)
		{
			if (q1[0].t1+v[2] > q1[3].t1)
			{
				q1[3].t1 = q1[0].t1 + v[2];
			}
			q1.erase(q1.begin());
		}
		current = q1[q1.size() - 1].t1+v[2];
	}

	if (q2.size() != 0)
	{
		while (q2.size() > 3)
		{
			if (q2[0].t2 + v[5] > q2[3].t2)
			{
				q2[3].t2 = q2[0].t2 + v[5];
			}
			q2.erase(q2.begin());
		}
		current = max(current, q2[q2.size()-1].t2 + v[5]);
	}

	res = min(res, current);
}
int main()
{
	cin >> tc;
	for (size_t t = 0; t < tc; t++)
	{
		cin >> N;
		int MAN = 0;
		
		res = 987654321;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{

				int in;
				cin >> in;
				if (in == 1)
				{
					MAN++;
					people.push_back(node(i, j));
				}
				else if(in != 0)
				{
					v.push_back(i);
					v.push_back(j);
					v.push_back(in);
				}
			}
		}
		for (size_t i = 0; i < MAN; i++)
		{
			people[i].setDistance();
		}
		 
		int whereWeGo = (1 << MAN);

		while (whereWeGo != 0)
		{
			whereWeGo--;
			simulation(whereWeGo);	
		}

		cout << "#" << t + 1 << " " << res+1 << endl;
		v.clear();
		people.clear();
	}
	return 0;
}