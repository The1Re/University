package lab1;
import java.util.Scanner;
public class Program{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String number;
    int sum=0;
    System.out.print("Enter input the number : ");
    number = sc.nextLine();
    System.out.print(number + " = ");
    for (int i=0; i<number.length(); i++)
    {
      char cha = number.charAt(i);
      System.out.print(cha);
      if (i != number.length()-1)
        System.out.print(" + ");
      sum += cha - '0';
    }
    System.out.print(" = "+sum);
    sc.close();
  }
}
