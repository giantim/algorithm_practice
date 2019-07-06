#include <iostream>
#include <stack>
using namespace std;

int graph[10][10];
bool visited[10];

void dfs_recursion(int start)
{
	cout << start + 1 << " ";
	visited[start] = true;
	for (int i = 0; i < 10; i++)
	{
		if (graph[start][i] && !visited[i])
			dfs_recursion(i);
	}
}

void dfs_stack(int start)
{
	int i;
	stack<int> s;
	s.push(start);
	visited[start] = true;
	cout << start + 1 << " ";
	while (!s.empty())
	{
		int currentNode = s.top();
		for (i = 0; i < 10; i++)
		{
			if (graph[currentNode][i] && !visited[i])
			{
				s.push(i);
				cout << i + 1 << " ";
				visited[i] = true;
				break;
			}
		}
		if (i == 10)
			s.pop();
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
	cout << "dfs recursion" << endl;
	dfs_recursion(0);
	cout << endl;
	for (i = 0; i < 10; i++)
		visited[i] = false;
	cout << "dfs stack" << endl;
	dfs_stack(0);
	cout << endl;
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