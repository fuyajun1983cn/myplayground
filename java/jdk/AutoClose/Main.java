class Resource implements AutoCloseable {
    void doSome() {
        System.out.println("do something");
    }

    public void close() throws Exception {
        System.out.println("close resources");
    }
}

public class Main {
    public static void main(String args[]) {
        //自动关闭资料的新语法， Java 7引入
        try (Resource res = new Resource()) {
            res.doSome();
        } catch(Exception ex) {
            ex.printStackTrace();
        }
    }
}
