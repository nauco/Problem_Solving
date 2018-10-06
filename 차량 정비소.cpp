//이거 완전 OS 만드는거 아니냐
//일단 노드 안만들고 해보기
//접수와 정비를 하나로
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N, M, K, A, B, res;
int at[21];
int bt[21];
int a[21];
int b[21];
int kt[1001];

class node
{
public:
	int num;
	int t;
	int reception;
	node(int num, int t, int r) :num(num), t(t),reception(r) {};
	int areyou(int r) const
	{
		if (reception == A && r == B)
		{
			return num;
		}
		else
		{
			return 0;
		}
	}
};
bool operator<(const node& a, const node& b)
{
	if (a.t == b.t)
	{
		return a.reception > b.reception;
	}
	return a.t > b.t;
}
priority_queue<node> pq;

int main()
{
	int tc;
	cin >> tc;
	for (size_t testcase = 1; testcase <= tc; testcase++)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		
		cin >> N >> M >> K >> A >> B;

		for (size_t i = 1; i <= N; i++)
			cin >> at[i];
		for (size_t i = 1; i <= M; i++)
			cin >> bt[i];
		for (size_t i = 1; i <= K; i++)
			cin >> kt[i];

		
	//접수 -> 정비
	//먼저 기다리는 고객이 우선한다.
	//접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우
	//  이용했던 접수 창구번호가 작은 고객이 우선한다.
	//빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.
		

		for (size_t i = 1; i <= K; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{

				if (kt[i] >= a[j])//자리 있음
				{
					a[j] = at[j] + kt[i];//i가 온시간 + j접수처리시간
					//kt[i] += at[j];//창구로
					pq.push(node(i,kt[i]+at[j], j));
					break;//1984
				}
				if (j==N)//창구 다 돌았는데 자리가 없어
				{
					//가장빨리 끝나는 곳으로
					int t, thatj = 1;
					t = a[1];
					for (size_t k = 1; k <= N; k++)
					{
						if (t > a[k])
						{
							t = a[k];
							thatj = k;
						}
					}
					a[thatj] += at[thatj];
					pq.push(node(i, a[thatj], thatj));
				}
			}
		}

		while (!pq.empty())
		{
			int tt = pq.top().t;
			for (size_t i = 1; i <= M; i++)
			{
				if (tt >= b[i])
				{
					b[i] = tt + bt[i];
					res += pq.top().areyou(i);
					break;
				}
				if (i == M)
				{
					int t, thatj = 1;
					t = b[1];
					for (size_t k = 1; k <= M; k++)
					{
						if (t > b[k])
						{
							t = b[k];
							thatj = k;
						}
					}
					b[thatj] += bt[thatj];
					res += pq.top().areyou(thatj);
				}
			}
			pq.pop();
		}
		if (res == 0)
		{
			res = -1;
		}
		cout << "#" << testcase << " " << res << endl;
		res = 0;
	}

	return 0;
}