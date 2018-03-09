#include <iostream>
using namespace std;

int n;
int A[20];


int solve(int i, int m){
  if (m == 0) {
    return 1;
  }
  if (i >= n) {
    return 0;
  }
  int res = solve(i+1, m) || solve(i+1, m - A[i]);

}

int main(int argc, char const *argv[]) {
  int m;
  int q;

  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> m;
    if (solve(0, m)) {
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
  return 0;
}
