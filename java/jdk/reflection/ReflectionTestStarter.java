import java.lang.reflect.*;

public class ReflectionTestStarter {

    public static void main(String[] args) {

        ReflectionTestStarter starter = new ReflectionTestStarter();

        try {
            Class mainClass = Class.forName("ReflectionTest");
            Method mainMethod = mainClass.getMethod("main", new Class[] { String[].class });
            mainMethod.invoke(null, new Object[] { args });

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
