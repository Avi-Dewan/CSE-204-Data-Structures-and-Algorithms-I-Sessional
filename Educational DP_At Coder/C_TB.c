#include <iostream>
#include <vector>

#define N 10001

using namespace std;

vector<vector<int>> hap(N, vector<int>(4, -1));

vector<vector<int>> maxC(N, vector<int>(4, -1));

int maxHappiness(int n, int flag) {


    if(maxC[n][flag] != -1) return maxC[n][flag];

    if(n == 1) {
        if(flag == 0)
            max[n][flag] = max(hap[1][1] , max( hap[1][2], hap[1][3]));
        else if(flag == 1)
            max[n][flag] = max( hap[1][2], hap[1][3]);
        else if(flag == 2)
            max[n][flag] = max(hap[1][1] , hap[1][3]);
        else if(flag == 3)
            max[n][flag] =max(hap[1][1] , hap[1][2]);
    }

    if(flag == 0) {
        maxC[n][flag] = max(hap[n][1] + maxHappiness(n-1, 1), max(hap[n][2] + maxHappiness(n-1, 2), hap[n][3] + maxHappiness(n-1, 3)));
    } else {
        for(int i = 1; i <= 3; i++) {
            if(i == flag) continue;

            maxC[n][flag] = max(hap[n][i] + maxHappiness(n-1, i), maxC[n][flag] )
        }
    }

    return maxC[n][flag];
}


int main() {
    int n;

    cin >> n;


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> hap[i][j];
        }
    }

    cout << maxHappiness(n, 0);


    return 0;
}
