public class Cashier {
    private String name;
    private final String LINE = "=============================";
    public Cashier(String name){
        this.name = name;
    }

    public void printReceipt(InventoryCart ic){
        System.out.println("\t" + LINE + "\n");
        System.out.println("\t  Pumkin Shop (" + name + ")\n");
        
        double total = 0;
        for (Product pd : ic.getAllProduct())
        {
            System.out.printf("\t%d x %s   %s\t%d\n", pd.getAmount(), pd.getName(), pd.getDetail(), (int)pd.getPrice());
            total += pd.getPrice();
        }
        System.out.println("\n\t" + LINE);
        System.out.printf("\t    Total\t\t%d $\n", (int)total);
    }
}
