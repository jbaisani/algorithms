#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

typedef struct{
  string str;
  int num;
}DNA;

DNA dna[101];

bool cmp(DNA a, DNA b){
  return a.num < b.num;
}

int main(int argc, char const *argv[]) {
  int length;
  int num;


  cin >> length >> num;

  for(int i = 0; i < num; i++){
    cin >> dna[i].str;
    dna[i].num = 0;
  }

  for(int i = 0; i < num; i++){
    for(int right = 1; right < length; right++){
        for(int left = 0; left < right; left++){
          if(dna[i].str[right] < dna[i].str[left])
            dna[i].num++;
        }
    }
  }

  stable_sort(dna,dna+num,cmp);
  for(int i = 0; i < num; i++)
    cout << dna[i].str << endl;

  return 0;
}
