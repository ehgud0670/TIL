package kr.ac.ajou.programmers;

import java.util.Arrays;

public class 완주하지_못한_선수 {
    private static String solution(String[] participant, String[] completion) {
        Arrays.sort(participant);
        Arrays.sort(completion);
        int pLength = participant.length;

        try {
            for (int i = 0; i < pLength; i++) {
                if (!participant[i].equals(completion[i])) {
                    return participant[i];
                }
            }
        } catch(ArrayIndexOutOfBoundsException ignored){

        }

        return participant[pLength-1];
    }
    public static void main(String[] args) {
        String[] participant = {"mislav", "stanko", "mislav", "ana"};
        String[] completion = {"stanko", "ana", "mislav"};
        System.out.println(solution(participant,completion));
    }
}
