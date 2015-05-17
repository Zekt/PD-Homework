#include<iostream>
using namespace std;

void insertionSort(int array[], const int n)
{
	if(n > 1)
	{
		insertionSort(array + 1, n - 1);
		int num1 = array[0];
		for(int i = 1; i < n; i++)
		{
			if(array[i] < num1)
				array[i - 1] = array[i];
			else
			{
				array[i] = num1;
				break;
			}
		}
	}
}

int main() {
	int a[10] = {0,6,3,5,2,7,4,2,5,6};
	insertionSort(a, 10);
}
