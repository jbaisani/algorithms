#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int qcomp(const void *a,const void *b){
  int *pa = (int *)a;
  int *pb = (int *)b;
  return (*pa) - (*pb);
}

int duplicate[5000][2];
char phoneNum[2000];
int realNum[2000]={0};

int main(int argc, char const *argv[]) {
  int num;
  int index=0;
  int len=0;
  int dnum=0;
  int flag=0;
  cin >> num;
  while (num>0) {
    num--;
    cin >> phoneNum;
    len = strlen(phoneNum);
    //cout << len <<endl;
    for(int i=0; i<len; i++){//convert strings to integer
      switch (phoneNum[i]) {
        case 'A':
        case 'B':
        case 'C':
          realNum[index] += 2;
          realNum[index] *= 10;
          break;
        case 'D':
        case 'E':
        case 'F':
          realNum[index] += 3;
          realNum[index] *= 10;
          break;
        case 'G':
        case 'H':
        case 'I':
          realNum[index] += 4;
          realNum[index] *= 10;
          break;
        case 'J':
        case 'K':
        case 'L':
          realNum[index] += 5;
          realNum[index] *= 10;
          break;
        case 'M':
        case 'N':
        case 'O':
          realNum[index] += 6;
          realNum[index] *= 10;
          break;
        case 'P':
        case 'R':
        case 'S':
          realNum[index] += 7;
          realNum[index] *= 10;
          break;
        case 'T':
        case 'U':
        case 'V':
          realNum[index] += 8;
          realNum[index] *= 10;
          break;
        case 'W':
        case 'X':
        case 'Y':
          realNum[index] += 9;
          realNum[index] *= 10;
          break;
        case '-':
          break;
        default:
          realNum[index] += (int)(phoneNum[i]-'0');
          realNum[index] *= 10;
          break;
      }
    }
    realNum[index] /= 10;
    //cout << realNum[index] << endl;
    index++;
  }

  qsort(realNum,index,sizeof(int),qcomp);

  int temp = realNum[0];
  for(int i=0;i<index;i++){
    if (temp == realNum[i]) {
      duplicate[dnum][0]=temp;
      duplicate[dnum][1]++;
    }else{
      temp = realNum[i];
      dnum++;
      duplicate[dnum][1]++;
    }
  }
  for(int i=0;i<dnum;i++){
    if(duplicate[i][0]!=0){
      printf("%03d-%04d %d\n", duplicate[i][0]/10000, duplicate[i][0]%10000, duplicate[i][1]);
      flag++;
    }
  }
  if(flag==0){
    cout << "No duplicates." << endl;
  }

  // for(int i=0;i<index;i++){
  //   cout << realNum[i] << endl;
  // }



  return 0;
}
