package lab2;
public class Milk extends Product{
    public Milk(int price){
        super("Milk", price);
        Milk.amount++;
    }
}