package kr.ac.ajou.programmers.algo0619;

import java.util.Collection;
import java.util.HashMap;

// note : 조합구하기.  => 재귀로 구한다. 재귀가 중요한 거였구나.
// note : 모든 경우를 조합으로 풀려니 시간초과 뜬다. 위장2를 살펴보자.
public class 위장 {

    private int doCombinationAndMutiply(int n, int r, int target, int[] arr) {

        int sum = 0;

        if (r == 0) {
            return 1;
        } else if (target == n) {
            return 0;
        } else {
            // target을 선택한다면
            sum += arr[target] * doCombinationAndMutiply(n, r - 1, target + 1, arr);
            // target을 선택하지 않는다면,
            sum += doCombinationAndMutiply(n, r, target + 1, arr);
        }

        return sum;
    }

    public int solution(String[][] clothes) {
        int sum = 0;
        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String[] cloth : clothes) {
            hashMap.put(cloth[1], hashMap.getOrDefault(cloth[1], 0) + 1);
        }

        Collection<Integer> set = hashMap.values();

        int n = set.size();
        int[] arr = new int[n];

        int i = 0;
        for (int value : set) {
            arr[i++] = value;
        }

        for (int r = 1; r <= n; r++) {
            sum += doCombinationAndMutiply(n, r, 0, arr);
        }

        return sum;
    }

    public static void main(String[] args) {
        위장 test = new 위장();

        String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"},
                {"green_turban", "headgear"}};
        System.out.println(test.solution(clothes));
    }
}
