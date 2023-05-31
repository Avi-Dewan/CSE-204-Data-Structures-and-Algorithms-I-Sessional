#include<iostream>
#include<cstring>
#include <vector>
#include<climits>


using namespace std;

long long int Merge(int A[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;
    long long int cnt = 0;

    int L[n1 + 1];
    int R[n2 + 1];

    for(int i = 1; i < n1 + 1; i++ ) {
        L[i-1] = A[p+i-1];
    }

    for(int i = 1; i < n2 + 1; i++ ) {
        R[i-1] = A[q+i];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 1, j = 1;

    for(int k = p; k <= r; k++) {
        if(L[i-1] <= R[j-1]) {
            A[k] = L[i-1];
            i++;
        } else {
            A[k] = R[j-1];
            j++;
            cnt += (n1 - i + 1));
        }
    }

    return cnt;

}

long long int countLuckyPairs(int A[], int p, int r) {

    long long int cnt = 0;

    if(p < r) {
        int q = (p+r)/2;
        cnt +=  countLuckyPairs(A, p, q);
        cnt +=  countLuckyPairs(A, q+1, r);
        cnt += Merge(A, p, q, r);
    }

    return cnt;
}






int main() {

    int t, n;
    string str;

    cin >> t;

    while(t--) {
        getline(cin, str);
        cin >> n;

        int arr[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << countLuckyPairs(arr, 0, n-1) << endl;

    }

    return 0;
}
