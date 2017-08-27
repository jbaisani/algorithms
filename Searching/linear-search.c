// A simple approach is to do linear search, i.e
//   * Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
//   * If x matches with an element, return the index.
//   * If x doesn’t match with any of elements, return -1.


// Linearly search x in arr[].  If x is present then return its
// location,  otherwise return -1
int search(int arr[], int n, int x)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}

// time complexity: O(n)
