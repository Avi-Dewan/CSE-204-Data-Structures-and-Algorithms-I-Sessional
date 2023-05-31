import javax.swing.*;
import java.util.Scanner;

class Stop {
    private int bus;
    private int train;

    Stop() {
        bus = 0;
        train = 0;
    }

    public void setBus(int bus) {
        this.bus = bus;
    }

    public int getBus() {
        return bus;
    }

    public void setTrain(int train) {
        this.train = train;
    }

    public int getTrain() {
        return train;
    }
}


public class TNL {

    private static LnList<Stop> stops;

    static void task(int t) {
        if(t == 1) {
            stops.moveToStart();
            while (stops.currPos() < stops.length()) {

                System.out.print(stops.currPos());

                if(stops.currPos() == stops.length() - 1) {
                    System.out.println();
                } else {
                    System.out.print(",");
                }

                stops.next();
            }

            stops.moveToStart();
            while (stops.currPos() < stops.length()) {
                if(stops.getValue().getBus() == 1) {
                    System.out.print(stops.currPos());
                }

                if(stops.currPos() == stops.length() - 1) {
                    System.out.println();
                } else {
                    System.out.print(",");
                }
                stops.next();
            }

            stops.moveToStart();
            while (stops.currPos() < stops.length()) {
                if(stops.getValue().getTrain() == 1) {
                    System.out.print(stops.currPos());
                }

                if(stops.currPos() == stops.length() - 1) {
                    System.out.println();
                } else {
                    System.out.print(",");
                }
                stops.next();
            }
        }
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int K, L, M, T;

        K = scanner.nextInt();

        stops = new LnList<Stop>(K);

        for(int i = 0; i < K; i++) {
            stops.append(new Stop());
        }

        L = scanner.nextInt();

        for(int i = 0; i < L; i++) {
            int lPos = scanner.nextInt();

            stops.moveToPos(lPos);
            stops.getValue().setBus(1);

        }

        M = scanner.nextInt();

        for(int i = 0; i < M; i++) {
            int mPos = scanner.nextInt();

            stops.moveToPos(mPos);
            stops.getValue().setTrain(1);
        }

        T = scanner.nextInt();
        task(T);

        /* Iterating
        stops.moveToStart();
        while (stops.currPos() < stops.length()) {
            Stop s = stops.getValue();
            System.out.println(stops.currPos() + " " + s.getBus() + " " + s.getTrain());
            stops.next();
        }*/

    }


}
