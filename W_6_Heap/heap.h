#include<vector>
#include<iostream>



using namespace std;

class Heap{

    int *heapArray;
    int maxSize;
    int mSize;

public:

    Heap(int s) {

        maxSize = s;
        mSize = 0;
        heapArray = new int[maxSize+1];

    }

    Heap(vector<int> v) {
        maxSize = v.size();
        mSize = 0;
        heapArray = new int[maxSize+1];

        for(int i = 0; i < maxSize; i++) {
            insert(v[i]);
        }

    }

    ~Heap() {
        delete []heapArray;
        maxSize = 0;
        mSize = 0;
    }

    int size() {
        return mSize;
    }

    void insert(int a) {
        heapArray[mSize + 1] = a;
        mSize++;

        int pos = mSize;

        while(pos > 1) {
            if(heapArray[pos] > heapArray[pos/2]) {
                int temp = heapArray[pos];
                heapArray[pos] = heapArray[pos/2];
                heapArray[pos/2] = temp;
                pos = pos/2;
            } else
                break;
        }

    }

    int getMax() {
        return heapArray[1];
    }

    void deleteKey() {
        heapArray[1] = heapArray[mSize];

        mSize--;

        int pos = 1;

        while(2*pos <= mSize) {
            int sPos = 2*pos;
            if(2*pos + 1 <= mSize) {
                if(heapArray[sPos+1] > heapArray[sPos]) sPos += 1;
            }

            if(heapArray[pos] >= heapArray[sPos]) break;
            else {
                int temp = heapArray[pos];
                heapArray[pos] = heapArray[sPos];
                heapArray[sPos] = temp;
                pos = sPos;
            }
        }

    }

/* ----------

    void printHeap() {
        cout << "Printing Heap: ";
        for(int i = 1; i <= mSize; i++) {
            cout << heapArray[i] << " -- ";
        }

        cout << endl;
    }


    void max_heapify(int i) {
        int l = 2*i;
        int r = 2*i + 1;

        int largest = i;

        if(l <= mSize && heapArray[l] > heapArray[i])
            largest = l;
        if(r <= mSize && heapArray[r] > heapArray[largest])
            largest = r;

        if(largest != i) {
            int temp = heapArray[i];
            heapArray[i] = heapArray[largest];
            heapArray[largest] = temp;

            max_heapify(largest);
        }
    }


    void sort() {
        int l = mSize;

        for(int i = l; i >= 2; i--) {
            cout << " first:  ";
            printHeap();
            int temp = heapArray[1];
            heapArray[1] = heapArray[i];
            heapArray[i] = temp;

            mSize--;

            max_heapify(1);

            printHeap();
        }

        mSize = l;
    }


    void build_heap() {

        int l = mSize/2;
        for(int i = l; i > 0; i--) {
            max_heapify(i);
        }
    }

*/

};


void heapsort(vector<int> &numbers) {

    Heap h(numbers);

//    h.sort();

    int i = 0;

    while(h.size() != 0) {
        numbers[i] = h.getMax();
        h.deleteKey();
        i++;
    }


}
