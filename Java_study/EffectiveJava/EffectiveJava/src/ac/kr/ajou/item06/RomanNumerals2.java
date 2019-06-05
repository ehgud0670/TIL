package ac.kr.ajou.item06;

import java.util.regex.Pattern;

public class RomanNumerals2 {
    private static final Pattern ROMAN = Pattern
            .compile("^(?=.)M*(C[MD]|D?C{0,3})" + "(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$");

    // RomanNumerals1 클래스와 달리 이 메소드는 ROMAN이라는 Pattern 인스턴스를 계속 재사용하므로
    // 계속 Pattern 인스턴스를 생성하는 것보다 훨씬 성능을 끌어올릴 수 있다.
    // 조슈아 블로크가 말하길 길이가 8인 문자열을 입력했을때 개선 전에는 1.1us , 개선 후 0.17us 가 걸렸으므로
    // 6.5배정도 빨라졌다고 한다.
    static boolean isRomanNumeral(String s){
        return ROMAN.matcher(s).matches();
    }


}
