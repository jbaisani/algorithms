// link: http://practice.geeksforgeeks.org/problems/searching-a-number/0
// desciptions: Given an array of N elements and a integer K ,
//             return the position of first occurence of K in given array.  Position of first element is considered as 1.
//             Output -1 if the number is not found in an array.
// Input :
// 2
// 5 16
// 9 7 2 16 4
// 7 98
// 1 22 57 47 34 18 66
//
// Output :
// 4
// -1

#include <stdio.h>

int linear_search(int array[], int target, int len_array){
  int i;

  for (i = 0; i < len_array; i++) {
    if (array[i] == target)
      return i+1;
  }

  return -1;
}

int main() {
	//code
  int testcase;
  int len_array;
  int target;
  int array[1001];
  int pos;
  int i;
  scanf("%d", &testcase);
  while (testcase > 0) {
    scanf("%d %d\n", &len_array, &target);
    for (i = 0; i < len_array; i++) {
      scanf("%d", &array[i]);
    }
    pos = linear_search(array, target, len_array);
    printf("%d\n", pos);
    testcase -= 1;
  }

  return 0;
}
