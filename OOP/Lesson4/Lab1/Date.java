package Lab1;
public class Date{
    private int day;
    private int month;
    private int year;

    public Date(int d, int m, int y)
    {
        this.day = d;
        this.month = m;
        this.year = y;
    }

    public void setDay(int d)
    {
        if (d>=1 && d<=31)
            this.day = d;
    }

    public void setMonth(int m)
    {
        if (m>=1&&m<=12)
            this.month = m;
    }

    public void setYear(int y)
    {
        this.year = y;
    }

    public int getDay()
    {
        return this.day;
    }

    public int getMonth()
    {
        return this.month;
    }

    public int getYear()
    {
        return this.year+543;
    }
}