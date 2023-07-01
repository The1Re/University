public class CommissionPay extends Employee{
    private double gross_sale;
    private double commission_rate;
    public CommissionPay(String first, String last, String ssn, double gs, double com)
    {
        super(first ,last ,ssn);
        gross_sale = gs;
        commission_rate = com;
    }
    public double earnings()
    {
        return gross_sale*commission_rate;
    }
    @Override
    public String toString(){
        return "commission employee: "+super.toString()+"\n"+
                "gross sales: $"+gross_sale+"; commission rate: "+commission_rate;
    }
}
