public class InventoryCart {
    private Product[] products;
    private static int index = 0;

    public InventoryCart(int capacity){
        products = new Product[capacity];
    }

    public void addProduct(Product product){
        for (int i=0; i<index; i++)
        {
            if (product.name == products[i].name)
                return;
        }
        products[index++] = product;
    }
    public Product getProductAt(int i){
        return products[i];
    }
    public Product[] getAllProduct(){
        Product[] temp = new Product[index];
        for (int i=0; i<index; i++)
        {
            temp[i] = products[i];
        }
        return temp;
    }
}
