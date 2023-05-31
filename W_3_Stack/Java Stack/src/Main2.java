import java.util.Scanner;

public class Main2 {

    static void printStack(OATS<Integer> oats ) {

        int fL = oats.lengthA(), bL = oats.lengthB();

        OATS<Integer> temp = new OATS<>(fL + bL + 10);

        for(int i = 0; i < fL; i++) {
            temp.pushA(oats.popA());
        }

        for(int i = 0; i < bL; i++) {
            temp.pushB(oats.popB());
        }

        System.out.print("Front: < ");

        for(int i = 0; i < fL; i++) {
            System.out.print(temp.topValueA() + " ");
            oats.pushA(temp.popA());
        }
        System.out.print(">   ");

        System.out.print("  Back < ");

        for(int i = 0; i < bL; i++) {
            System.out.print(temp.topValueB() + " ");
            oats.pushB(temp.popB());
        }

        System.out.println(">");

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n, m = 1, p;
        n = scanner.nextInt();


        OATS<Integer> oats = new OATS<>(n);

        while (true) {
            m = scanner.nextInt();


            if(m == 0)
                break;
            else if(m == 7) {
                p = scanner.nextInt();
                oats.pushA(p);
                System.out.println(-1);
            } else if(m == 8) {
                System.out.println(oats.popA());
            } else if(m == 9) {
                System.out.println(oats.topValueA());
            } else  if(m == 10) {
                p = scanner.nextInt();
                oats.pushB(p);
                System.out.println(-1);
            } else if(m == 11) {
                System.out.println(oats.popB());
            } else  if(m == 12) {
                System.out.println(oats.topValueB());
            }

            printStack(oats);
         }

    }
}
