package ac.kr.ajou.item08;

public class Teenager {
    public static void main(String[] args) {
        new Room(99);
        System.gc();
        //NOTE: System.gc 나 System.runFinalization 메서드에 현혹되지 말자.
        // finalizer 와 cleaner 가 실행될 가능성을 높여줄 순 있으나,
        //  (*)보장해주지 않는다!
        System.out.println("아무렴");
    }
}
