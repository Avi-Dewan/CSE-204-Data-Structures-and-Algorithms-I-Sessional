#include<iostream>
#include<limits>
#include<time.h>

using namespace std;


int Partition(int A[], int p, int r) {

    int pivot = A[r];
    int i = p - 1;

    for(int j = p; j < r; j++) {
        if(A[j] <= pivot) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i + 1;

}

void quickSort(int A[], int p, int r) {
    if(p < r) {
        int q = Partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void randQuickSort(int A[], int p, int r) {
    if(p < r) {
        srand(time(0));
        int ran = p + rand()%(r-p + 1); //a random number between p and r. Then, making it pivot

        //swapping r and ran

        int temp = A[ran];
        A[ran] = A[r];
        A[r] = temp;

        //regular quick_sort
        int q = Partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}



int main() {

    int A[5] = {1 , -6, 8, 0, 3};

    randQuickSort(A, 0, 4);


    for(int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }

    cout << endl;


    return 0;
}

