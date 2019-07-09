#include <iostream>
using namespace std;

int N;
char arr[50][50];

int calHeight(int row, int column)
{
	char original = arr[row][column];
	int sum = 0;
	int i;
	// ��
	for (i = row - 1; i >= 0; i--)
	{
		if (original == arr[i][column])
			sum++;
		else
			break;
	}

	// �Ʒ�
	for (i = row; i < N; i++)
	{
		if (original == arr[i][column])
			sum++;
		else
			break;
	}
	return sum;
}

int calbreadth(int row, int column)
{
	char original = arr[row][column];
	int sum = 0;
	int i;
	// ������
	for (i = column; i < N; i++)
	{
		if (original == arr[row][i])
			sum++;
		else
			break;
	}

	// ����
	for (i = column - 1; i >= 0; i--)
	{
		if (original == arr[row][i])
			sum++;
		else
			break;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int originalMax = 0;
	int tempMax, height, breadth;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			height = calHeight(i, j);
			breadth = calbreadth(i, j);
			tempMax = height >= breadth ? height : breadth;
			originalMax = originalMax >= tempMax ? originalMax : tempMax;
		}
	}
	int max = 0;
	int rightMax, belowMax;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			char temp = arr[i][j];
			// �������� �ٲ��� ��
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;
			height = calHeight(i, j);
			breadth = calbreadth(i, j);
			rightMax = height >= breadth ? height : breadth;
			arr[i][j + 1] = arr[i][j];
			arr[i][j] = temp;
			
			// �Ʒ��� �ٲ��� ��
			arr[i][j] = arr[i + 1][j];
			arr[i + 1][j] = arr[i][j];
			height = calHeight(i, j);
			breadth = calbreadth(i, j);
			belowMax = height >= breadth ? height : breadth;
			arr[i + 1][j] = arr[i][j];
			arr[i][j] = temp;

			tempMax = rightMax >= belowMax ? rightMax : belowMax;
			max = originalMax >= tempMax ? originalMax : tempMax;
		}
	}
	cout << max;
	return 0;
}