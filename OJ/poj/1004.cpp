#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  double sum=0;
  for(int i=0;i<12;i++){
    double temp;
    cin >> temp;
    sum += temp;
  }
  cout << '$' << sum/12.0 << endl;
  return 0;
}
