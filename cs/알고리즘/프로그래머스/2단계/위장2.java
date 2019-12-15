package kr.ac.ajou.programmers.algo0619;

import java.util.Collection;
import java.util.HashMap;

public class 위장2 {
    public int solution(String[][] clothes) {

        HashMap<String, Integer> hashMap = new HashMap<>();
        for (String[] cloth : clothes) {
            hashMap.put(cloth[1], hashMap.getOrDefault(cloth[1], 0) + 1);
        }
        Collection<Integer> set = hashMap.values();
        int sum = 1;
        for(int value : set){
            sum*=(value+1);
        }
        sum -=1;

        return sum;
    }

    public static void main(String[] args) {
        String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"},
                {"green_turban", "headgear"}};

        위장2 test = new 위장2();
        System.out.println(test.solution(clothes));
    }
}
