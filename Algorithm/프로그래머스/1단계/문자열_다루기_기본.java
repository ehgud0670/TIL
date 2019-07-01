package kr.ac.ajou.programmers.algo0617;


public class 문자열_다루기_기본 {
    private static boolean solution(String s) {

        try {
            Integer.valueOf(s);
            int len = s.length();
            if(len == 4 || len == 6){
                return true;
            }
        } catch(NumberFormatException e){
            return false;
        }

        return false;
    }

    public static void main(String[] args) {
        System.out.println(solution("123456"));
    }
}
