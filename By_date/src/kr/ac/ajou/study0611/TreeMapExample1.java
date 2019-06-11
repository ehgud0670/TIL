package kr.ac.ajou.study0611;

import java.util.Map;
import java.util.TreeMap;

public class TreeMapExample1 {
    public static void main(String[] args) {

        TreeMap<Integer, String> scores = new TreeMap<>();
        scores.put(87, "홍길동");
        scores.put(98, "이동수");
        scores.put(75, "박길순");
        scores.put(95, "신용권");
        scores.put(80, "김자바");

        Map.Entry<Integer, String> entry = null;

        entry = scores.firstEntry(); // 제일 키가 낮은 객체 반환(리턴).
        System.out.println("가장 낮은 점수: " + entry.getKey() + "-" + entry.getValue());

        entry = scores.lastEntry(); // 제일 키가 높은 객체 반환.
        System.out.println("가장 높은 점수: " + entry.getKey() + "-" + entry.getValue());

        entry = scores.lowerEntry(95);
        System.out.println("95점 아래 점수: " + entry.getKey() + "-" + entry.getValue());

        entry = scores.higherEntry(75);
        System.out.println("75점 위 점수: " + entry.getKey() + "-" + entry.getValue());

        entry = scores.floorEntry(80);
        System.out.println("80점 이거나 그 아래 점수: " + entry.getKey() + "-" + entry.getValue());

        entry = scores.ceilingEntry(97);
        System.out.println("97점 이거나 그 위 점수: " + entry.getKey() + "-" + entry.getValue());


        System.out.println();
        while (!scores.isEmpty()) {
            entry = scores.pollFirstEntry();
            System.out.println(entry.getKey() + "-" + entry.getValue() +
                    "(남은 객체 수: " + scores.size() + ")");
        }
    }
}
