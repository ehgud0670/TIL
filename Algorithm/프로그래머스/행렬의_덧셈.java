package kr.ac.ajou.programmers.algo0618;

import java.util.Arrays;

public class 행렬의_덧셈 {

    public int[][] solution(int[][] arr1, int[][] arr2) {

        int len = arr1.length;
        int[][] answer = new int[len][];


        for (int i = 0; i < len; i++) {
            int len2 = arr1[i].length;

            answer[i] = new int[len2];
            for (int j = 0; j < len2; j++) {
                answer[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        return answer;
    }

    public static void main(String[] args) {
        행렬의_덧셈 test = new 행렬의_덧셈();

        int[][] arr1 = {{1, 2}, {2, 3}};
        int[][] arr2 = {{3, 4}, {5, 6}};

        System.out.println(Arrays.deepToString(test.solution(arr1, arr2)));

        int[][] arr3 = {{1}, {2}};
        int[][] arr4 = {{3}, {4}};
        System.out.println(Arrays.deepToString(test.solution(arr3, arr4)));
    }
}
