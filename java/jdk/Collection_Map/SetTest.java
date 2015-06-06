import java.util.*;

public class SetTest {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please input english words:");
        String line = scanner.nextLine();
        String[]  tokens = line.split(" ");
        Set words = new HashSet();
        
        for (String token : tokens) {
            words.add(token);
        }

        System.out.printf("signle word in set : %d: %s%n", words.size(), words);
    }
}
