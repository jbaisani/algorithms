// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
//
// 1) The subarray which is already sorted.
// 2) Remaining subarray which is unsorted.
//
int select(int arr[], int i){
	int max=i;
	while(i--){
		if(arr[i]>arr[max]){
			max = i;	
		}
	}
	return max;
}

void selectionSort(int arr[], int n){
	int i, j, temp;
	for(i=n-1; i>=0; i--){
		j = select(arr, i);	
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

