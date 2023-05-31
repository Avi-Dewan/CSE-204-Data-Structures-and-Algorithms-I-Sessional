#include <iostream>
#include <vector>

using namespace std;

vector<int> minC(100001, -1);

int minCost(int h[], int n) {

    minC[1] = 0;
    if(n > 1) minC[2] = abs(h[1] - h[0]);

    for(int i = 3; i <= n; i++) {
        minC[i] = min(abs(h[i-1] - h[i-2]) + minC[i-1], abs(h[i-1] - h[i-3]) + minC[i-2]);
    }

    return minC[n];

}


int main() {
    int n;

    cin >> n;

    int h[n];

    for(int i = 0; i < n; i++) cin >> h[i];

    cout << minCost(h, n);


    return 0;
}

