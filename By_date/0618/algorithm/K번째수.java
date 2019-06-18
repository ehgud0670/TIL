package kr.ac.ajou.programmers.algo0618;

import java.util.Arrays;

public class K번째수 {
    private static int[] solution(int[] array, int[][] commands) {

        int num = commands.length;
        int[] answer = new int[num];

        int count = 0;
        for (int[] command : commands) {
            int startIndex = command[0] - 1;
            int endIndex = command[1] - 1;
            int size = endIndex - startIndex + 1;

            int[] temp = new int[size];

            int t = 0;
            for (int j = startIndex; j <= endIndex; j++) {
                temp[t++] = array[j];
            }
            Arrays.sort(temp);

            int k = command[2] - 1;
            answer[count++] = temp[k];
        }


        return answer;
    }

    public static void main(String[] args) {
        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

        System.out.println(Arrays.toString(solution(array, commands)));
    }
}
