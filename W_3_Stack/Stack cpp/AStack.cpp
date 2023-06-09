
template <typename E> class AStack: public Stack<E> {
private:
    int maxSize;
    int defaultSize = 20;
    int top;
    E *listArray;

public:
    AStack(int size = defaultSize) {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }

    ~AStack() {
        delete [] listArray;
    }

    void clear() {
        top = 0;
    }

    void push(const E& it) {
        Assert(top != maxSize, "Stack is full");
        listArray[top++] = it;
    }

    E pop() {
        Assert(top != 0, "Stack is empty");
        return listArray[top-1];
    }

    int length() const {
        return top;
    }

};

