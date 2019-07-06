/*들어가기에 앞서, 모든 코드는 배열 입력 -> 알고리즘(정렬 수행) -> 정렬된 배열 출력 순으로 구성되있음*/
/*
/*<선택정렬>
1. idea: 오른쪽 리스트에서 가장 작은 숫자를 선택해 왼쪽 리스트로 이동하는 작업을 되풀이
=> 특징적으로 보이는 부분이 오른쪽 리스트중 하나 선택해서 왼쪽으로 보내니까 
   "(오른쪽 리스트 원소 수) + (왼쪽 리스트의 원소 수) = 정렬 데이터 양" 으로 일정
   => 제자리 정렬 가능

2. 제자리 정렬( : 입력 배열 이외에는 다른 추가 메모리를 요구하지 않는 정렬 방식) 사용

tip 
=> 일반적으로 (비교연산) == 3*(이동연산)
*/

#include <iostream>
using namespace std;
int main()
{
	//배열입력
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	/*알고리즘 구현
	1. 비교횟수 = (size-1) * (size-i-1)
	2. 이동횟수 = 3*(size-1)
	=> O(n^2)
	*/	
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		/*정렬 안된 리스트에서 가장 작은 값에 해당되는 index선택*/
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
			= > 일반적으로(비교연산) < 3 * (이동연산)
			따라서 조건문 넣는것이 더 효율적*/
			temp = arr[i];
			arr[i] = arr[temp_index];
			arr[temp_index] = temp;
		}
	}

	//확인
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

