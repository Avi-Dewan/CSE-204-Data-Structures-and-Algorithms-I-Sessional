#include <iostream>
#include "queueADT.cpp"
#include "LQueue.cpp"
#include "AQueue.cpp"


using namespace std;


void printQ(AQueue<int> *q) {

    int l = q->length();

    cout  << "< " ;

    for(int i = 0; i < l; i++) {
        int x = q->dequeue();
        cout << x << " ";
        q->enqueue(x);
    }

    cout << ">" << endl;

}


int main() {

    int n, m, p, r, t;

    cin >> n;

//    LQueue<int> *q = new LQueue<int>(n);

    AQueue<int> *q = new AQueue<int>(n);

//    int arr[n];
//    int sz = sizeof(arr)/sizeof(arr[0]);
//    AQueue<int> *q = new AQueue<int>(arr, sz);


    for(int i = 0; i < n; i++) {
        cin >> m;
        q->enqueue(m);
    }


    printQ(q);

    while(true) {

        cin >> p >> r;

        if(p == 0) {
             break;
        } else if(p == 1) {

            q->clear();
            printQ(q);
            cout << -1 << endl;

        } else if(p == 2) {

            q->enqueue(r);
            printQ(q);
            cout << -1 << endl;

        } else if(p == 3) {

            try {
                t = q->dequeue();
                printQ(q);
                cout << t << endl;
            } catch(const char* msg) {
                cout << msg << endl;
            }


        } else if(p == 4) {

            printQ(q);
            cout << q->length() << endl;

        } else if(p == 5) {

            try {
                printQ(q);
                cout << q->frontValue() << endl;
            } catch(const char* msg) {
                cout << msg << endl;
            }

        } else if(p == 6) {

            try {
                printQ(q);
                cout << q->rearValue() << endl;
            } catch(const char* msg) {
                cout << msg << endl;
            }


        } else if(p == 7) {

            try {
                t = q->leaveQueue();
                printQ(q);
                cout << t << endl;
            } catch(const char* msg) {
                cout << msg << endl;
            }

        }

    }

    return 0;
}
