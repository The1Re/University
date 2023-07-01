public class Student {
    protected String name;
    protected int id;
    protected  double gpa;
    public Student() {}
    public Student(int id, String name, double gpa )
    {
        this.id = id;
        this.name = name;
        this.gpa = gpa;
    }
    public Student(int id, double gpa)
    {
        this.id = id;
        this.gpa = gpa;
        this.name = "";
    }
    public String getName() { return this.name; }
    public int getId() { return this.id; }
    public double getGpa() { return this.gpa; }

    public void setName(String name) { this.name = name; }

    public String toString()
    {
        return String.format(
                  "Student:\n"+
                  "Id:\t"+this.id+"\n"+
                  "Name:\t"+this.name+"\n"+
                  "GPA:\t"+this.gpa
        );
    }
}
