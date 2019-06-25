package kr.ac.ajou.programmers.algo0617;

public class 약수의_합 {

    private static int solution(int n) {
        int sum = 0;
        int half = n / 2;
        for (int i = 1; i <= half; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }

        return sum + n;
    }

    public static void main(String[] args) {
        System.out.println(solution(12));
    }
}
