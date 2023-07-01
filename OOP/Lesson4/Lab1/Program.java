package Lab1;
public class Program {
    public static void main(String args[])
    {
        BlankAccount p1 = new BlankAccount("player1");
        BlankAccount p2 = new BlankAccount("Player2", 500,new Date(1, 5, 2015));
        p1.deposit(1000);
        p2.transfer(p1, 1000);
        p2.transfer(p1,300);
        p2.withdraw(300);
        System.out.printf("P1 : %s : %.0f\nP2 : %s : %.0f", p1.getInfo(),p1.getAmount(), p2.getInfo(), p2.getAmount());
    }
}
