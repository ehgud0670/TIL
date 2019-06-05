package ac.kr.ajou.item03;

import java.util.function.Supplier;

public class ChetExample {

    public static void main(String[] args) {
        //Chet chet = new Chet();
        Chet chet = Chet.getInstance();
        Supplier<Chet> supplier = Chet::getInstance;
    }
}
