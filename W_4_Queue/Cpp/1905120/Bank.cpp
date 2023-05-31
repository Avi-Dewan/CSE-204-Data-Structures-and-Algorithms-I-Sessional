#include <iostream>

#include "queueADT.cpp"
#include "LQueue.cpp"
#include "AQueue.cpp"

using namespace std;


class Customer {
private:
    int time;
    int duration;
    int fnTime;

public:

    Customer() {

    }

    Customer(int t, int d) {
        this->time = t;
        this->duration = d;
    }

    int getTime() {
        return time;
    }

    int getDuration() {
        return duration;
    }

    void setFnTime(int t) {
        fnTime = t;
    }

    int getFnTime() {
        return fnTime;
    }

};


int main() {

    int n,  t = 0, cnCustomer = 1, eTime, dTime;

    bool service1 = true, service2 = true;
    int t1 = 0, t2 = 0;


    cin >> n;

    cin >> eTime >> dTime;

    AQueue<Customer> *q1 = new AQueue<Customer>(n);
    AQueue<Customer> *q2 = new AQueue<Customer>(n);

//    LQueue<Customer> *q1 = new LQueue<Customer>(n);
//    LQueue<Customer> *q2 = new LQueue<Customer>(n);


    while(true) {

        if(t >= t1) service1 = true;
        if(t >= t2) service2 = true;

        if(t == eTime) {

            Customer cus(eTime, dTime);

            if(cnCustomer != n) {
                cin >> eTime >> dTime;
                cnCustomer++;
            }

            int l1 = q1->length(), l2 = q2->length();

            if(!service1) l1++;
            if(!service2) l2++;

            if(l2 < l1) {
                q2->enqueue(cus);
            } else {
                q1->enqueue(cus);
            }
        }

        if(service1 && q1->length() != 0) {
            Customer a = q1->dequeue();
            t1 = t + a.getDuration();
            a.setFnTime(t1);
            service1 = false;
        }

        if(service2 && q2->length() != 0) {
            Customer b = q2->dequeue();
            t2 = t + b.getDuration();
            b.setFnTime(t2);
            service2 = false;
        }


        int l1 = q1->length(), l2 = q2->length();

        if(!service1) l1++;
        if(!service2) l2++;





        if(l1 - l2  > 1) {
//            cout << "Time: " << t << " Switching from l1 to l2 " << endl;
            q2->enqueue(q1->dequeue());

        } else if(l2 - l1 > 1) {
//            cout << "Time: " << t <<  " Switching from l2 to l1 " << endl;
            q1->enqueue(q2->dequeue());
        }

        t++;


        if(q1->length() == 0 && q2->length() == 0 && cnCustomer == n) break;

    }

    cout << "Booth 1 finishes service at t=" << t1 << endl;
    cout << "Booth 2 finishes service at t=" << t2 << endl;



    return 0;
}
