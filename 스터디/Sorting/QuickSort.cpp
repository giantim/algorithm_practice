/*
<퀵 정렬>
1. 이것도 역시 분할 정복 방식
(1) 전체 리스트를 2개의 부분리스트로 분할과 동시에 어느정도 정렬(MergeSort와는 다음)
(=> 피벗을 기준으로 왼쪽은 피벗보다 작은것 오른쪽은 큰것이 오도록)
(2) 피벗을 기준으로 나눈 각각의 부분리스트들에 대해서 다시한번 (1)을 반복
(3) 부분리스트로 더는 쪼갤수 없을때 탈출하면 정렬 끝

+a => 참고로 여기서는 피벗을 부분리스트 가장 왼쪽것으로 정함

2. 합병정렬과의 차이
=> 다 1/2로 규칙적으로 쪼갠 후 합병에서 실질적 정렬이 이루어짐
   vs
   피벗을 기준으로 정렬이 허술하게 되면서 부분리스트가 쪼개지고 모든게 다 쪼개졌을 때 정렬이 끝남

3. QuickSort를 하기 위해선 quick_sort와 partition함수 필요

(1) quick_sort := partition 호출 후 partition이 반환한 피벗을 기준으로 부분리스트로 분할하여 quick_sort()를 재귀호출
				  (merge_sort 같은 경우는 다 나눈 후 merge를 호출! 차이인식)

(2) partition  := 각 부분리스트들을 다시한번 피벗을 기준으로 허술하게 정렬 후 피벗위치 반환
=> 이 과정은 책의 그림을 통해 설명
*/

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int partition(int list[], int left, int right)
{
	//left: 부분리스트 시작
	//right:부분리스트 끝
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
	} while (low < high);	//low와 high가 교차하기 전까지 반복

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
	//배열입력
	int size;
	cout << "MAX_SIZE보다 작게 입력하시오: ";
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	/*알고리즘 구현
	*/
	quick_sort(arr, 0, size - 1);

	//확인
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


/*
4. 복잡도 분석

(1) 재귀호출의 깊이는 합병정렬과 마찬가지로 log2(n)
(2) 각 호출 단계에서 비교 횟수: 평균 n번
                    이동 횟수=> 비교횟수보다 작음
=> 평균적으로 O(n*log2(n))의 시간복잡도

=> 하지만 이미 정렬된 리스트에 대해선 재귀 호출의 깊이가 n
                                   각 호출에서의 이동 횟수가 n
								   => O(n^2)이 된다.(최악의 경우)

=> 그럼에도, 평균적인 경우 시간복잡도가  O(n*log2(n))이고
   같은 빅오를 가진 정렬중 가장 빠른 것으로 평가됨
   추가 메모리 공간 사용 안함
   => 선호되는 알고리즘

=> 최악의 경우 n^2을 방지하기 위해 피벗을 단순히 리스트 왼쪽 데이터를 사용하는 대신 더 균등하게
   분할 할 수 있도록 데이터를 선택하기도 함.
   ex> 리스트 내의 몇 개의 임의 데이터 중 크기순으로 중간 값을 피벗으로 선택하는 방법
*/