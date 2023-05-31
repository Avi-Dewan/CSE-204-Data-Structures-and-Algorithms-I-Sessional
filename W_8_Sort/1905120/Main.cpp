#include<iostream>
#include<climits>
#include<time.h>
#include<algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


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


void printArr(int A[], int n) {
    cout << "Array:\t" ;
    for(int i = 0; i < n; i++) cout << A[i] << " ";

    cout << endl;
}

int main() {

    int n[6]= {5, 10, 100, 1000, 10000, 1000000};

    srand(18349432);

    int totalIteration = 20;

    for(int i = 0; i < 6; i++) {

        int a1[n[i]], a2[n[i]], a3[n[i]], a4[n[i]], a5[n[i]];

        double time[7] = {0};


        for(int iter = 0; iter < totalIteration; iter++) { //20 times rotation

            //creating n[i] random numbers

            for(int x = 0; x < n[i]; x++) {
                a1[x] = a2[x] = a3[x] = a4[x] = a5[x] = rand();
            }




        //Merge Sort

            auto start = high_resolution_clock::now();

            mergeSort(a1, 0, n[i]-1);

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);


            time[0] += duration.count();


        //Quick Sort

            start = high_resolution_clock::now();

            quickSort(a2, 0, n[i]-1);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[1] += duration.count();




        //Randomized Quick Sort

            start = high_resolution_clock::now();

            randQuickSort(a3, 0, n[i]-1);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[2] += duration.count();





        //Insertion Sort

            start = high_resolution_clock::now();
//            if(i != 5)
                insertionSort(a4, n[i]);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[3] += duration.count();



        //Quick Sort with Sorted Input (a2 is already sorted)

            start = high_resolution_clock::now();

//            if(i != 5)
                quickSort(a2, 0, n[i]-1);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[4] += duration.count();




        //Randomized Quick Sort with Sorted Input

            start = high_resolution_clock::now();

//            if(i != 5)
                randQuickSort(a3, 0, n[i]-1);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[5] += duration.count();



        //STL sort

            start = high_resolution_clock::now();

            sort(a5, a5 + n[i]);

            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);


            time[6] += duration.count();


            cout << iter << " " << n[i] << endl;

        }

        cout << "For " << n[i] << " random input average time(ms): ";

        for(int i = 0; i < 7; i++) {
            time[i] /= 20.0; //average time
            time[i] /= 1000; // micro second to mili-second
            cout << time[i] << " ";
        }

        cout << endl;


    }






    return 0;
}
