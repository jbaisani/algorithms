// The idea it to first find the smallest Fibonacci number that is greater than or equal to length of given array. Let the found fibonacci number be fib (m’th fibonacci number). We use (m-2)’th Fibonacci number as index (If it is a valid index). Let (m-2)’th Fibonacci Number be i, we compare arr[i] with x, if x is same, we return i. Else if x is greater, we recur for subarray after i, else we recur for subarray before i.

int min(int a, int b){return a<=b?a:b;}

int fibonacciSearch(int array[], int target, int len){
  int fibMMm2 = 0; // (m-2)'th Fibonacci
	int fibMMm1 = 1; // (m-1)'th Fibonacci
	int fibM = fibMMm1 + fibMMm2; // m'th

	while(fibM < len){
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	int offset = -1;
	while(fibM > 1){
	
		int i = min(offset+fibMMm2, len-1);

		if(array[i] < target){
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}else if(array[i] > target){
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}else 
			return i;
	}
	if(fibMMm1 && array[offset+1] == target) 
		return offset+1;

	return -1;
}  


