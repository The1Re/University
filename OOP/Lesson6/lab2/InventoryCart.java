package lab2;

public class InventoryCart {
    private Product[] product;
    private static int index = 0;
    public InventoryCart(int size){
        product = new Product[size];
    }
    public void addProduct(Product pd){
        this.product[index] = pd;
        index++;
    }
    public Product getProduct(){
        return this.product[--index];
    }
    public Product[] getAllProduct(){
        Product[] getAllPd = new Product[index];
        // for (int i=0; i < index; i++){
        //     if (this.product[i] == null)
        //         break;
        //     getAllPd[i] = this.product[i];
        // }
        while (index!=0){
            getAllPd[index-1] = getProduct();
        }
        return getAllPd;
    }
}
