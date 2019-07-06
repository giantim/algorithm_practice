/*
<삽입정렬>
1. 정렬된 리스트에 정렬 안된 원소 하나씩을 알맞은 위치에 삽입한다는 아이디어

2. 아이디어를 코드로 구현할 때에는 계속 비교해 가면서 적절한 위치를 찾아감(제자리 정렬)

=> 난 처음 구현할 때 비교할때마다 swap시켰는데 그것보다 더 효율적인 방법이 책에 있었음
*/
#include <iostream>
using namespace std;
int main()
{
	//별도 변수
	int temp, i, j, k;
	//배열입력
	int size;
	cin >> size;
	int* arr = new int[size];
	for (k = 0; k < size; k++)
		cin >> arr[k];

	/*알고리즘 구현
	1. 비교횟수 = 1+2+...+(size-1) = (size-1)*size/2
	2. 이동횟수 = 3+4+...+(size+1) = (size-1)*size/2 + 2*(size-1)
	=> O(n^2)
	*/
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
		arr[j + 1] = temp;

	}

	//비효율적 방식====>버블정렬 느낌(버블정렬 생략=>거의 쓰이지 않음)
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

	//확인
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}