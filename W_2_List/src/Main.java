import java.util.Scanner;

public class Main {

    static ArrList<Integer> list;
//    static  LnList<Integer> list;


    static void printList() {

//        System.out.println(list.length());

        int pos = list.currPos();

        list.moveToStart();

        System.out.print("<");

        while (list.currPos() < list.length()) {
            if(list.currPos() == pos) System.out.print("|");

            System.out.print(list.getValue());
            if(list.currPos() != list.length()-1) {
                System.out.print(" ");
            }
            list.next();
        }

        System.out.println(">");

        list.moveToPos(pos);

    }


    public static void main(String[] args) {

        int K, X;
        Scanner scanner = new Scanner(System.in);

        K = scanner.nextInt();
        X = scanner.nextInt();

        list = new ArrList<Integer>(K, X);
//      list = new LnList<Integer>(K);

        for(int i = 0; i < K; i++) {
            int temp = scanner.nextInt();
            list.append(temp);
        }

        printList();

        int q = 1, p;

        while (true) {
            q = scanner.nextInt();
            p = scanner.nextInt();

            if(q == 0) break;

            switch (q) {
                case 1:
                    list.clear();
                    printList();
                    System.out.println(-1);
                    break;
                case 2:
                    list.insert(p);
                    printList();
                    System.out.println(-1);
                    break;
                case 3:
                    list.append(p);
                    printList();
                    System.out.println(-1);
                    break;
                case 4:
                     int removedOne = list.remove();
                    printList();
                    System.out.println(removedOne);
                    break;
                case 5:
                    list.moveToStart();
                    printList();
                    System.out.println(-1);
                    break;
                case 6:
                    list.moveToEnd();
                    printList();
                    System.out.println(-1);
                    break;
                case 7:
                    list.prev();
                    printList();
                    System.out.println(-1);
                    break;
                case 8:
                    list.next();
                    printList();
                    System.out.println(-1);
                    break;
                case 9:
                    int ln = list.length();
                    printList();
                    System.out.println(ln);
                    break;
                case 10:
                    int c = list.currPos();
                    printList();
                    System.out.println(c);
                    break;
                case 11:
                    list.moveToPos(p);
                    printList();
                    System.out.println(-1);
                    break;
                case 12:
                    int value = list.getValue();
                    printList();
                    System.out.println(value);
                    break;
                case 13:
                    int sResult = list.Search(p);
                    printList();
                    System.out.println(sResult);
                    break;
            }

        }

    }
}
