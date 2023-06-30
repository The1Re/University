package lab4;
import java.util.Scanner;

public class Program {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter sentence : ");
        String msg = sc.nextLine();
        msg = msg.replace("happy", "happy :)");
        msg = msg.replace("sad", "sad :(");
        System.out.println(msg);
        sc.close();
    }
}
