/*
 * The idea of formula is to return higher value of pos
 * when element to be searched is closer to arr[hi]. And
 * smaller value when closer to arr[lo]
 * pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]
 *
 * arr[] ==> Array where elements need to be searched
 * x     ==> Element to be searched
 * lo    ==> Starting index in arr[]
 * hi    ==> Ending index in arr[]
 *
 * */

int interpolationSearch(int array[], int len, int target){
	int low = 0;
	int high = len - 1;
	
	while(low <= high && target >= array[low] && target <= array[high]){
	
		int pos = low + ( (double) (target-low) * (high-low) / (array[high]-array[low]) );

		if(array[pos] == target)
			return pos;
		
		if(array[pos] < target)
			low = pos + 1;
		else
			high = pos - 1;
	
	}
	return -1;
}
// Time Complexity : If elements are uniformly distributed, then O (log n)). In worst case it can take upto O(n).
// Auxiliary Space : O(1)
