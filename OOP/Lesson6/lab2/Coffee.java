package lab2;
public class Coffee extends Product{
    public Coffee(int price){
        super("Coffee", price);
        Coffee.amount++;
    }
}