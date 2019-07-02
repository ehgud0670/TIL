package kr.ac.ajou.programmers.algo0617;

public class 문자열_정수로_바꾸기 {
    private static int solution(String s) {
        char sign;
        char temp = s.charAt(0);

        int len = s.length();
        int num;

        if (temp == '+' || temp == '-') {
            sign = temp;
            num = Integer.valueOf(s.substring(1, len));
            return sign == '+' ? +num : -num;
        } else {
            num = Integer.valueOf(s);
            return num;
        }
    }

    public static void main(String[] args) {
        System.out.println(solution("+1234"));
    }
}
