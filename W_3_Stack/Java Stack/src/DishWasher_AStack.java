import java.util.Scanner;

public class DishWasher_AStack {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n, x;

        n = scanner.nextInt();
        x = scanner.nextInt();


        int[] dishes = new int[x];
        boolean[] friends = new boolean[n];

        for(int i = 0 ; i < x; i++) {
            dishes[i] = scanner.nextInt();
        }

        for(int i = 0; i < n; i++) friends[i] = false;

        int k , t, s; // k- friend, t - when , s - which course

        boolean canTakeInput = false;
        int count = 0;

        AStack<DishWash> dirtyStack = new AStack<>();
        AStack<DishWash> cleanStack = new AStack<>();


        DishWash workingDish = null;
        int finishingTime = -1;


        k = scanner.nextInt();
        t = scanner.nextInt();
        s = scanner.nextInt();

        while (dirtyStack.length() != 0 || count <= t ) {


            if(t == count) canTakeInput = !canTakeInput;

            if(canTakeInput) {
                DishWash dishWash = new DishWash(k, t, s);
//                System.out.println(k + " " + t +" " + s);

                if(s == x) {
                    friends[k-1] = true;
                }

                dirtyStack.push(dishWash);

                canTakeInput = false;
                k = scanner.nextInt();
                t = scanner.nextInt();
                s = scanner.nextInt();
            }

            if( dirtyStack.length() != 0 && (count >= finishingTime)) {
                workingDish = dirtyStack.pop();

                int dishNo = workingDish.getDishNo();
                int dur = dishes[dishNo-1];

                if(workingDish.getTime() > finishingTime) {
                    finishingTime  =  (workingDish.getTime() + dur - 1);
                } else {
                    finishingTime = (finishingTime + dur);
                }

                workingDish.setTime(finishingTime);
                workingDish.setClean(true);
                cleanStack.push(workingDish);

//                System.out.println("fr" + workingDish.getFriend() + "  " +dishNo + " dur " + dur  );

//                System.out.println("fTime = "  + finishingTime );
            }

            count++;

            //if(k == 0) break; not comment

        }

        System.out.println(finishingTime);


        AStack<DishWash> tempStack = new AStack<>();

        int ln = 0, c = 0;

        while (cleanStack.length() != 0) {
            tempStack.push(cleanStack.pop());
            ln++;
        }


        while (tempStack.length() != 0) {
            DishWash temp = tempStack.pop();

            c++;
            if(c < ln)
                System.out.print(temp.getTime() + ",");
            else
                System.out.println(temp.getTime());

            cleanStack.push(temp);
        }

        ln = 0;

        for(int i = 0; i < n; i++) {
            if(friends[i])
                ln++;
        }

        if(ln == n)
            System.out.println("Y");
        else
            System.out.println("N");

        c = 0;

        for(int i = 0; i < n; i++) {
            if(friends[i]) {
                c++;
                if(c < ln)
                   System.out.print(i + 1 + ",");
                else
                    System.out.println(i + 1);
            }
        }

    }
}
