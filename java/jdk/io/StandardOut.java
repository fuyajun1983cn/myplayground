import java.io.*;

public class StandardOut {

    public static void main(String[] args) throws IOException {

        try (PrintStream printStream = new PrintStream(new FileOutputStream(args[0]))) {
            System.setOut(printStream);
            System.out.println("Hello, World");
        }
    }
}
