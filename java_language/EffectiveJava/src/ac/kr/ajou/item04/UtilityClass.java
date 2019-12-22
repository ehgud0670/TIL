package ac.kr.ajou.item04;

public class UtilityClass {
    // 유틸 클래스라 인스턴스를 만들지 못하게 막았습니다.
    private UtilityClass(){
        throw new AssertionError();
    }

    static void printHello(){
        System.out.println("hello world");
    }
}
