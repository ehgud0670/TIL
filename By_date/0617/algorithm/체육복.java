package kr.ac.ajou.programmers.algo0617;


import java.util.HashSet;

public class 체육복 {

    private static int solution(int n, int[] lost, int[] reserve) {
        final int NONE = 0;
        int lostLength = lost.length;
        int reserveLength = reserve.length;

        // 중복된 것 찾기.
        int overLap = 0;
        for (int i = 0; i < lostLength; i++) {
            for (int j = 0; j < reserveLength; j++) {
                if (lost[i] == reserve[j]) {
                    ++overLap;
                    lost[i] = NONE;
                    reserve[j] = NONE;
                    break;
                }
            }
        }

        HashSet<Integer> recoverSet = new HashSet<>();

        for (int lostNum : lost) {

            if (lostNum == NONE) {
                continue;
            }
            for (int i = 0; i < reserveLength; i++) {
                if (reserve[i] == NONE) {
                    continue;
                }
                if (lostNum == reserve[i] - 1 || lostNum == reserve[i] + 1) {
                    recoverSet.add(lostNum);
                    reserve[i] = NONE;//NONE 처리
                    break;
                }
            }
        }
        return n - lostLength + overLap + recoverSet.size();
    }

    public static void main(String[] args) {
        int n = 5;
        int[] lost = {2, 4, 5};
        int[] reserve = {3, 5};

        System.out.println(solution(n, lost, reserve));
    }
}
