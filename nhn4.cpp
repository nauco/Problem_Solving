#include <iostream>
#include <string>
using namespace std;

int N;
int dx[] = {0, 0, 0, 0};
int dy[] = {0, 0, 0, 0};
string arr[51][51];

class node
{
public:
	
};



void play(int turn)
{
	if (true)//Ȯ�尡���Ѱ����� ������
	{
		//Ȯ��

		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				//�����̸�
				if (arr[i][j] <= "15" && arr[i][j] >= "0" )
				{
					for (size_t k = 0; k < 4; k++)
					{

					}


				}
			}
		}




		play(turn + 1);
	}
	else
	{
		//���
	}



}

//��(1), ��(2), ��(4), ��(8)
int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	play(0);
	return 0;
}