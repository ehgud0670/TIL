package kr.ac.ajou.programmers.algo0617;

import java.util.ArrayList;
import java.util.List;

import java.util.Arrays;

public class 모의고사 {

    private static int[] solution(int[] answers) {

        final int PENTA = 5;
        final int OCTAL = 8;
        final int DECIMAL = 10;
        final int PLUS_ONE = 1;

        int[] player1 = {1, 2, 3, 4, 5};
        int[] player2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] player3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};


        int[] sums = new int[3];

        int len = answers.length;

        // note: 정답 맞추기
        for (int i = 0; i < len; i++) {
            int value = answers[i];
            //player1
            if (player1[i % PENTA] == value) {
                sums[0] += PLUS_ONE;
            }
            //player2
            if (player2[i % OCTAL] == value) {
                sums[1] += PLUS_ONE;
            }
            //player3
            if (player3[i % DECIMAL] == value) {
                sums[2] += PLUS_ONE;
            }
        }


        //note: find Max
        int max = sums[0];
        for (int i = 1; i < 3; i++) {
            if (sums[i] > max) {
                max = sums[i];
            }
        }

        // note: 1등 찾아내기 ( 공동 포함 )
        List<Integer> playerList = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (sums[i] == max) {
                playerList.add(i + 1);
            }
        }

        // note : List -> int[]
        int size = playerList.size();
        int[] answer = new int[size];
        for(int i=0; i<size; i++){
            answer[i] = playerList.get(i);
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] answers = {1, 2, 3, 4, 5};

        System.out.println(Arrays.toString(solution(answers)));
    }
}


