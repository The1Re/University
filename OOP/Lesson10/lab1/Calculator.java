import javax.swing.*;
import java.awt.event.ActionListener;
public class Calculator extends JFrame{
    private JButton button_1, button_2, button_3,
                    button_4, button_5, button_6,
                    button_7, button_8, button_9;
    private JButton button_C, button_CE, button_slash, button_multiply,
                    button_plus, button_minus, button_equal;
    public Calculator(String title){
        button_1 = new JButton("1");
        button_2 = new JButton("2");
        button_3 = new JButton("3");
        button_4 = new JButton("4");
        button_5 = new JButton("5");
        button_6 = new JButton("6");
        button_7 = new JButton("7");
        button_8 = new JButton("8");
        button_9 = new JButton("9");
        button_C = new JButton("C");
        button_CE = new JButton("CE");
        button_slash = new JButton("/");
        button_multiply = new JButton("*");
        button_plus = new JButton("+");
        button_minus = new JButton("-");
        button_equal = new JButton("=");
        setSize(400, 400);
        setTitle(title);
    }
}