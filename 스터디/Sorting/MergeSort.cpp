/*
<MergeSort>
1. divide(분할) & conquer(정복->정렬) 방법에 기반
=> 기본구조: 문제를 작은 2개의 문제로 분리 => 각각을 해결 => 다시 합침

(1) 입력 배열을 같은 크기의 2개의 부분 배열로 분할
(2) 부분 배열 정렬. 부분 배열의 크기가 충분히 작지 않으면 순환호출을 이용해 다시 분할 정복 적용
(3) 합병

=> (2)의 과정에서 부분 배열을 정렬할 때도 또다시 합병정렬을 이용 즉, 합병정렬을 순환적으로 적용

2. mergeSort를 하기 위해선 merge 부분과 merge_sort부분 2가지가 필요

(1) merge_sort	:= 적절히 분할 후 merge를 호출하는 부분
(2) merge		:= 합병하는 부분(실질적인 정렬이 이루어지는 부분)

=> 합병의 원리
-> 2개의 리스트의 요소들을 처음부터 하나씩 비교하여 더 작은 요소를 새로운 리스트로 옮기는 것을 반복
   둘 중 하나의 리스트가 끝나면 나머지를 모두 복사
   => 따라서 추가적인 메모리 공간 필요 

=> merge_sort에서 순환호출로 주어진 배열을 부분리스트 길이가 1이 될때까지 재귀호출로 쪼개고
   그상태에서 merge를 순차적으로 진행하면서 정렬된 배열을 만드는 구조
*/

#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
int sorted[MAX_SIZE];	//합병을 위해서는 추가공간이 필요

//i : 정렬된 왼쪽 리스트에 대한 인덱스
//j : 정렬된 오른쪽 리스트에 대한 인덱스
//k : 정렬될 리스트 대한 인덱스
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	/*분할 정렬된 list의 합병*/
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	/*남아 있는 레코드의 일괄 복사*/
	if (i > mid)//오른쪽이 남아있는 경우
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	/*배열 sorted[] 리스트를 배열 list로 재복사*/
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)	//부분리스트가 1보다 더 작게 쪼개질 경우 리턴하면서 이때부터 pop하면서 합병됨
	{
		mid = (left + right) / 2;			//리스트 균등분할
		merge_sort(list, left, mid);		//부분 리스트 정렬
		merge_sort(list, mid + 1, right);	//부분 리스트 정렬
		merge(list, left, mid, right);		//합병
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
	merge_sort(arr, 0, size - 1);

	//확인
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


/*
4. 복잡도 분석
(1) 순환 호출의 깊이 => 1/2로 쪼개나가기 때문에 log2(n) 깊이
    그리고 배열이 부분 배열로 나누어 지는 단계에서는 비교나 이동이 수행되지 않음
	merge에서 비교 연산과 이동 연산이 수행
	순환 호출의 깊이 만큼 merge가 호출

(2) 하나의 합병 단계에서 최대 n 번의 비교연산 필요	(옮길때 마다 비교한번씩 해야하므로)
                       최대 2n 번의 이동연산 필요(sort에 옮겼다가 다시 list로 옮겨야함)

=> 결과적으로 3n*log2(n) => O(nlog2(n))인 정렬 방식임

5. 기타 내용
-> 임시 배열이 필요함, 레코드의 크기가 큰 경우에 이동 횟수가 많아 시간적 낭비

-> 레코드 길이가 큰 경우 레코드를 연결 리스트로 구성하여 합병 정렬할 경우ㅡ 링크 인텍스만 변경되므로 데이터의
   이동은 무시할 수 있을 정도로 작아짐. 
   따라서 크기가 큰 레코드일 경우 연결리스트 사용하면 다른 어떤 정렬방법보다 효율적일 수 있음

   확실하게는 모르겠어서 같이 이야기해보고싶음
*/

