public class Main {
    public static void main(String[] args) {
        Milk p1 = new Milk(150);
        p1.setVolumn(250);
        Sugar p2 = new Sugar(50);
        p2.setWeight(250);
        Coffee p3 = new Coffee(250);
        p3.setWeight(50);
        Coffee p4 = new Coffee(250);
        p4.setWeight(50);

        InventoryCart ic = new InventoryCart(10);
        ic.addProduct(p1);
        ic.addProduct(p2);
        ic.addProduct(p3);
        ic.addProduct(p4);

        Cashier c = new Cashier("John Doe");
        c.printReceipt(ic);
    }
}
