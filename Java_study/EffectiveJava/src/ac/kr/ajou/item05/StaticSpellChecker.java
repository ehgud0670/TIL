package ac.kr.ajou.item05;

import java.util.List;

public class StaticSpellChecker {
    private static final Lexicon dictionary = new KoreanDictionary();

    private StaticSpellChecker() {
        throw new AssertionError();
    }

    public static boolean isValid(String word) {
        throw new UnsupportedOperationException();
    }

    public static List<String> suggestions(String typo) {
        throw new UnsupportedOperationException();
    }


    public static void main(String[] args) {
        StaticSpellChecker.isValid("hello");
    }
}
