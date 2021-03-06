package ac.kr.ajou.item04;

// 정적 메서드는 final 클래스와 관련된 메서드들을 모아놓을 때도 사용한다.
// final 클래스를 상속해서 하위 클래스에 메서드를 넣는 건 불가능하기 떼문이다.

public final class Final {


    // 정적 멤버만 담은 유틸리티 클래스는 인스턴스로 만들어 쓰려고 설계한 게 아니다.
    // 하지만 생성자를 명시하지 않으면 컴파일러가 자동으로 기본 생성자를 만들어주는데, 즉 매개변수를 받지 않는
    // public 생성자가 만들어지며, 사용자는 생성자가 자동 생성된 것인지 구분할 수 없다.
    // 이와 같은 문제점을 해결하기 위해선 아래와 같이 private 생성자를 만들어야 인스턴스화를 막을 수 있다.
     private Final(){
        throw new AssertionError();
    }
    public static String getName(){
         return "final";
    }
}
