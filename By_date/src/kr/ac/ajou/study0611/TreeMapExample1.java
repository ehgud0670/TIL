package kr.ac.ajou.study0611;

import java.util.Map;
import java.util.TreeMap;

public class TreeMapExample1 {
    public static void main(String[] args) {

        // note: 점수 기준으로 검색해야 되서 key 값이 Integer 인 것이다.
        TreeMap<Integer, String> scores = new TreeMap<>();
        scores.put(87, "홍길동");  // note: 기본 타입(int)에서 박스타입(Integer)으로 오토박싱된다.
        scores.put(98, "이동수");
        scores.put(75, "박길순");
        scores.put(95, "신용권");
        scores.put(80, "김자바");

        Map.Entry<Integer, String> entry = null;

        entry = scores.firstEntry();
        System.out.println("가장 낮은 점수: " + entry.getKey() + " - " + entry.getValue());

        entry = scores.lastEntry();
        System.out.println("가장 높은 점수: " +entry.getKey() + " - " + entry.getValue());
        System.out.println("good");
    }
}
