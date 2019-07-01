package kr.ac.ajou.programmers.algo0617;

public class 소수_찾기 {

    private static int solution(int n) {
        int count = 0;

        for (int i = 2; i <= n; i++) {

            boolean check = false;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                count++;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        System.out.println(solution(1000000));
    }
}
