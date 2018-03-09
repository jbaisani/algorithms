#include <iostream>
#include <cmath>

#define PI 3.1415926

using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  double x[100];
  double y[100];
  double year[100] = {0};

  cin >> num;
  for(int i=0;i<num;i++){
    cin >> x[i] >> y[i];
    year[i] = PI * ( pow(x[i],2) + pow(y[i],2) ) / (2*50);
    cout << "Property " << i+1 << ": This property will begin eroding in year " << (int)year[i]+1 << "." << endl;
  }
  cout << "END OF OUTPUT." << endl;
  return 0;
}
