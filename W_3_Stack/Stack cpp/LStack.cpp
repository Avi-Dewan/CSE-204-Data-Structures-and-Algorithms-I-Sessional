template <typename E> class LStack {

private:
    Link<E> *top;
    int size;
    static const int defaultSize = 10;


public:
    LStack(int sz = defaultSize) {
        top = NULL; //NULL
        size = 0;
    }

    ~LStack() {
        clear();
    }

    void clear() {
        while(top != NULL) {
            Link<E> *temp = top;
            top = top->next;
            delete temp;
        }

        size = 0;
     }





};
