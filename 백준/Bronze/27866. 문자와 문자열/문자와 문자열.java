import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        int n = scanner.nextInt();
        System.out.println(a.charAt(n-1));
    }
}
