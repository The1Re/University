import java.util.Scanner;

public class Program {
    private static final String LINE = "========";
    private static final int MAXSIZE = 5;
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int code = 0, amount;
        double price = 0;

        System.out.println(LINE+" Enter Products detail "+LINE);
        Product product[] = new Product[MAXSIZE];
        product[0] = new Product(0, "Mama", 5.5);
        product[1] = new Product(10,"Lays",10.5);
        
        //input
        for (int i=2; i<MAXSIZE;i++)
        {
            product[i] = new Product();
            product[i].setCode(i*10);
            System.out.println("Product code "+product[i].getCode());

            System.out.print("name : ");
            product[i].setName(scanner.nextLine());

            System.out.print("price : ");
            product[i].setPrice(scanner.nextDouble());
            scanner.nextLine();
        }

        //output list product
        System.out.println("\n\n"+LINE+" List of Products "+LINE);
        for (int i=0; i<MAXSIZE; i++)
        {
            System.out.println("Product code "+product[i].getCode());
            System.out.println("Name:"+product[i].getName()+" , Price:"+product[i].getPrice());
        }

        //loop buy
        System.out.println("\n\n"+LINE+" What do you want to buy? "+LINE);
        System.out.println("Enter product code (press -1 to exit)");
        while (true)
        {
            System.out.print("Product Code : ");
            code = scanner.nextInt();
            scanner.nextLine();

            if (code == -1) break;
            code /= 10;
            System.out.print("Amount of "+product[code].getName()+" : ");
            amount = scanner.nextInt();
            scanner.nextLine();

            price += amount*product[code].getPrice();
        }
        System.out.println("You have to pay "+price+" Baht");
        scanner.close();
    }
}
