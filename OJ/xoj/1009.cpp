#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int u) {
    if (u <= 1)
        return false;
    if (u == 2 || u == 3)
        return true;
    if (u % 2 == 0)
        return false;
    int m = (int) sqrt(u);
    for (int i = 3; i <= m; i += 2)
        if (u % i == 0)
            return false;
    return true;
}

void superprime(int k, int v, int n){
  if(k == n){
    cout << v << endl;
    return ;
  }

  for(int i=1; i<=9; i++){
    int u = v*10 + i;
    if(is_prime(u))
      superprime(k+1,u,n);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  superprime(0,0,n);
  return 0;
}
