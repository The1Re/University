import java.util.ArrayList;

public class Program {
    public static void main(String[] args)
    {
        Employee fixedSalary = new FixedSalary("Clark", "Kent", "555-999-5555", 1500.00);
        Employee hourlySalary = new HourlySalary("Bruce", "Wayne", "555-777-1111", 20.00, 165);
        Employee commissionPay = new CommissionPay("Peter", "Parker", "555-111-5555", 95000, 0.06);

        ArrayList<Employee> employees = new ArrayList<Employee>();
        employees.add(fixedSalary);
        employees.add(hourlySalary);
        employees.add(commissionPay);

        for (Employee emp : employees){
            System.out.println(emp);
            System.out.printf("earned $%.2f\n\n", emp.earnings());
        }
    }
}
