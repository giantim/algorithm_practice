#include <iostream>
using namespace std;

//struct Node
//{
//	int element;
//	int height;
//	Node* left;
//	Node* right;
//};
//
//void insert(Node* N, int x, long &height)
//{
//	if (x < N->element)
//	{
//		if (N->left != NULL)
//			insert(N->left, x, height);
//		else
//		{
//			Node* temp = new Node();
//			temp->element = x;
//			temp->left = NULL;
//			temp->right = NULL;
//			temp->height = N->height + 1;
//			N->left = temp;
//			height += temp->height;
//			printf("%d\n", height);
//		}
//	}
//	else
//	{
//		if (N->right != NULL)
//			insert(N->right, x, height);
//		else
//		{
//			Node* temp = new Node();
//			temp->element = x;
//			temp->left = NULL;
//			temp->right = NULL;
//			temp->height = N->height + 1;
//			N->right = temp;
//			height += temp->height; 
//			printf("%d\n", height);
//		}
//	}
//}

int P[300000][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*int N, i;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> P[i];
	Node* root = new Node();
	root->element = P[0];
	root->height = 0;
	root->left = NULL;
	root->right = NULL;
	long height = 0;
	printf("%d\n", height);
	for (i = 1; i <= N - 1; i++)
		insert(root, P[i], height);
	system("pause");*/
	int N, i, num, j;
	cin >> N;
	cin >> num;
	P[0][0] = num;
	P[0][1] = 0;
	long height = 0;
	for (i = 1; i <= N - 1; i++)
	{
		cin >> num;
		for (j = 0; j < i; j++)
		{

		}
	}
	system("pause");
	return 0;
}