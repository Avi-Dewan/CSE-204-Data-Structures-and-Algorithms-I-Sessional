#include<iostream>
#include<climits>

using namespace std;


int main() {

    int n;

    cin >> n;

    int dpArr[n+10];

    dpArr[0] = 0;

    for(int i = 1; i <= n; i++) dpArr[i] = INT_MAX;

    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i+ (j*j) <= n ) {
                if(dpArr[i + (j*j)] > dpArr[i] + 1) {
                   dpArr[i + (j*j)] = dpArr[i] + 1;
                }
            }
        }
    }

    cout << dpArr[n];

    return 0;

}
