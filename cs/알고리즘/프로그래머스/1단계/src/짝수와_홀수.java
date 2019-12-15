package kr.ac.ajou.programmers.algo0618;

public class 짝수와_홀수 {
    public String solution(int num) {
        final String EVEN = "Even";
        final String ODD = "Odd";

        if (num % 2 == 0) {
            return EVEN;
        } else {
            return ODD;
        }

    }

    public static void main(String[] args) {
        짝수와_홀수 test = new 짝수와_홀수();
        System.out.println(test.solution(3));
        System.out.println(test.solution(4));
    }
}
