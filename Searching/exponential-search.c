/*
 * Exponential search involves two steps:
 *
 * Find range where element is present
 * Do Binary Search in above found range.
 * */
#include <math.h>

int binarySearch(int array[], int left, int right, int target){

	while(left <= right){
		int mid = (left + right) / 2;

		if(array[mid] == target)
			return mid;
		if(array[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}

	return -1;

}

int exponentialSearch(int array[], int len, int target){
	if(array[0] == target){
		return 0;
	}

	int i = 1;
	while(i < len && array[i] <= target){
		i *= 2;
	}
  int bound = min(i, len); 
	return binarySearch(array, i/2, bound, target);

}

// Time Complexity : O(Log n)
// Auxiliary Space : The above implementation of Binary Search is recursive and requires O()Log n) space. With iterative Binary Search, we need only O(1) space.
