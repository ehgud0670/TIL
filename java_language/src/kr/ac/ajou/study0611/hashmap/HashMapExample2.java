package kr.ac.ajou.study0611.hashmap;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMapExample2 {
    public static void main(String[] args) {

        Student student1 = new Student(1, "홍길동");
        Student student2 = new Student(1, "홍길동");

        Map<Student, Integer> map = new HashMap<>();

        map.put(student1, 90);
        map.put(student2, 100);

        System.out.println("총 Entry 수 : " + map.size());

        Set<Map.Entry<Student, Integer>> entrySet = map.entrySet();

        for (Map.Entry<Student, Integer> entry : entrySet) {
            Student key = entry.getKey();
            Integer value = entry.getValue();

            System.out.println("key = " + key.toString() + " value = " + value);

        }

    }
}
