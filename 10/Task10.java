import java.util.Scanner;

public class Task10 {
    public static void main(String[] args) {
        int x, s = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter x: ");
        x = scanner.nextInt();
        
        for (int i = 0; i < 123; i++) {
            s += x;
        }
        
        System.out.println("Sum: " + s);
    }
}