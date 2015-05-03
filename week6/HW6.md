## Problem 1

1.
	5 6 
	2 5 6 
	2 4 5 6 
	2 4 5 6 7 
	2 2 4 5 6 7 
	2 2 4 5 5 6 7 
	2 2 3 4 5 5 6 7 
	2 2 3 4 5 5 6 6 7 
	0 2 2 3 4 5 5 6 6 7 

2.
This function recursively sort from the second element to the last element, then move every element less than the first one an index forward, and put the first element at the address of the last moved element. array+1 represent a subarray that starts from the address of the second element of array.

3.
In this function, in every recursion the funtion should find a position to put the first element. But it will do so only if it enconter an element that is not smaller than the first element. But if all elements from the second one to the last one are not smaller than the first one, it will be put nowhere.
