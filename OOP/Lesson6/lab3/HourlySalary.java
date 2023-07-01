public class HourlySalary extends Employee{
    private double rate;
    private double hour;
    public HourlySalary(String first, String last, String ssn, double rate, double hour)
    {
        super(first ,last ,ssn);
        this.rate = rate;
        this.hour = hour;
    }
    public double earnings()
    {
        return rate*hour;
    }
    @Override
    public String toString(){
        return "hourly employee: "+super.toString()+"\n"+
                "hourly pay: $ "+rate+"; hours worked: "+hour;
    }
}
