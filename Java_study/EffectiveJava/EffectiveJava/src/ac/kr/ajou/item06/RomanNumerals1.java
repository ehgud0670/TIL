package ac.kr.ajou.item06;

public class RomanNumerals1 {

    // 주어진 문자열이 유효한 로마 숫자인지를 정규표현식을 이용하여 확인하는 메소드.
    static boolean isRomanNumeral(String s) {
        return s.matches("^(?=.)M*(C[MD]|D?C{0,3})" + "(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$");
    }
    // => String.matches 는 정규표현식으로 문자열 형태를 확인하는 가장 쉬운 방법이지만,
    // 성능이 중요한 상황에서 반복해 사용하기엔 적합하지 않다.

    // 이 메소드가 내부에서 만드는 정규표현식용 Pattern 인스턴스는, 한번 쓰고 버려지는데( 가비지 컬렉션의 대상이 된다.)
    // 하지만 Pattern 은 입력받은 정규표현식에 해당하는 유한 상태 머신(finite state machine)을 만들기 때문에
    // 인스턴스 생성 비용이 높으므로 계속 Pattern 인스턴스를 생성하는 것은 성능이 중요한 상황에서 적합하지 않다.
}
