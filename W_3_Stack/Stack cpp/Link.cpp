template <typename E> class Link {

public:
    E element;
    Link *next;

    Link(const E& eleVal, Link *nextVal = 0) {
        element = eleVal;
        next = nextVal;
    }

    Link(Link *nextVal = 0) {
        next = nextVal;
    }
};
