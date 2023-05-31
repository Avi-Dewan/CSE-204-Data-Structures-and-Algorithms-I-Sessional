#include<iostream>
#include<limits>

using namespace std;

void Merge(int A[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

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
        }
    }

}

void mergeSort(int A[], int p, int r) {

    if(p < r) {
        int q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }

}





int main() {

    int A[5] = {1 , -6, 8, 0, 3};

    mergeSort(A, 0, 4);


    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }

    cout << endl;


    return 0;
}
