package lab2;

public class Cashier {
    private String name;
    private final String LINE = "\n---------------------------\n";
    public Cashier(String name){
        this.name = name;
    }
    public void printReceipt(InventoryCart ic){
        int sumPrice = 0;
        String info;

        System.out.println(LINE);
        System.out.println("Pumpkin shop (" + this.name + ")\n");

        for (Product pd : ic.getAllProduct()){
            if (pd.isVolumn){
                info = pd.volumn + " CC";
            }else{
                info = pd.weight + " Gram";
            }
            System.out.printf("%d x %s %s  %d\n", Product.amount, pd.productName, info, pd.price);
            sumPrice += pd.price;
        }

        System.out.println(LINE);
        System.out.println("   Total\t" + sumPrice + " $");
    }
}
