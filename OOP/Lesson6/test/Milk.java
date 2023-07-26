public class Milk extends Product {
  private static int count = 0;
  public Milk(String name, int price) {
    super(name, price);
    count++;
  }
  public int getCount(){
    return count;
  }
}
