import java.util.Scanner;

class Student {
    int roll;
    int mark;

    Student(int r, int m) {
        roll = r;
        mark = m;
    }

    public int getMark() {
        return mark;
    }
}


public class Main {

    public static void main(String[] args) {


        ArrList<Student> studInfo = new ArrList<>();

        Scanner scanner = new Scanner(System.in);

        int m = 1, n = 2;

        while (m != 0 && n!= 0) {
            m = scanner.nextInt();
            n = scanner.nextInt();

            studInfo.append(new Student(m, n));
        }

        for(int i = 0; i < studInfo.length(); i++) {
            for(int j = i+ 1; j < studInfo.length(); j++) {
                if(studInfo.getValue() > ) {
                    studInfo.swap();
                }
            }
        }

    }
}