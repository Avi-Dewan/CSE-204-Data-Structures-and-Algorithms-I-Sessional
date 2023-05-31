public class AStack<E> implements Stack<E> {

    private static final int defaultSize  = 10;

    private int maxSize;
    private int top;
    private int direction = 1;
    private E[] listArray;


    AStack() {
        this(defaultSize);
    }

    AStack(int size) {
        maxSize = size;
        listArray = (E[]) new Object[size];
    }

    AStack(E[] allocArr, int direction ) {

        maxSize = allocArr.length;
        listArray = allocArr;

        this.direction = direction;

        if(direction == 1) top = 0;
        else  top = maxSize - 1;

    }

    private void capacityIncrease() {
        E[] tempArray = (E[])new Object[2*maxSize];

        if(direction == 1) {
            for(int i = 0; i < maxSize; i++) {
                tempArray[i] = listArray[i];
            }
        } else  {
            int tempTop = 2*maxSize - 1;
            for(int i = maxSize - 1, j = 0; i >= 0; i--, j++) {
                tempTop = 2*maxSize - 1 - j;
//                System.out.println(maxSize);
//                System.out.println(i + " " + tempTop);
                tempArray[tempTop] = listArray[i];
            }
            top =  tempTop - 1;
        }

        maxSize = 2*maxSize;
        listArray = tempArray;
    }

    @Override
    public void clear() {
        if(direction == 1) {
            top = 0;
        }
        else  {
            top = maxSize - 1;
        }
    }

    @Override
    public void push(E it) {
        if(direction == 1) {
            if(top > maxSize - 1) capacityIncrease();
            listArray[top++] = it;
        } else  {
            if(top < 0) capacityIncrease();
            listArray[top--] = it;
        }

    }

    @Override
    public E pop() {
        if(direction == 1) {
            assert top != 0 : "Stack is empty";
            return listArray[--top];
        } else {
            assert top != maxSize - 1 : "Stack is empty";
            return listArray[++top];
        }

    }

    @Override
    public E topValue() {
        if(direction == 1) {
            assert top != 0 : "Stack is empty";
            return listArray[top - 1];
        } else  {
            assert top != maxSize - 1 : "Stack is empty";
            return listArray[top + 1];
        }

    }

    @Override
    public int length() {
        if(direction == 1) {
            return top;
        } else  {
            return  (maxSize - top -1 );
        }

    }

    public void setDirection(int d) {
        assert length() == 0 : "The stack isn't empty";

        direction = d;

        if(direction == 1) top = 0;
        else  top = maxSize - 1;
    }

    /*public void print() {
        for (int i = 0; i < listArray.length; i++) {
            System.out.print(listArray[i] + " ");
        }
        System.out.println();
    }*/
}
