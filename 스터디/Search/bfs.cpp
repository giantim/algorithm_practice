#include <iostream>
#include <queue>
using namespace std;

int graph[10][10];
bool visited[10];

void bfs(int start)
{
	int i;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int currentNode = q.front();
		cout << currentNode + 1 << " ";
		q.pop();
		for (i = 0; i < 10; i++)
		{
			if (graph[currentNode][i] && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			graph[i][j] = 0;
	for (i = 0; i < 10; i++)
		visited[i] = false;
	int start, end;
	for (i = 0; i < 10; i++)
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}
	cout << "bfs queue" << endl;
	bfs(0);
	system("pause");
	return 0;
}

//input
//1 2
//1 3
//2 4
//2 5
//4 8
//5 8
//3 6
//3 7
//6 8
//7 8