public class Milk extends Product{
    private int volumn;
    private static int amount = 0;
    private static double price = 0;

    public Milk(double price){
        super.name = "Milk";
        Milk.price += price;
        amount++;
    }

    public void setVolumn(int volumn){
        this.volumn = volumn;
    }
    @Override
    public String getDetail(){
        return volumn + " CC";
    }
    @Override
    public int getAmount(){
        return amount;
    }
    @Override
    public double getPrice(){
        return price;
    }
}
