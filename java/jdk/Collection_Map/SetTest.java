import java.util.*;

public class SetTest {

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入英文：");
        String line = scanner.nextLine();
        String[]  tokens = line.split(" ");
        Set words = new HashSet();
        
        for (String token : tokens) {
            words.add(token);
        }

        System.out.printf("不重复的单字有%d个：%s%n", words.size(), words);
    }
}
