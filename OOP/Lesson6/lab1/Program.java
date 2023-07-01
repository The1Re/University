public class Program {
    public static void main(String[] args) {
        Student s1 = new Student(97000, "Sameer", 3.51);
        Student s2 = new Student(98000, 3.22);
        Undergrade u1 = new Undergrade(99000, "Shahid", 2.91, "Junior");
        Graduate g1 = new Graduate(200000, "Mubin", 3.57, "Algorithms and Complexity");
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(u1);
        System.out.println(g1);
    }
}
