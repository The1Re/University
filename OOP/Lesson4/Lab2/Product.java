public class Product{
    private int code;
    private String name;
    private double price;

    public Product()
    {
        this.code = 0;
        this.name = null;
        this.price = 0;
    }

    public Product(int code ,String name, double price)
    {
        this.code = code;
        this.name = name;
        this.price = price;
    }

    public void setCode(int c) { this.code = c; }
    public void setName(String n) { this.name = n; }
    public void setPrice(double p) { this.price = p; }

    public int getCode() { return this.code; }
    public String getName() { return this.name; }
    public double getPrice() { return this.price; }

}