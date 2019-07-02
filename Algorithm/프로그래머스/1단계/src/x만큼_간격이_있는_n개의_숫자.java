package kr.ac.ajou.programmers.algo0618;

import java.util.Arrays;

public class x만큼_간격이_있는_n개의_숫자 {

    public long[] solution(int x, int n) {
        long[] answer = new long[n];

        for (int i = 0; i < n; i++) {
            answer[i] = (long) x * (i + 1);
        }


        return answer;
    }

    public static void main(String[] args) {
        x만큼_간격이_있는_n개의_숫자 test = new x만큼_간격이_있는_n개의_숫자();
        System.out.println(Arrays.toString(test.solution(2, 5)));
        System.out.println(Arrays.toString(test.solution(4, 3)));
        System.out.println(Arrays.toString(test.solution(-4, 2)));

    }
}
