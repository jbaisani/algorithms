#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  int input;
  int a[8];
  int* beg;
  int* end;

  cin >> input;
  for(int i=0; i<input ; i++){
    a[i] = i + 1;
  }

  beg = a;
  end = a + input;

  do {
    for(int i=0; i<input ; i++){
      cout << a[i];
      if(i!=input-1)
        cout << " ";
    }
    cout << endl;
  } while(next_permutation(beg,end));

  return 0;
}
