#include <iostream>
#include <vector>
#include<climits>

using namespace std;

vector<int> minC(100001, -1);

int minCost(int h[], int n, int k) {

    minC[1] = 0;

//     minC[i] = min(abs(h[i-1] - h[i-2]) + minC[i-1], abs(h[i-1] - h[i-3]) + minC[i-2]);

    for(int i = 2; i <= n; i++) {
        int minT = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(i-1-j < 0) continue;
            if((abs(h[i-1] - h[i-1-j]) + minC[i-j]) < minT)
                minT = abs(h[i-1] - h[i-1-j]) + minC[i-j];
        }

        minC[i] = minT;
    }

    return minC[n];

}


int main() {
    int n, k;

    cin >> n >> k;

    int h[n];

    for(int i = 0; i < n; i++) cin >> h[i];

    cout << minCost(h, n, k);


    return 0;
}


