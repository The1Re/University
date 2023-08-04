public abstract class Product {
    protected String name;

    public String getName(){
        return name;
    }
    public abstract double getPrice();
    public abstract int getAmount();
    public abstract String getDetail();
}
