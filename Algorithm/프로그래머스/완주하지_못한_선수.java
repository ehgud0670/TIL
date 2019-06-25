package kr.ac.ajou.programmers.algo0619;

import java.util.HashMap;

public class 완주하지_못한_선수 {
    public String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String player : participant) {
            hashMap.put(player, hashMap.getOrDefault(player, 0) + 1);
        }
        for (String player : completion) {
            hashMap.put(player, hashMap.get(player) - 1);
        }

        for (String player : participant) {
            if (hashMap.get(player) != 0) {
                return player;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        완주하지_못한_선수 test = new 완주하지_못한_선수();
        String[] participant = {"mislav", "stanko", "mislav", "ana"};
        String[] completion = {"stanko", "ana", "mislav"};

        System.out.println(test.solution(participant, completion));
    }
}
