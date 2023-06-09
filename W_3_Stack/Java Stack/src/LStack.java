public class LStack<E> implements Stack<E>{
    private  Link<E> top;
    private int size;

    public LStack() {
        top = null;
        size = 0;
    }

    public LStack(int size) {
        this();
    }

    @Override
    public void clear() {
        top = null;
        size = 0;
    }

    @Override
    public void push(E it) {
        top = new Link<E> (it, top);
        size++;
    }

    @Override
    public E pop() {
        assert top != null: "Stack is empty";
        E it = top.element();
        top = top.next();
        size--;

        return it;
    }

    @Override
    public E topValue() {
        assert top != null: "Stack is empty";
        return top.element();
    }

    @Override
    public int length() {
        return size;
    }
}
