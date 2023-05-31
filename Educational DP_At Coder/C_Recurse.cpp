#include <iostream>
#include <vector>

#define N 10001

using namespace std;

vector<vector<int>> hap(N, vector<int>(4, -1));

vector<int> maxC(10001, -1);

int maxHappiness(int n, int flag) {


    if(n == 1) {
        if(flag == 0)
            return max(hap[1][1] , max( hap[1][2], hap[1][3]));
        else if(flag == 1)
            return max( hap[1][2], hap[1][3]);
        else if(flag == 2)
            return max(hap[1][1] , hap[1][3]);
        else if(flag == 3)
            return max(hap[1][1] , hap[1][2]);
    }

    if(flag == 0) {

        return max(hap[n][1] + maxHappiness(n-1, 1), max(hap[n][2] + maxHappiness(n-1, 2), hap[n][3] + maxHappiness(n-1, 3)));

    } else if(flag == 1) {

        return max(hap[n][2] + maxHappiness(n-1, 2), hap[n][3] + maxHappiness(n-1, 3));

    } else if(flag == 2) {

        return max(hap[n][1] + maxHappiness(n-1, 1), hap[n][3] + maxHappiness(n-1, 3));

    } else if(flag == 3) {

        return max(hap[n][1] + maxHappiness(n-1, 1), hap[n][2] + maxHappiness(n-1, 2));

    }

    return 0;
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


