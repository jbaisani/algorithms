#include <stdio.h>

bool binarySearch(int A[], int n, int key){
  int left = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (left + right) / 2;
    if (key == A[mid]) {
      return true;
    }else if (key < A[mid]) {
      right = mid;
    }else if (key > A[mid]) {
      left = mid + 1;
    }
  }
  return false;
}



int main(int argc, char const *argv[]) {
  int n;
  int A[1000000];
  int q;
  int key;
  int sum = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%d", &key);

    if (binarySearch(A, n, key)) {
      sum++;
    }
  }

  printf("%d\n", sum);
  return 0;
}
