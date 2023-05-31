#include "queueADT.cpp"

#ifndef NULL
#define NULL 0
#endif


template <typename E> class Link {
public:
    E element;
    Link *next;

    Link(const E& elemVal, Link *nextval = NULL) {
        element = elemVal;
        next = nextval;
    }

    Link(Link *nextVal = NULL) {
        next = nextVal;
    }
};

template<typename E> class LQueue: public Queue<E> {

private:
    Link<E> *front; //front
    Link<E> *rear; //rear
    int size;
    const static int defaultSize = 10;

public:
    LQueue(int s = defaultSize) {
        front = rear = new Link<E>;
        size = 0;
    }

    ~LQueue() {
        clear();
        delete front;
    }

    void clear() {

        while(front->next != NULL) {
            rear = front->next;
            front->next = rear->next;

            delete rear;
        }

        rear = front;

        size = 0;
    }

    void enqueue(const E& it) {
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }

    E dequeue() {
        if(length() == 0) throw "Queue is empty!";

        E it = front->next->element;
        Link<E> *ltemp = front->next;
        front->next = ltemp->next;

        if(rear == ltemp) rear = front;
        delete ltemp;

        size--;
        return it;
    }


    E leaveQueue() {
        if(length() == 0) throw "Queue is empty!";
        E it = rear->element;

        Link<E> *tempFrontNext = front->next;
        Link<E> *tempRear = rear;

        while(front->next != tempRear) {
            rear = front->next;
            front->next = rear->next;
        }

        delete tempRear;
        front->next = tempFrontNext;
        size--;
        return it;
    }


    const E& frontValue() const {
        if(length() == 0) throw "Queue is empty!";
        return front->next->element;
    }

    const E& rearValue() const {
        if(length() == 0) throw "Queue is empty!";
        return rear->element;
    }

    virtual int length() const {
        return size;
    }


};
