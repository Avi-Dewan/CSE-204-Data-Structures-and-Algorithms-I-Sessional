public class OATS<E> {

    private E[] OATS_Arr;
    private static final int defaultSize  = 10;
    private int maxSize;

    private AStack FrontStack;
    private AStack BackStack;

    OATS() {
        this(defaultSize);
    }

    OATS(int size) {
        maxSize = size;
        OATS_Arr = (E[]) new Object[size];

        FrontStack = new AStack(OATS_Arr, 1);
        BackStack = new AStack(OATS_Arr, -1);
    }

    private void increase() {
        E[] temp_Arr = (E[])new Object[2*maxSize];


        for(int i = 0; i < FrontStack.length(); i++) {
            temp_Arr[i] = OATS_Arr[i];
        }

        for(int j = 2*maxSize-1, k = 0; k < BackStack.length(); k++, j--) {
            temp_Arr[j] = OATS_Arr[maxSize - 1 - k];
        }

        int fLength = FrontStack.length();
        int bLength = BackStack.length();

        maxSize = 2*maxSize;
        OATS_Arr = temp_Arr;

        FrontStack.clear();
        BackStack.clear();

        for(int i = 0 ; i < fLength; i++) {
            FrontStack.push(OATS_Arr[i]);
        }

        for(int j = 0; j < bLength; j++) {
            BackStack.push(OATS_Arr[maxSize-1-j]);
        }

    }

    void pushA(E it) {
        if(FrontStack.length() + BackStack.length() > maxSize) increase();

        FrontStack.push(it);
    }

    void pushB(E it) {
        if(FrontStack.length() + BackStack.length() > maxSize) increase();

        BackStack.push(it);
    }

    E topValueA() {
        return (E) FrontStack.topValue();
    }

    E topValueB() {
        return (E)BackStack.topValue();
    }

    E popA() {
        return (E) FrontStack.pop();
    }

    E popB() {
        return (E) BackStack.pop();
    }

    int lengthA() {
        return FrontStack.length();
    }

    int lengthB() {
        return BackStack.length();
    }



}
