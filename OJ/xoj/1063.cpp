#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

int data[4096][12];
int a[12][12];
int o[12];


const int MAX_NUMBER = 999999999;

int main(int argc, char* argv[]) {
    int n;
    int temp;
    int maxn;
    int result = MAX_NUMBER;

    cin >> n; //1<=n<=12

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        o[i] = 1 << i;

    maxn = 1 << n;

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < n; j++)
            data[i][j] = MAX_NUMBER;
    data[1][0] = 0;

    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < n; j++) {
            if (data[i][j] == MAX_NUMBER)
                continue;
            for (int k = 0; k < n; k++) {
                if (i & o[k])
                    continue;
                temp = i | o[k];
                data[temp][k] = min(data[temp][k], data[i][j] + a[j][k]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        result = min(result, data[maxn - 1][i] + a[i][0]);

    cout << result << endl;
    return 0;
}
