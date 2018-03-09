#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  char ch;
  bool flag = true;
  while (scanf("%c", &ch) != EOF) {
    if (isalpha(ch)) {
      if (flag) {
        flag = false;
      }else{
        ch = tolower(ch);
      }
    }

    printf("%c", ch);
    if (ch == '.' || ch == '!' || ch == '?') {
      flag = true;
    }
  }
  return 0;
}
