/*
: �������Ŀ��� �� ���Ұ� ���Ե� ������ ��ġ�� �Ÿ��� �ָ� �ſ� �� ȿ����

1. ���������� ��� ���� ���ĵ� �迭�� ���ؼ��� �����ٴ� �Ϳ� ������ ���
=> �κи���Ʈ�� ������ �κ������� �����ع���

=> ���������� O(n^2)���� ����

=> ���������� �ִ� �������� ��ҵ��� ���Ե� ��, �̿��� ��ġ�θ� �̵��Ѵٴ� ��.

=> �� ���Ŀ����� ��ҵ��� �ָ� ������ ��ġ�ε� �̵�����

2. �˰���
(1) �־��� �迭�� ���������� ���� ���� �κи���Ʈ�� �ɰ�

(2) �� �κи���Ʈ�� ��������

(3) ��� �κи���Ʈ�� ���ĵǸ� �ٽ� ��ü ����Ʈ�� �� ���� ������ �κи���Ʈ��

(4) �κи���Ʈ ������ 1�� �Ǹ� ���� ��
=> ����� �κи���Ʈ ������ 1�̸� �׳� ���������� �ϴ°Ͱ� ����
   but �̹� ������� ������ �� �����̱� ������ ���������� ȿ�������� �����


3. �ð����⵵
 => �־� O(n^2)
    ��� O(n^1.5)
*/
#include <iostream>
using namespace std;


//gap�� �����ϸ鼭(��, �κи���Ʈ�μ�) �������� �ϴ� �Լ�
void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i+ gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j =j-gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

//gap = gap/2 �� �ٿ������鼭 gap == 1�� �ɶ� ���� �κи���Ʈ�� ���� �������� ����
void shell_sort(int list[], int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

int main()
{
	//�迭�Է�
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	shell_sort(arr, size);
	//Ȯ��
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}