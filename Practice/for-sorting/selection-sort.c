// Description: 
// The task is to complete select() function which is used to implement Selection Sort.
// Input: 
// First line of the input denotes number of test cases 'T'. First line of the test case is the size of array and second line consists of array elements.
// Output:
// Sorted array in increasing order is displayed to the user.

// 
// Example:
//
// Input:
// 2
// 5
// 4 1 3 9 7
// 10
// 10 9 8 7 6 5 4 3 2 1
//
// Output:
// 1 3 4 7 9
// 1 2 3 4 5 6 7 8 9 10
//
#include <stdio.h>
int select(int arr[], int i);
void selectionSort(int arr[], int n);


void selectionSort(int arr[], int n){
	int i, j, temp;
	for(i=n-1; i>=0; i--){
		j = select(arr, i);	
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}


}
int select(int arr[], int i){
	int max=i;
	while(i--){
		if(arr[i]>arr[max]){
			max = i;	
		}
	}
	return max;
}
int main(){
	int testcase;
	int size;
	int i;
	int arr[1001];
	scanf("%d\n", &testcase);
  while(testcase--){
		scanf("%d", &size);
		for(i=0; i<size; i++){
			scanf("%d", &arr[i]);	
		}
		selectionSort(arr, size);

		for(i=0; i<size; i++){
			printf("%d ", arr[i]);	
		}
	}	
		
}
