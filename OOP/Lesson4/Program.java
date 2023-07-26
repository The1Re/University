public class Program {
    public static void main(String args[])
    {
        Date date = new Date(21,6,2565);
        System.out.println(date.getDay());
        date.setDay(5);
        System.out.println(date.getDay());
    }
}
