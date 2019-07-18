#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N, M, V;
int graph[1000][1000];
bool visit[1000];

void dfs()
{
	stack<int> s;
	s.push(V - 1);
	cout << V << ' ';
	visit[V - 1] = true;
	int i;
	while (!s.empty())
	{
		int node = s.top();
		for (i = 0; i < N; i++)
		{
			if (graph[node][i] == 1 && visit[i] == false)
			{
				cout << i + 1 << ' ';
				s.push(i);
				visit[i] = true;
				break;
			}
		}
		if (i == N)
			s.pop();
	}
	cout << endl;
}

void bfs()
{
	queue<int> q;
	q.push(V - 1);
	cout << V << ' ';
	visit[V - 1] = true;
	int i;
	while (!q.empty())
	{
		int node = q.front();
		for (i = 0; i < N; i++)
		{
			if (graph[node][i] == 1 && visit[i] == false)
			{
				q.push(i);
				cout << i + 1 << ' ';
				visit[i] = true;
			}
		}
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
		cin >> N >> M >> V;
	int i;
	int start, end;
	for (i = 0; i < M; i++)
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}
	dfs();
	for (i = 0; i < N; i++)
		visit[i] = false;
	bfs();
	system("pause");
	return 0;
}