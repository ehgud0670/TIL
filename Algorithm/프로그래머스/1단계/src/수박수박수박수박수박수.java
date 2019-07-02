package kr.ac.ajou.programmers;

public class 수박수박수박수박수박수 {

    public static String solution(int n) {
        String supark = "수박";
        String su = "수";
        StringBuilder stringBuilder = new StringBuilder();

        int quo = n / 2;

        for (int i = 0; i < quo; i++) {
            stringBuilder.append(supark);
        }
        if (n % 2 != 0) {
            stringBuilder.append(su);
        }
        return stringBuilder.toString();
    }

    public static void main(String[] args) {
        System.out.println(solution(5));
    }
}
