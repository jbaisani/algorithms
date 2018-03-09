#include <iostream>
#include <algorithm>

using namespace std;

void swap(string &num1, string &num2){
  string temp;
  temp = num1;
  num1 = num2;
  num2 = temp;
}

void bigNumAdd(string num1, string num2){
  if (num1.size() < num2.size()) {
    swap(num1,num2);
  }
  //cout << "num1: " << num1 << endl;
  //cout << "num2: " << num2 << endl;
  int flag = 0;//进位标志
  int a; //num1上的一个位
  int b; //num2上的对应a的位
  int sum;  //新的一位的加法和
  int len1 = num1.size();
  int len2 = num2.size();

  while(len1>0){
    a = num1[len1-1] - '0';
    if(len2>0)
      b = num2[len2-1] - '0';
    else
      b = 0;
    sum = a + b + flag;

    if(sum >= 10){
      num1[len1-1] = '0' + sum%10;
      flag = 1;
    }else{
      num1[len1-1] = '0' + sum%10;
      flag = 0;
    }

    len1--;
    len2--;
  }
  if(flag == 1){
    num1 = "1" + num1;
  }
  cout << num1 << endl;

}


int main(int argc, char const *argv[]) {
  string num1;
  string num2;

  while (cin >> num1 >> num2) {
    bigNumAdd(num1,num2);
  }
  return 0;
}
