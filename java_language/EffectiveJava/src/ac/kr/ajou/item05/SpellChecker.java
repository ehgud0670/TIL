package ac.kr.ajou.item05;

import java.util.List;
import java.util.Objects;
import java.util.function.Supplier;


// => 정적 유틸리티를 잘못 사용한 예 : 유연하지 않고 테스트하기 어렵다.
//public class SpellChecker {
//
//    private static final Lexicon dictionary = new KoreanDictionary();
//
//    // 객체 생성 방지
//    private SpellChecker() {
//        throw new AssertionError();
//    }
//
//    public static boolean isValid(String word){
//        return false;
//    }
//
//    public static List<String> suggestions(String typo){
//        return new ArrayList<>();
//    }
//
//}
//  => 싱글턴을 잘못 사용한 예 : 유연하지 않고 테스트하기 어렵다.
//public class SpellChecker {
//    private final Lexicon dictionary = new KoreanDictionary();
//
//    private SpellChecker() {
//    }
//    public static final SpellChecker INSTANCE = new SpellChecker();
//
//    public boolean isValid(String word) {
//        return false;
//    }
//    public List<String> suggestions(String typo) {
//        return new ArrayList<>();
//    }
//
//    public static void main(String[] args) {
//        SpellChecker.INSTANCE.isValid("hello");
//    }
//}


// 의존 객체 주입은 유연성과 테스트 용이성을 높여준다.
public class SpellChecker {
    // Lexicon 은 클래스가 아닌 인터페이스로 만들어야 함을 잊지 마라.
    private final Lexicon dictionary;

    //    public SpellChecker(Lexicon dictionary) {
//        this.dictionary = Objects.requireNonNull(dictionary);
//    }
    public SpellChecker(Supplier<? extends Lexicon> dictionary) {
        this.dictionary = Objects.requireNonNull(dictionary.get());
    }

    public boolean isValid(String word) {
        throw new UnsupportedOperationException();
    }

    public List<String> suggestions(String typo) {
        throw new UnsupportedOperationException();
    }

    public static void main(String[] args) {

        Lexicon koreanDictionary = new KoreanDictionary();
        SpellChecker spellChecker = new SpellChecker(() -> koreanDictionary);
        spellChecker.isValid("hello");

        Lexicon testDictionary = new TestDictionary();
        spellChecker = new SpellChecker(()->testDictionary);
        spellChecker.isValid("hello");
    }
}