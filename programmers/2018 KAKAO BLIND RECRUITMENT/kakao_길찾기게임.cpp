#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Pair
{
public:
	int x;
	int y;
	int index;
	Pair* left;
	Pair* right;

	Pair()
	{
		x = 0;
		y = 0;
		index = 0;
		left = nullptr;
		right = nullptr;
	}

	Pair(int x, int y, int index)
	{
		this->x = x;
		this->y = y;
		this->index = index;
		left = nullptr;
		right = nullptr;
	}
};

vector<int> preOrder;
vector<int> postOrder;

class Tree
{
public:
	Pair* root;

	Tree()
	{
		root = nullptr;
	}

	void insert(Pair p)
	{
		recursiveInsert(p, root);
	}

	void recursiveInsert(Pair p, Pair* pos)
	{
		if (p.x > pos->x)
		{
			if (pos->right == nullptr)
				pos->right = new Pair(p.x, p.y, p.index);
			else
				recursiveInsert(p, pos->right);
		}
		else
		{
			if (pos->left == nullptr)
				pos->left = new Pair(p.x, p.y, p.index);
			else
				recursiveInsert(p, pos->left);
		}
	}

	void preOrderTravel(Pair* p)
	{
		if (p != nullptr)
		{
			preOrder.push_back(p->index);
			preOrderTravel(p->left);
			preOrderTravel(p->right);
		}
	}

	void postOrderTravel(Pair* p)
	{
		if (p != nullptr)
		{
			postOrderTravel(p->left);
			postOrderTravel(p->right);
			postOrder.push_back(p->index);
		}
	}
};

bool compare(const Pair& p1, const Pair& p2)
{
	if (p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y > p2.y;
}

vector<Pair> v;
Tree* t;

void makeTree()
{
	t = new Tree();
	t->root = new Pair(v[1].x, v[1].y, v[1].index);
	for (int i = 2; i < v.size(); i++)
		t->insert(v[i]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;

	v.push_back(Pair(-1, -1, -1));
	for (int i = 0; i < nodeinfo.size(); i++)
		v.push_back(Pair(nodeinfo[i][0], nodeinfo[i][1], i + 1));
	stable_sort(v.begin() + 1, v.end(), compare);
	makeTree();
	t->preOrderTravel(t->root);
	t->postOrderTravel(t->root);
	answer.push_back(preOrder);
	answer.push_back(postOrder);

	return answer;
}

int main()
{
	vector<vector<int>> nodeinfo;
	vector<int> v;

	v.push_back(5);
	v.push_back(3);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(11);
	v.push_back(5);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(13);
	v.push_back(3);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(3);
	v.push_back(5);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(6);
	v.push_back(1);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(1);
	v.push_back(3);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(8);
	v.push_back(6);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(7);
	v.push_back(2);
	nodeinfo.push_back(v);
	v.clear();

	v.push_back(2);
	v.push_back(2);
	nodeinfo.push_back(v);
	v.clear();

	vector<vector<int>> answer = solution(nodeinfo);
	return 0;
}

// [[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]