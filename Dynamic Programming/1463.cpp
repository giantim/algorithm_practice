#include <iostream>
using namespace std;

int arr[1000001];
int N;

int main()
{
	arr[1] = 0;
	int number = 0;
	int count;
	int divTwo, divThree, subOne, small;
	for (int i = 2; i <= 1000000; i++)
	{
		count = 0;
		number = i;
		while (number != 1)
		{
			if (arr[number] != 0)
			{
				arr[i] = arr[number] + count;
				break;
			}
			if (number % 2 == 0 && number % 3 == 0)
			{
				divTwo = arr[number / 2];
				divThree = arr[number / 3];
				subOne = arr[number - 1];
				small = divTwo > divThree ? (divThree > subOne ? subOne : divThree) : (divTwo > subOne ? subOne : divTwo);
				if (small == divTwo)
				{
					number /= 2;
					count++;
				}
				else if (small == divThree)
				{
					number /= 3;
					count++;
				}
				else if (small == subOne)
				{
					number -= 1;
					count++;
				}
			}
			else if (number % 2 == 0 && number % 3 != 0)
			{
				divTwo = arr[number / 2];
				subOne = arr[number - 1];
				small = divTwo > subOne ? subOne : divTwo;
				if (small == divTwo)
				{
					number /= 2;
					count++;
				}
				else if (small == subOne)
				{
					number -= 1;
					count++;
				}
			}
			else if (number % 2 != 0 && number % 3 == 0)
			{
				divThree = arr[number / 3];
				subOne = arr[number - 1];
				small = divThree > subOne ? subOne : divThree;
				if (small == divThree)
				{
					number /= 3;
					count++;
				}
				else if (small == subOne)
				{
					number -= 1;
					count++;
				}
			}
			else
			{
				number -= 1;
				count++;
			}
		}
		if (number == 1)
			arr[i] = count;
	}
	cin >> N;
	cout << arr[N];
	return 0;
}