package kr.ac.ajou.programmers.algo0617;

import java.util.Arrays;

public class 같은_숫자는_싫어_1 {

    private static int[] solution(int[] arr) {

        int len = arr.length;
        if (len == 1) {
            return arr;
        }

        int[] answer = new int[len];

        int k = -1;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] != arr[j]) {
                    answer[++k] = arr[i];
                    i = j - 1;
                    break;
                }
            }
        }

        if (k == -1) {
            return new int[]{arr[0]};
        }

        int last = arr[len - 1];

        if (answer[k] != last) {
            answer[++k] = last;
        }

        answer = Arrays.copyOf(answer, k + 1);

        return answer;
    }

    public static void main(String[] args) {

        int[] arr = {1, 1, 3, 3, 0, 1, 1};

        System.out.println(Arrays.toString(solution(arr)));
    }
}
