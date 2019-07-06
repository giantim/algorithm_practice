/*
<�� ����>
1. �̰͵� ���� ���� ���� ���
(1) ��ü ����Ʈ�� 2���� �κи���Ʈ�� ���Ұ� ���ÿ� ������� ����(MergeSort�ʹ� ����)
(=> �ǹ��� �������� ������ �ǹ����� ������ �������� ū���� ������)
(2) �ǹ��� �������� ���� ������ �κи���Ʈ�鿡 ���ؼ� �ٽ��ѹ� (1)�� �ݺ�
(3) �κи���Ʈ�� ���� �ɰ��� ������ Ż���ϸ� ���� ��

+a => ����� ���⼭�� �ǹ��� �κи���Ʈ ���� ���ʰ����� ����

2. �պ����İ��� ����
=> �� 1/2�� ��Ģ������ �ɰ� �� �պ����� ������ ������ �̷����
   vs
   �ǹ��� �������� ������ ����ϰ� �Ǹ鼭 �κи���Ʈ�� �ɰ����� ���� �� �ɰ����� �� ������ ����

3. QuickSort�� �ϱ� ���ؼ� quick_sort�� partition�Լ� �ʿ�

(1) quick_sort := partition ȣ�� �� partition�� ��ȯ�� �ǹ��� �������� �κи���Ʈ�� �����Ͽ� quick_sort()�� ���ȣ��
				  (merge_sort ���� ���� �� ���� �� merge�� ȣ��! �����ν�)

(2) partition  := �� �κи���Ʈ���� �ٽ��ѹ� �ǹ��� �������� ����ϰ� ���� �� �ǹ���ġ ��ȯ
=> �� ������ å�� �׸��� ���� ����
*/

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int partition(int list[], int left, int right)
{
	//left: �κи���Ʈ ����
	//right:�κи���Ʈ ��
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high);	//low�� high�� �����ϱ� ������ �ݺ�

	temp = list[left];
	list[left] = list[high];
	list[high] = temp;
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main()
{
	//�迭�Է�
	int size;
	cout << "MAX_SIZE���� �۰� �Է��Ͻÿ�: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	/*�˰��� ����
	*/
	quick_sort(arr, 0, size - 1);

	//Ȯ��
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


/*
4. ���⵵ �м�

(1) ���ȣ���� ���̴� �պ����İ� ���������� log2(n)
(2) �� ȣ�� �ܰ迡�� �� Ƚ��: ��� n��
                    �̵� Ƚ��=> ��Ƚ������ ����
=> ��������� O(n*log2(n))�� �ð����⵵

=> ������ �̹� ���ĵ� ����Ʈ�� ���ؼ� ��� ȣ���� ���̰� n
                                   �� ȣ�⿡���� �̵� Ƚ���� n
								   => O(n^2)�� �ȴ�.(�־��� ���)

=> �׷�����, ������� ��� �ð����⵵��  O(n*log2(n))�̰�
   ���� ����� ���� ������ ���� ���� ������ �򰡵�
   �߰� �޸� ���� ��� ����
   => ��ȣ�Ǵ� �˰���

=> �־��� ��� n^2�� �����ϱ� ���� �ǹ��� �ܼ��� ����Ʈ ���� �����͸� ����ϴ� ��� �� �յ��ϰ�
   ���� �� �� �ֵ��� �����͸� �����ϱ⵵ ��.
   ex> ����Ʈ ���� �� ���� ���� ������ �� ũ������� �߰� ���� �ǹ����� �����ϴ� ���
*/