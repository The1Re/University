package lab1;

public class Cashier {
    private String name;
    public Cashier(String name){
        this.name = name;
    }
    public void printReceipt(InventoryCart ic){
        int sumPrice = 0;
        System.out.println("\tPumpkin shop (" + this.name + ")\n");
        for (Product pd : ic.getAllProduct()){
            System.out.printf("    1 x %s\t(%s)\t%d\n", pd.name, pd.id, pd.price);
            sumPrice += pd.price;
        }
        System.out.println("\t------------------");
        System.out.println("\t\t(Total)\t" + sumPrice + "$");
    }
}
