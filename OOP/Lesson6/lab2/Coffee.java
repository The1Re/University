public class Coffee extends Product{
    private int weight;
    private static int amount = 0;
    private static double price = 0;

    public Coffee(double price){
        super.name = "Coffee";
        Coffee.price += price;
        amount++;
    }

    public void setWeight(int weight){
        this.weight = weight;
    }

    @Override
    public String getDetail(){
        return weight + " Gram";
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
