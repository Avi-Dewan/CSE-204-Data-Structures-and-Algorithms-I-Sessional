#include<iostream>

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


int main() {

    int n, k; //n = number of Plants, k = number of friends

    cin >> n >> k;

    int price[n];

    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    quickSort(price, 0, n-1);

    int minCost = 0, mult = 1, nFriendsBought = 0;

    for(int i = n - 1; i >= 0; i--) {

        minCost += (mult*price[i]);

        nFriendsBought++;

        if(nFriendsBought == k)  {
            mult++;
            nFriendsBought = 0;
        }


    }

    cout << minCost << endl;

    return 0;
}


/*

3 3
2 5 6

3 2
2 5 6

12 4
1 2 3 5 6 3 1 32 2 1 2 4

4 10
2 4 17 822

20 7
4 5 7 1 4 12 24 2 1 67 12 3 56 78 9 12 15 1 7 0
*/
