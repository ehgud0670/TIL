package kr.ac.ajou.programmers;

public class 시저_암호 {

    private static String solution(String s, int n) {

            StringBuilder answer = new StringBuilder();

            char[] chars = s.toCharArray();

            for (char c : chars) {
                if (c == ' ') {
                    answer.append(c);
                    continue;
                }

                if (c < 'a') {
                    int absol = (c - 'A' + n);
                    if (absol < 26) {
                        c += n;
                    } else {
                        c = (char) ('A' + absol - 26);
                    }
                } else {
                    int absol = (c - 'a' + n);
                    if (absol < 26) {
                        c += n;
                    } else {
                        c = (char) ('a' + absol - 26);
                    }
                }
                answer.append(c);
            }

            return answer.toString();
        }


    public static void main(String[] args) {
        System.out.println(solution("a B z", 1));
    }
}
