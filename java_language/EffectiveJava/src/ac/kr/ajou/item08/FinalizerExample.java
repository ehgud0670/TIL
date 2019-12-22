package ac.kr.ajou.item08;

public class FinalizerExample {
    int a = 5;
    //note: GC가 동작할때 finalizer 가 호출이 된다.
    //  finalizer 가 언제 호출될지 알 수가 없다.
    @Override
    protected  void  finalize() throws Throwable {
        System.out.println("Clean up");
    }
    void hello(){
        System.out.println("hi");
    }
}
