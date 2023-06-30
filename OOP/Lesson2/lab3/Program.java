package lab3;
import java.util.Scanner;

public class Program {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int AMOUNT_DAY = 31;
        int startDay,day=1;
        System.out.print("Enter started day : ");
        startDay = sc.nextInt();

        //Output
        System.out.println("Su\tMo\tTu\tWe\tTh\tFr\tSa");
        while (day < startDay+AMOUNT_DAY)
        {
            if (day < startDay)
                System.out.print("\t");
            else
                System.out.print( (day-startDay+1) + "\t");
            if (day%7 == 0)
                System.out.println();
            day++;
        }
        sc.close();
    }
}
