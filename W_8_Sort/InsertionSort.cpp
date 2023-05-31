#include<iostream>
#include<limits>

using namespace std;


void insertionSort(int A[], int n) {

    for(int i = 1; i < n; i++) {

        int insrtA = A[i];

        int j = i - 1;

        while(j >= 0 && A[j] > insrtA) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = insrtA;
    }


}


int main() {

    int A[5] = {1 , -6, 8, 0, 3};

    insertionSort(A, 5);


    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }

    cout << endl;


    return 0;
}

