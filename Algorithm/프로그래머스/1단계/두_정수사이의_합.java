package kr.ac.ajou.programmers;

public class 두_정수사이의_합 {

    private static long solution(int a, int b) {
        long sum = 0;

        if (a == b) {
            return a;
        } else if (a < b) {
            for (int i = a; i <= b; i++) {
                sum += i;
            }
        } else {
            for (int i = b; i <= a; i++) {
                sum += i;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(solution(3, 5));
    }
}
