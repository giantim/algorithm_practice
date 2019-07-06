/*���⿡ �ռ�, ��� �ڵ�� �迭 �Է� -> �˰���(���� ����) -> ���ĵ� �迭 ��� ������ ����������*/
/*
/*<��������>
1. idea: ������ ����Ʈ���� ���� ���� ���ڸ� ������ ���� ����Ʈ�� �̵��ϴ� �۾��� ��Ǯ��
=> Ư¡������ ���̴� �κ��� ������ ����Ʈ�� �ϳ� �����ؼ� �������� �����ϱ� 
   "(������ ����Ʈ ���� ��) + (���� ����Ʈ�� ���� ��) = ���� ������ ��" ���� ����
   => ���ڸ� ���� ����

2. ���ڸ� ����( : �Է� �迭 �̿ܿ��� �ٸ� �߰� �޸𸮸� �䱸���� �ʴ� ���� ���) ���

tip 
=> �Ϲ������� (�񱳿���) == 3*(�̵�����)
*/

#include <iostream>
using namespace std;
int main()
{
	//�迭�Է�
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	/*�˰��� ����
	1. ��Ƚ�� = (size-1) * (size-i-1)
	2. �̵�Ƚ�� = 3*(size-1)
	=> O(n^2)
	*/	
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		/*���� �ȵ� ����Ʈ���� ���� ���� ���� �ش�Ǵ� index����*/
		int temp_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[temp_index] > arr[j])
				temp_index = j;
		}

		//temp = arr[i];
		//arr[i] = arr[temp_index];
		//arr[temp_index] = temp;

		if (temp_index != i)
		{
			/*tip
			= > �Ϲ�������(�񱳿���) < 3 * (�̵�����)
			���� ���ǹ� �ִ°��� �� ȿ����*/
			temp = arr[i];
			arr[i] = arr[temp_index];
			arr[temp_index] = temp;
		}
	}

	//Ȯ��
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

