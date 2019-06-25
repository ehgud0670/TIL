package kr.ac.ajou.programmers.algo0617;

import java.util.Arrays;

public class 예산 {
    private static int solution(int[] d, int budget) {

        Arrays.sort(d);

        int count = 0;
        for (int temp : d) {
            if (budget >= temp) {
                count++;
                budget -= temp;
            } else {
                break;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int[] d = {2, 2, 3, 3};
        int budget = 10;
        System.out.println(solution(d, budget));
    }
}
