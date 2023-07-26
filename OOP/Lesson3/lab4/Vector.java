package lab4;

public class Vector {
    public double x;
    public double y;
    public double z;

    public Vector() {
        this(0, 0, 0);
    }

    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void printVector() {
        System.out.printf("(%.0f,%.0f,%.0f)\n", x, y, z);
    }

    public static void main(String[] args) {
        Vector v1 = new Vector();
        Vector v2 = new Vector(3, 4, 5);
        System.out.print("Vector v1 : ");
        v1.printVector();
        System.out.print("Vector v2 : ");
        v2.printVector();
    }
}