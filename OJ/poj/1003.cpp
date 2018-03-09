#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  float c;
  int i;
  int num;
  float sum;
  cin >> c;
  while(c!=0.0){
    sum = 0.0;
    for(i=2,num=0;sum<=c;++i,++num){
      sum += 1.0/i;
    }
    cout << num << ' ' << "card(s)" << endl;
    cin >> c;
  }
  return 0;
}
