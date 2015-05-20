
class ResourceSome implements AutoCloseable {
    void doSome() {
        System.out.println("do something");
    }

    public void close() throws Exception {
        System.out.println("close resources");
    }
}

class ResourceOther implements AutoCloseable {
    void doOther() {
        System.out.println("do something other");
    }

    public void close() throws Exception {
        System.out.println("close other resources");
    }
}

public class Main {
    public static void main(String args[]) {
        //自动关闭资料的新语法， Java 7引入
        //可以自动关闭多个资源，中间用分号隔开
        //在try括号里面，越后面写的对象，资源会越早被关闭
        try (ResourceSome some = new ResourceSome(); 
                ResourceOther other = new ResourceOther()) {
            some.doSome();
            other.doOther();
        } catch(Exception ex) {
            ex.printStackTrace();
        }
    }
}
