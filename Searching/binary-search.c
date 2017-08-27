// Search a sorted array by repeatedly dividing the search interval in half.
//   * Begin with an interval covering the whole array.
//   * If the value of the search key is less than the item in the middle of the interval,
//   * narrow the interval to the lower half.
//   * Otherwise narrow it to the upper half.
//   * Repeatedly check until the value is found or the interval is empty.


// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int array[], int left, int right, int target)
{
  while (left <= right)
  {
    int mid = (left + right) / 2;

    // Check if x is present at mid
    if (array[mid] == target)
        return mid;

    // If x greater, ignore left half
    if (array[mid] < target)
        left = mid + 1;

    // If x is smaller, ignore right half
    else
         right = mid - 1;
  }

  // if we reach here, then element was not present
  return -1;
}
