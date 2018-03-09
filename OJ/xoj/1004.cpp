#include <iostream>
#include <algorithm>
using namespace std;
int num[1000000];
int main(int argc, char const *argv[]) {
  int len;
  cin >> len;
  for(int i = 0; i < len; i++){
    cin >> num[i];
  }
  sort(num,num+len);
  for(int i = 0; i < len; i++){
    cout << num[i];
    if(i!=len-1)
      cout << " ";
  }
  cout << endl;
  return 0;
}
