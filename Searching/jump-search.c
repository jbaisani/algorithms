// Like Binary Search, Jump Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements.
// For example, suppose we have an array arr[] of size n and block (to be jumped) size m. Then we search at the indexes arr[0], arr[m], arr[2m]…..arr[km] and so on. Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the index km to find the element x.

#include <math.h>

int jumpSearch(int array[], int target, int len){
	int step = sqrt(len);
	int prev = 0;
	int current = step;

	while(array[current-1] < target){
		prev = step;
		step += sqrt(len);
		if (prev >= len) {
			return -1;
		}
		current = min(step, len);
	}

	while (array[prev] < target) {
		prev++;
		if (prev == min(step, n)) {
			return -1;
		}
	}

	if (array[prev] == target) {
		return prev;
	}

	return -1;
}

// Time Complexity : O(√n)
// Auxiliary Space : O(1)
