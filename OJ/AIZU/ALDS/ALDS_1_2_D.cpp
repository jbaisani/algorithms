#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int l;
int n;
int A[1000000];
long long cnt;
vector<int> G;

void insertion_sort(int A[], int N, int g){
  for(int i = g; i<N; i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shell_sort(int A[], int N){
  for(int h = 1; ; ){
    if(h > N)
      break;
    G.push_back(h);
    h = 3*h +1;
  }

  for(int i = G.size() - 1; i >= 0; i--){
    insertion_sort(A,N,G[i]);
  }
}

int main(int argc, char const *argv[]) {
  cin >> n;
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  cnt = 0;

  shell_sort(A,n);
  cout << G.size() << endl;
  for(int i = G.size()-1; i>=0; i--){
    printf("%d", G[i]);
    if (i) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%lld\n", cnt);
  for(int i = 0; i<n; i++)
    printf("%d\n", A[i]);
  return 0;
}
