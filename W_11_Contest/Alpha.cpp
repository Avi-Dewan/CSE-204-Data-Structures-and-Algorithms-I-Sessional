#include<iostream>
#include<cstring>
#include <vector>

using namespace std;


int main() {

    int n;

    cin >> n;

    int x[n+3], y[n+4];

    for(int i = 0 ; i < n; i++) {
        cin >> x[i];
        y[x[i]] = i;
    }



    int cnt = 0;

    for(int i = 2; i <= n; i++) {
        if(y[i] < y[i-1]) cnt++;
    }

    cout << cnt  + 1;


}
