#include <iostream>
#include <vector>

using namespace std;

vector<int> minC(100001, -1);


//memorization or top-bottom approach

int minCost(int h[], int n) {

    if(minC[n] != -1)
        return minC[n];

    if(n == 2) {
        minC[2] = abs(h[1] - h[0]);
        return minC[2];
    }
    if(n == 1) {
        minC[1] = 0;
        return 0;
    }

    minC[n] = min(( abs(h[n-1] - h[n-2]) + minCost(h, n-1) ), (abs(h[n-1] - h[n-3]) + minCost(h, n-2)) );

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
