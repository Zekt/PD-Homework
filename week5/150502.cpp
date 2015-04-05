#include<iostream>
using namespace std;

int main() {
	int arrA[1001], arrB[1001];
	int sizeA = 0, sizeB = 0, tmp, i, j;
	do {
		cin >> arrA[sizeA];
	} while(arrA[sizeA++] != -1);
	//input and increase sizeA at the same time.
	--sizeA;
	//size of arrA is larger than it should be, so minus 1 to sizeA.
	if(arrA[0] > arrA[sizeA-1])
		for(i = 0; i < (sizeA+1)/2; ++i) {
			tmp = arrA[i];
			arrA[i] = arrA[sizeA-i-1];
			arrA[sizeA-i-1] = tmp;
		}
	//if the first element of arrA is greater than the last one,
	//it means the array is descending,
	//then swap two elements which are symmetrical to the middle one
	//to make it ascending.
	do {
		cin >> arrB[sizeB];
	} while(arrB[sizeB++] != -1);
	--sizeB;
	if(arrB[0] > arrB[sizeB-1])
		for(i = 0; i < (sizeB+1)/2; ++i) {
			tmp = arrB[i];
			arrB[i] = arrB[sizeB-i-1];
			arrB[sizeB-i-1] = tmp;
		}
	//Ditto
	i = j = 0;
	while(i < sizeA || j < sizeB) {
		if(arrA[i] < arrB[j] && i < sizeA || j == sizeB)
			cout << arrA[i++];
		else
			cout << arrB[j++];
		if(i < sizeA || j < sizeB)
			cout << " ";
	}
	//for every i and j in arrA and arrB, always output the smaller one.
	//if i or j is equal to sizeA or sizeB,
	//the output after it should only be in the other one array.
	cout << endl;
	return 0;
}
