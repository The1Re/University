public class Undergrade extends Student{
    private String year;
    public void setYear(String year) { this.year = year; }
    public String getYear() { return this.year; }

    public Undergrade(int id, String name, double gpa, String year)
    {
        super(id, name, gpa);
        this.year = year;
    }

    @Override
    public String toString() {
        return String.format(
                "Undergrade "+super.toString()+
                "Year:\t"+this.year
        );
    }
}
