package kr.ac.ajou.programmers.algo0617;

// NOTE: 하나 이상의 공백 문자인 걸 명심해라! "   " 도 가능하다는 얘기!
public class 이상한_문자_만들기 {
    private static String solution(String str) {
        StringBuilder answer = new StringBuilder();

        int len = str.length();

        int count = 0;
        for (int i = 0; i < len; i++) {
            if (str.charAt(i) == ' ') {
                answer.append(' ');
                count = 0;
            } else {
                String s = String.valueOf(str.charAt(i));
                if (count % 2 == 0) {
                    answer.append(s.toUpperCase());
                } else {
                    answer.append(s.toLowerCase());
                }
                count++;
            }
        }
        return answer.toString();
    }

    public static void main(String[] args) {
        System.out.println(solution("try hello   world"));
    }
}
