public class Graduate extends Student{
    private String thesisTitle;
    public Graduate(int id, String name, double gpa, String thesisTitle)
    {
        super(id, name, gpa);
        this.thesisTitle = thesisTitle;
    }
    public void setThesisTitle(String thesisTitle) { this.thesisTitle = thesisTitle; }
    public String getThesisTitle() { return this.thesisTitle; }

    @Override
    public String toString() {
        return String.format(
                "Graduate "+super.toString()+
                "thesis:\t"+this.thesisTitle
        );
    }
}
