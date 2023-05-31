#include "queueADT.cpp"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

template<typename E> class AQueue: public Queue<E> {
private:
    int maxSize;
    int front;
    int rear;
    E *listArray;

    const static int defaultSize = 10;

    void capacityIncrease() {


        E *tempArr = new E[2*maxSize - 1];

        int j = 0;

        while(true) {
            tempArr[++j] = listArray[front];

            if(front == rear) break;

            front = (front + 1) % maxSize;
        }

        delete []listArray;

        front = 1;
        rear = j;
        maxSize = 2*maxSize - 1;

        listArray = tempArr;

    }

public:
    AQueue(int size = defaultSize) {
        maxSize = size + 1;
        front = 1;
        rear = 0;
        listArray = new E[maxSize];
    }

    AQueue(E *arr, int size) {
        front = 1;
        rear = 0;
        listArray = arr;
        maxSize = size;

    }

    ~AQueue() {
        delete []listArray;
    }

    void clear() {
        rear = 0;
        front = 1;
    }

    void enqueue(const E& it) {
        if((rear + 2) % maxSize == front) capacityIncrease();

        rear = (rear + 1) % maxSize;
        listArray[rear] = it;
    }

    E dequeue() {

        if(length() == 0) throw "Queue is empty!";

        E it = listArray[front];
        front = (front+1) % maxSize;

        return it;
    }

    E leaveQueue() {

        if(length() == 0) throw "Queue is empty!";

        E it = listArray[rear];
        rear = (rear + maxSize - 1) % maxSize;

        return it;
    }

    const E& frontValue() const {
        if(length() == 0) throw "Queue is empty!";
        return listArray[front];
    }

    const E& rearValue() const {
        if(length() == 0) throw "Queue is empty!";

        return listArray[rear];
    }

    virtual int length() const {
        return ((rear + 1 - front) + maxSize) % maxSize;
    }

};
