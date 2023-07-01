package lab1;

public class Program {
    public static void main(String[] args){
        Product p1 = new Product("XA001","Milk",150);
        Product p2 = new Product("XA002","Sugar",50);
        Product p3 = new Product("XA003","Coffe",250);

        InventoryCart ic = new InventoryCart(10);
        ic.addProduct(p1);
        ic.addProduct(p2);
        ic.addProduct(p3);

        Cashier c = new Cashier("John Doe");
        c.printReceipt(ic);
    }
}
