public class LnList<E> implements List<E> {

    private Link<E> head;
    private Link<E> tail;
    private Link<E> curr; //protected ase boi e
    private int cnt;

    LnList(int size) {
        this();
    }

    public LnList() {
        curr = tail = head = new Link<E>(null); // Create header
        cnt = 0;
    }

    LnList(int size, E[] arr) {
        curr = tail = head = new Link<E>(null); // Create header
        cnt = 0;
        for(int i = 0; i < arr.length; i++) {
            this.append(arr[i]);
        }
    }

    @Override
    public void clear() {
        head.setNext(null);
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }

    @Override
    public void insert(E item) {
        Link<E> node = new Link<E>(item,curr.next());
        curr.setNext(node);

        if(tail == curr) tail = curr.next();
        cnt++;
    }

    @Override
    public void append(E item) {
        tail = tail.setNext(new Link<E>(item, null));
        cnt++;
    }

    @Override
    public E remove() {
        if (curr.next() == null) return null;

        E it = curr.next().element();

        if(tail == curr.next()) {
            tail = curr;
            tail.setNext(null);

            curr = head;
            while (curr.next() != tail) curr = curr.next();
        } else {
            curr.setNext(curr.next().next());
        }


        cnt--;

        return it;
    }

    @Override
    public void moveToStart() {
        curr = head;
    }

    @Override
    public void moveToEnd() {
        if(cnt != 0) {
            curr = head;
            while (curr.next() != tail) curr = curr.next();
        }
    }

    @Override
    public void prev() {
        if(curr != head) {
            Link<E> temp = head;
            while (temp.next() != curr) temp = temp.next();
            curr = temp;
        }
    }

    @Override
    public void next() {
        if (curr != tail) curr = curr.next();
    }

    @Override
    public int length() {
        return cnt;
    }

    @Override
    public int currPos() {
        int i;
        Link<E> temp = head;

        for(i = 0; curr != temp; i++) {
            temp = temp.next();
        }

        return i;
    }

    @Override
    public void moveToPos(int pos) {
        assert (pos>=0) && (pos < cnt) : "Position out of range";
        curr = head;
        for(int i=0; i<pos; i++) curr = curr.next();
    }

    @Override
    public E getValue() {
        if(curr.next() == null) return null;

        return curr.next().element();
    }

    @Override
    public int Search(E item) {

        Link<E> temp = head.next();

        int i = 0;

        while (temp.next() != null) {
//            System.out.println("i: " + i + " " + temp.element());
            if(temp.element() == item) {
//                System.out.println("Found in " + i);
                return i;
            }

            temp = temp.next();
            i++;

        }

        return -1;
    }

    @Override
    public void swap(int pos) {
        E currValue = this.getValue();
        int currPos = this.currPos();

        this.moveToPos(pos);
        E posValue = this.getValue();

        curr.next().setElement(currValue);

        this.moveToPos(currPos);
        curr.next().setElement(posValue);
    }

    @Override
    public E findMaxUptoCur() {
        Link<E> temp = head;

        E maX = head.element();

        while (temp != curr.next()) {
            if(temp.element() > maX) maX = temp.element();
        }

        return maX;
    }

    @Override
    public E findMinUptoCur() {
        Link<E> temp = head;

        E miN = head.element();

        while (temp != curr.next()) {
            if(temp.element() < miN) miN = temp.element();
        }

        return miN;
    }
}

/** Singly linked list node */
class Link<E>  {
    private E element; // Value for this node
    private Link<E> next; // Pointer to next node in list

    // Constructors
    Link(E it, Link<E> nextval) {
        element = it;
        next = nextval;
    }

    Link(Link<E> nextval) {
        next = nextval;
    }

    Link<E> next() {
        return next;
    }

    Link<E> setNext(Link<E> nextval) { // Set next field
        return next = nextval;   // Return element field
    }

    E element() {
        return element;
    }

    // Set element field
    E setElement(E it) {
        return element = it;
    }
}
