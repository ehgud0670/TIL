package item04;

public class UtilityClass {
    // 기본 생성자가 만들어지는 것을 막는다 (인스턴스 화 방지용).
    private UtilityClass(){
        throw new AssertionError();
    }

    static void printHello(){
        System.out.println("hello world");
    }
}
