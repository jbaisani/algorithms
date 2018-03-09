#include <iostream>
using namespace std;

int bubble_sort(int A[], int N){
  int sw = 0;
  int temp = 0;
  for(int i=0; i<N; i++){
    for(int j = 0; j < N - i -1; j++){
      if(A[j] > A[j+1]){
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
        sw++;
      }
    }
  }

  return sw;
}

int main(int argc, char const *argv[]) {
  int A[100], N, sw = 0;
  cin >> N;
  for(int i=0; i < N; i++){
    cin >> A[i];
  }

  sw = bubble_sort(A, N);

  for(int i=0; i < N; i++){
    if (i) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
