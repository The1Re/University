import javax.swing.JFrame;

public class Program {
    public static void main(String[] args)
    {
        Calculator cl = new Calculator("CALCULATOR");
        cl.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        cl.setVisible(true);
    }
}
