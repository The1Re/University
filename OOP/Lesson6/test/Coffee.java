public class Coffee extends Product {
    private static int count = 0;
    public Coffee(String name, int price) {
        super(name, price);
        count++;
    }
    public int getCount() {
        return count;
    }
}
