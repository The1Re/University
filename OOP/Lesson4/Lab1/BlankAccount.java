package Lab1;
public class BlankAccount {
    private String name;
    private double amount = 0;
    private Date date = new Date(21,6,2023);

    public BlankAccount(String name)
    {
        this.name = name;
    }

    public BlankAccount(String name, double amount, Date date)
    {
        this.name = name;
        this.amount = amount;
        this.date = date;
    }

    public void deposit(double amount)
    {
        this.amount += amount;
    }

    public boolean withdraw(double amount)
    {
        if (amount <= this.amount){
            this.amount -= amount;
            System.out.println("withdraw succes your account = "+this.amount);
            return true;
        }
        System.out.println("Error withdraw please try again!");
        return false;
    }

    public void transfer(BlankAccount other, double amount)
    {
        if (amount <= this.amount){
            this.amount -= amount;
            other.deposit(amount);
            System.out.println("Transfer succes your account = "+this.amount);
        }
        System.out.println("Error transfer try again!!");
    }

    public double getAmount()
    {
        return this.amount;
    }

    public String getInfo()
    {
        return this.name+" => "+date.getDay()+"/"+date.getMonth()+"/"+date.getYear();
    }
}
