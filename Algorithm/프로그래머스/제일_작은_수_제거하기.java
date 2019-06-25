package kr.ac.ajou.programmers.algo0617;

import java.util.Arrays;

public class 제일_작은_수_제거하기 {

    private static int[] solution(int[] arr) {
        int len = arr.length;
        if (len == 1) {
            return new int[]{-1};
        }

        int min = arr[0];
        for (int i = 1; i < len; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }

        int[] answer = new int[len - 1];

        int k = 0;
        for (int value : arr) {
            if (value != min) {
                answer[k++] = value;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 4};
        System.out.println(Arrays.toString(solution(arr)));
    }
}
