package ac.kr.ajou.item08;

public class SampleRunner {


    public static void main(String[] args) throws InterruptedException {
        SampleRunner runner = new SampleRunner();
        runner.run();
        System.gc();
        // note: run() 메소드가 끝나면 finalizerExample 은 더이상 유효하지 않아 GC의 대상이 된다.
        //  하지만 finalize()은 바로 호출되지 않고 finalizerExample 은  바로 소멸되지 않는다.
        //  GC가 언제 동작할지 모르기 때문에 finalize()의 호출이 불명확하고, 따라서 객체을 소멸하는데 finalize()는 써선 안되고
        //  오히려 성능에 문제가 생긴다. ( 또 아예 호출되지 않을 수도 있다.)
        Thread.sleep(1000L);
    }

    private void run(){
        FinalizerExample finalizerExample = new FinalizerExample();
        finalizerExample.hello();
    }
}
