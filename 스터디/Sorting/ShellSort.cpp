/*
: 삽입정렬에서 한 원소가 삽입될 적절한 위치와 거리가 멀면 매우 비 효율적

1. 삽입정렬이 어느 정도 정렬된 배열에 대해서는 빠르다는 것에 착안한 방법
=> 부분리스트로 나눠서 부분적으로 정렬해버림

=> 삽입정렬의 O(n^2)보다 빠름

=> 삽입정렬의 최대 문제점은 요소들이 삽입될 때, 이웃한 위치로만 이동한다는 것.

=> 쉘 정렬에서는 요소들이 멀리 떨어진 위치로도 이동가능

2. 알고리즘
(1) 주어진 배열을 연속적이지 않은 여러 부분리스트로 쪼갬

(2) 각 부분리스트를 삽입정렬

(3) 모든 부분리스트가 정렬되면 다시 전체 리스트를 더 적은 개수의 부분리스트로

(4) 부분리스트 개수가 1이 되면 정렬 끝
=> 참고로 부분리스트 개수가 1이면 그냥 삽입정렬을 하는것과 동일
   but 이미 어느정도 정렬이 된 상태이기 때문에 삽입정렬이 효과적으로 진행됨


3. 시간복잡도
 => 최악 O(n^2)
    평균 O(n^1.5)
*/
#include <iostream>
using namespace std;


//gap을 유지하면서(즉, 부분리스트로서) 삽입정렬 하는 함수
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

//gap = gap/2 로 줄여나가면서 gap == 1이 될때 까지 부분리스트에 대한 삽입정렬 수행
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
	//배열입력
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	shell_sort(arr, size);
	//확인
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}