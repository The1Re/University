public abstract class Product {
  protected String name;
  protected int price;

  public Product(String name, int price) {
    this.name = name;
    this.price = price;
  }

  public abstract int getCount();
}
