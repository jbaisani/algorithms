#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[]) {
  int p;
  int e;
  int i;
  int d;
  int n=1;

  //cin >> p >> e >> i >> d;
  scanf("%d %d %d %d", &p, &e, &i, &d);

  while(n){
    if(p==-1 && e==-1 && i==-1 && d==-1)
      break;

    for(int j = 0; j <= 21252; j++){
      if((j+d-p%23)%23==0 && (j+d-e%28)%28==0 && (j+d-i%33)%33==0 && j>0)
        //cout << "Case " << n <<": the next triple peak occurs in " << j <<" days."<< endl;
        printf("Case %d: the next triple peak occurs in %d days.\n", n, j);
    }
    n++;
    scanf("%d %d %d %d", &p, &e, &i, &d);
  }



  return 0;
}
