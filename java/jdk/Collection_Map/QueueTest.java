import java.util.*;

interface Request {
    void execute();
}

public class RequestQueue {

    public static  void main(String args[]) {
        Queue requests = new LinkedList();
        //仿真将请求加入队列
        for (int i = 1; i < 6; i++) {
            requests.offer(new Request() {
                public void execute() {
                    System.out.printf("处理数据 %f%n", Math.random());
                }
            });
        }

        process(requests);
    }

    //处理队列请求
    private static void process(Queue requests) {
        
        while(requests.peek() != null) {
            Request request = (Request)request.poll();
            request.execute();
        }
    }
}
