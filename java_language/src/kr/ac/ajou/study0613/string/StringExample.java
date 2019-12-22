package kr.ac.ajou.study0613.string;

import java.util.TreeSet;

public class StringExample {
    public static void main(String[] args) {
        // note :  String 은  유니코드 깂을 기준으로 오름차순 자동 정렬된다.
        System.out.println("String's Comparable test: ");
        TreeSet<String> case3 = new TreeSet<>();
        case3.add("a");
        case3.add("A");

        for (String str : case3) {
            System.out.println("\t"+str);
        }
    }
}
