package kr.ac.ajou.programmers.algo0617;

public class 가운데_글자_가져오기 {

    private static String solution(String s) {
        int len = s.length();
        int half = len/2;

        if (len % 2 == 0) {
            return s.substring(half-1,half+1);
        } else {
            return s.substring(half,half+1);
        }
    }

    public static void main(String[] args) {
        System.out.println(solution("abcde"));
    }
}
