#include <iostream>
#include <string.h>
using namespace std;

int arr[11];
int self(int n)
{
	int t = n;//�ӽú���
	int c = 0;//�ڸ��� ī��Ʈ
	int f = 0;//flag
			  //�ϴ� ���ϱ� ���� �Ǵ��� Ȯ��
	while (t != 0)
	{
		if (arr[t % 10] == 0)
		{
			f = 1;//����
		}
		c++;
		t /= 10;
	}
	if (f == 0)
	{
		return c + 1;//c�� ������ ��� ����
	}
	return -1;
}

int func(int n)
{
	int t = n;//�ӽú���
	int c = 0;//�ڸ��� ī��Ʈ
	int f = 0;//flag
	//�ϴ� ���ϱ� ���� �Ǵ��� Ȯ��
	while (t != 0)
	{
		if (arr[t % 10] == 0)
		{
			f = 1;//����
		}
		c++;
		t /= 10;
	}
	if (f == 0)
	{
		return c + 1;//c�� ������ ��� ����
	}

	for (int i = n - 1; i > 10; i--)
	{
		if (self(i) == -1)
		{
			continue;
		}
		if (n%i == 0)
		{
			int r = func(i);
			if (r == -1)
			{
				continue;
			}
			else
			{
				int rr = func(n / i);
				if (rr == -1)
				{
					continue;
				}
				return r + rr;
			}
		}
	}

	for (int i = 10; i >= 2; i--)
	{
		if (arr[i] == 0)
			continue;
		if (n%i == 0)
		{
			int result = func(n / i);
			if (result == -1)//����
			{
				continue;
			}
			else
			{
				return result + 2;
			}
		}
	}
	return -1;
}

int main()
{
	int testcase, num;
	cin >> testcase;
	for (size_t tc = 1; tc <= testcase; tc++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
		cin >> num;
		int res;

		res = func(num);
		cout << "#" << tc << " " << res << endl;
	}

	return 0;
}