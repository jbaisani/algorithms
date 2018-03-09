#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int resNum = 0;
int a[14];
bool b[14];
int s[14];

int check(int k){
  for(int i=1; i<k; i++){
    if (abs(i - k) == abs(a[i] - a[k])) {
      return false;
    }
  }
  return true;
}


void nQueen(int k){
  if(k > n){
    resNum++;
    if(resNum == 1){
      for(int i=1; i<=n; i++){
        s[i] = a[i];
      }
    }
    return ;
  }
  for(int i=1; i<=n; i++){
    if(b[i])
      continue;

    b[i] = true;
    a[k] = i;

    if (check(k)) {
      nQueen(k+1);
    }
    b[i] = false;
  }


}




int main(int argc, char const *argv[]) {
  cin >> n;
  nQueen(1);
  cout << resNum << endl;
  if (resNum!=0) {
    for(int i=1; i<=n;i++){
      cout << i << " " <<  s[i] << endl;
    }
  }

  return 0;
}
