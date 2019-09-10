#include <iostream>
#include <vector>

using namespace std;

class Cube
{
public:
	int index;
	int number;
	int east, west, south, north;

	Cube()
	{
		this->index = 0;
		this->number = -1;
		this->east = this->west = this->south = this->north = 0;
	}

	Cube(int index, int number)
	{
		this->index = index;
		this->number = number;
		this->east = this->west = this->south = this->north = 0;
	}

	void setDirect()
	{
		this->east = 3;
		this->west = 4;
		this->south = 5;
		this->north = 2;
	}

	int getNextLoc(int direction)
	{
		switch (direction)
		{
		case 1:
			return this->east;
		case 2:
			return this->west;
		case 3:
			return this->north;
		case 4:
			return this->south;
		default:
			return 0;
		}
	}

	void changeLoc(int direction, const Cube& c)
	{
		switch (direction)
		{
		case 1:
			this->east = 7 - c.index;
			this->west = c.index;
			this->south = c.south;
			this->north = c.north;
			break;
		case 2:
			this->east = c.index;
			this->west = 7 - c.index;
			this->south = c.south;
			this->north = c.north;
			break;
		case 3:
			this->east = c.east;
			this->west = c.west;
			this->south = c.index;
			this->north = 7 - c.index;
			break;
		case 4:
			this->east = c.east;
			this->west = c.west;
			this->south = 7 - c.index;
			this->north = c.index;
			break;
		default:
			break;
		}
	}
};

int board[20][20];
vector<Cube> cube;

void setLocation(int x, int y, int direction, int& nextX, int& nextY)
{
	switch (direction)
	{
	case 1:
		nextX = x;
		nextY = y + 1;
		break;
	case 2:
		nextX = x;
		nextY = y - 1;
		break;
	case 3:
		nextX = x - 1;
		nextY = y;
		break;
	case 4:
		nextX = x + 1;
		nextY = y;
		break;
	default:
		break;
	}
}

bool checkRange(int nextX, int nextY, int N, int M)
{
	if ((nextX >= 0 && nextX <= N - 1)
		&& (nextY >= 0 && nextY <= M - 1))
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			board[i][j] = -1;
	}

	int N, M;
	int x, y;
	int K;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int number;
			cin >> number;
			board[i][j] = number;
		}
	}

	cube.push_back(Cube(0, -1));
	for (int i = 1; i <= 6; i++)
		cube.push_back(Cube(i, 0));
	cube[1].setDirect();
	
	int cubeIndex = 1;
	for (int i = 0; i < K; i++)
	{
		int direction;
		cin >> direction;
		int nextX;
		int nextY;
		setLocation(x, y, direction, nextX, nextY);
		if (checkRange(nextX, nextY, N, M))
		{
			x = nextX;
			y = nextY;
			int nextCube = cube[cubeIndex].getNextLoc(direction);
			cube[nextCube].changeLoc(direction, cube[cubeIndex]);
			cubeIndex = nextCube;
			if (board[x][y] == 0)
				board[x][y] = cube[cubeIndex].number;
			else
			{
				int temp = board[x][y];
				board[x][y] = 0;
				cube[cubeIndex].number = temp;
			}
			cout << cube[7 - cubeIndex].number << endl;
		}
	}
	return 0;
}