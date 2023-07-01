package lab2;
public class Sugar extends Product{
    public Sugar(int price){
        super("Sugar", price);
        Sugar.amount++; 
    }
}