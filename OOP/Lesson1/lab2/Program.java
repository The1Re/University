import java.util.Scanner;
class Program{
  public static void main(String[] args)
  {
    double side,length,area;
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter triangle side : ");
    side = scanner.nextDouble();
    System.out.print("Enter prism length : ");
    length = scanner.nextDouble();
    area = 2*(Math.sqrt(3)/4*Math.pow(side,2)) + 3*(side*length);
    System.out.printf("Surface area of prism is\n%.2f",area);
    scanner.close();
  }
}
