#include "heap.h"
#include<iostream>
#include<vector>

using namespace std;


int main() {

    int a;

    cin >> a;

    Heap h(a);

    vector<int> c;

    while(a--) {

        int b;
        cin >> b;
        h.insert(b);
        c.push_back(b);

        cout << "Size: " << h.size() << endl;
        cout << h.getMax() << endl;

    }

    cout << "Size: " << h.size() << endl;

//    h.printHeap();


    while(h.size() != 0) {
        cout << h.getMax() << " ";
        h.deleteKey();
    }

    cout << "\nsize:" << h.size() << endl;


    heapsort(c);

    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }


}

/*
10
2 5 145 44 3 7 8 10 97 6
*/
