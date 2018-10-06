#include <string>
#include <vector>

#define INF 987654321
using namespace std;

int V, E, K; // 정점의 수, 간선의 수, 시작 정점 번호
vector<vector<int>> dist;
vector<vector<int>> graph; // 간선 가중치. 그래프의 인접 리스트.
vector<vector<int>> directory;
vector<vector<int>> query;


void floydWarshall()
{
	
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}



int main()
{
	
	vector<int> answer;
	directory = { {1,2},{1,3},{2,4},{2,5} };
	query = { {1,5}, {2,5},{3,5},{4,5} };
	V = 5;
	E = directory.size();

	graph.assign(V, vector<int>(V, INF));
	dist.assign(V, vector<int>(V, INF));


	for (auto& i : directory)
	{
		graph[i[0]-1][i[1]-1] = 1;
		graph[i[1]-1][i[0]-1] = 1;
	}

	floydWarshall();
	
	for (size_t i = 0; i < V; i++)
	{
		dist[i][i] = 0;
	}


	for (auto& i : query)
	{
		answer.push_back(dist[i[1]-1][i[0]-1]+1);
	}

	return 0;
}