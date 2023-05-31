public class ArrList<E> implements List<E> {

    private static final int defaultSize = 10;
    private static final int defaultChunk = 5;
    private int maxSize;
    private int listSize;
    private int curr;
    private int chunk;
    private E[] listArr;

    ArrList() {
        this(defaultSize, defaultChunk);
    }

    ArrList(int size) {
        this(size, defaultChunk);
    }

    ArrList(int size, int x) {
        maxSize = size;
        listSize = 0;
        curr = 0;
        chunk = x;
        listArr = (E[])new Object[size];
    }

    ArrList(int size, int x, E[] arr) {
        maxSize = size;
        listSize = 0;
        curr = 0;
        chunk = x;
        listArr = (E[])new Object[size];

        for(int i = 0; i < arr.length; i++) {
            this.append(arr[i]);
        }
    }

    private void addChunk() {
        maxSize += chunk;
        E[] tempArr = (E[])new Object[maxSize];

        for(int i = 0; i < listSize; i++) {
            tempArr[i] = listArr[i];
        }

        listArr = tempArr;

    }

    @Override
    public void clear() {
        listSize = 0;
        curr = 0;
    }

    @Override
    public void insert(E item) {
//        assert listSize < maxSize : "List capacity exceeded"; //explanation

        if(listSize + 1 > maxSize ) addChunk();

        for (int i = listSize; i > curr; i--) {
            listArr[i] = listArr[i-1];
        }

        listArr[curr] = item;
        listSize++;
    }

    @Override
    public void append(E item) {
//        assert listSize < maxSize : "List capacity exceeded";

        if(listSize + 1 > maxSize ) addChunk();

        listArr[listSize++] = item;
    }

    @Override
    public E remove() {
        if ((curr<0) || (curr >= listSize))
            return null;

        E item = listArr[curr];

        for(int i=curr; i<listSize-1; i++)
            listArr[i] = listArr[i+1];

        if(curr == listSize - 1) curr -= 1;
        listSize--;

        return item;
    }

    @Override
    public void moveToStart() {
        curr = 0;
    }

    @Override
    public void moveToEnd() {
        curr = listSize - 1;
    }

    @Override
    public void prev() {
        if (curr != 0)
            curr--;
    }

    @Override
    public void next() {
        if(curr < listSize)
            curr++;
    }

    @Override
    public int length() {
        return listSize;
    }

    @Override
    public int currPos() {
        return curr;
    }

    @Override
    public void moveToPos(int pos) {
        assert (pos>=0) && (pos<listSize) : "Pos out of range";
        curr = pos;
    }

    @Override
    public E getValue() {
        assert (curr>=0) && (curr<listSize) :
                "No current element";
        return listArr[curr];
    }

    @Override
    public int Search(E item) {

        for (int i = 0; i < listSize; i++) {
            if(listArr[i] == item) return i;
        }

        return  -1;
    }

    @Override
    public void swap(int pos) {
        E currValue = listArr[curr];
        E swapValue = listArr[pos];

        int tempCurr = curr;

        listArr[curr] = swapValue;
        listArr[pos] = currValue;
    }

    @Override
    public E findMaxUptoCur() {

        E maX = listArr[0];

        for(int i = 1; i <= curr; i++) {
            if(listArr[i] > maX) maX = listArr[i];
        }

        return maX;
    }

    @Override
    public E findMinUptoCur() {
        E miN = listArr[0];

        for(int i = 1; i <= curr; i++) {
            if(listArr[i] < miN) miN = listArr[i];
        }

        return miN;
    }
}
