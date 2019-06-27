#include <iostream>
using namespace std;

int main()
{
	int vertex, edge;
	cin >> vertex >> edge;
	int** graph = new int* [vertex];
	for (int i = 0; i < vertex; i++)
	{
		graph[i] = new int[vertex];
		for (int j = 0; j < vertex; j++)
			graph[i][j] = 0;
	}
	int start, end;
	for (int i = 0; i < edge; i++)
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
	}
	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
	return 0;
}

//input
//4 8
//1 2
//1 3
//2 1
//2 4
//3 2
//3 4
//4 1
//4 2
