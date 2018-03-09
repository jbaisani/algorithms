#include <iostream>
static const int N = 1000;
using namespace std;

void trace(int A[], int n){
    for(int i=1; i<=n; i++){
        if(i>1)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[]){
    int n;
    int A[N+1];
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> A[i];
    trace(A,n);
    for(int j=2; j<=n; j++){
        int key = A[j];
        int i = j - 1;
        while (i>0 && A[i]>key) {
          A[i+1] = A[i];
          i--;
        }
        A[i+1] = key;
        trace(A,n);
    }
    return 0;
}
