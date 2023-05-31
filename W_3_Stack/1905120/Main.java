import java.util.Scanner;

public class Main {

    static void printStack(AStack<Integer> integerAStack) {
        AStack<Integer> tempStack = new AStack<>();

        while (integerAStack.length() != 0) {
            tempStack.push(integerAStack.pop());
        }

        System.out.print("<");

        while (tempStack.length() != 0) {
            int a = tempStack.pop();
            System.out.print(" " + a);
            integerAStack.push(a);
        }

        System.out.println(" >");
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the stack size and push the integers one by one: ");

        int n, m;
        n = scanner.nextInt();

        AStack<Integer> aStack = new AStack<>(n);

        for(int i = 0; i < n; i++) {
            m = scanner.nextInt();
            aStack.push(m);
        }

        int q = 1, p;

        printStack(aStack);

        while (true) {
            q = scanner.nextInt();
            p = scanner.nextInt();

            if (q == 0) break;

            switch (q) {
                case 1:
                    aStack.clear();
                    printStack(aStack);
                    System.out.println(-1);
                    break;
                case 2:
                    aStack.push(p);
                    printStack(aStack);
                    System.out.println(-1);
                    break;
                case 3:
                    m = aStack.pop();
                    printStack(aStack);
                    System.out.println(m);
                    break;
                case 4:
                    printStack(aStack);
                    System.out.println(aStack.length());
                    break;
                case 5:
                    printStack(aStack);
                    System.out.println(aStack.topValue());
                    break;
                case 6:
                    aStack.setDirection(p);
                    printStack(aStack);
                    System.out.println(-1);
                    break;
            }


        }


    }
}
