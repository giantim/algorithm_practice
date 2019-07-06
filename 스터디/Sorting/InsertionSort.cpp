/*
<��������>
1. ���ĵ� ����Ʈ�� ���� �ȵ� ���� �ϳ����� �˸��� ��ġ�� �����Ѵٴ� ���̵��

2. ���̵� �ڵ�� ������ ������ ��� ���� ���鼭 ������ ��ġ�� ã�ư�(���ڸ� ����)

=> �� ó�� ������ �� ���Ҷ����� swap���״µ� �װͺ��� �� ȿ������ ����� å�� �־���
*/
#include <iostream>
using namespace std;
int main()
{
	//���� ����
	int temp, i, j, k;
	//�迭�Է�
	int size;
	cin >> size;
	int* arr = new int[size];
	for (k = 0; k < size; k++)
		cin >> arr[k];

	/*�˰��� ����
	1. ��Ƚ�� = 1+2+...+(size-1) = (size-1)*size/2
	2. �̵�Ƚ�� = 3+4+...+(size+1) = (size-1)*size/2 + 2*(size-1)
	=> O(n^2)
	*/
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
		arr[j + 1] = temp;

	}

	//��ȿ���� ���====>�������� ����(�������� ����=>���� ������ ����)
	//for (i = 1; i < size; i++)
	//{
	//	for (j = i; j > 0; j--)
	//	{
	//		if (arr[j] < arr[j - 1])
	//		{				
	//			temp = arr[j];
	//			arr[j] = arr[j - 1];
	//			arr[j - 1] = temp;				
	//		}
	//	}
	//}

	//Ȯ��
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}