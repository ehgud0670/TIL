package kr.ac.ajou.programmers.algo0618;

public class 핸드폰_번호_가리기 {
    public String solution(String phone_number) {
        StringBuilder answer = new StringBuilder();

        int len = phone_number.length();
        for (int i = 0; i < len - 4; i++) {
            answer.append("*");
        }

        for (int i = len - 4; i < len; i++) {
            answer.append(phone_number.charAt(i));
        }

        return answer.toString();
    }

    public static void main(String[] args) {
        String s = "01033334444";
        System.out.println(new 핸드폰_번호_가리기().solution(s));

        String s2 = "027778888";
        System.out.println(new 핸드폰_번호_가리기().solution(s2));
    }
}
