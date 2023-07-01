package lab2;
public class Product{
    protected String productName;
    protected int price;
    protected int volumn;
    protected int weight;
    protected boolean isVolumn = false;
    protected static int amount = 0;
    public Product(String name, int price){
        this.productName = name;
        this.price = price;
    }
    public void setVolumn(int volumn){
        this.volumn = volumn;
        isVolumn = true;
    }
    public void setWeight(int weight){
        this.weight = weight;
    }
}