import java.util.*;

interface Request {
    void execute();
}

public class QueueTest {

    public static  void main(String args[]) {
        Queue requests = new LinkedList();
        //add integer to Queue
        for (int i = 1; i < 6; i++) {
            requests.offer(new Request() {
                public void execute() {
                    System.out.printf("Processing %f%n", Math.random());
                }
            });
        }

        process(requests);
    }

    //process request
    private static void process(Queue requests) {
        
        while(requests.peek() != null) {
            Request request = (Request)requests.poll();
            request.execute();
        }
    }
}
