package kr.ac.ajou.study0611.hashmap;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMapExample1 {
    public static void main(String[] args) {
        // Map 컬렉션 생성
        Map<String, Integer> map = new HashMap<>();

        // 객체 지정
        map.put("김도형", 98);
        map.put("김자바", 85);
        map.put("임재범", 90);
        map.put("김자바", 95); // "김자바" 키가 같기 때문에 제일 마지막에 저장한 값으로 대치.
        map.put("홍길동", 83);
        System.out.println("\t임재범 : " + map.get("임재범"));
        System.out.println();

        // 객체 찾기
        System.out.println("총 Entry 수: " + map.size()); // 키로 값 검색.


        // 객체를 하나씩 처리
        Set<String> keySet = map.keySet();
//        Iterator<String> keyIterator = keySet.iterator();
//        while(keyIterator.hasNext()){
//          String key = keyIterator.next();
//          Integer value = map.get(key);
//          System.out.println("\t"+key + " : " + value);
//        }
        for (String key : keySet) {
            Integer value = map.get(key);
            System.out.println("\t" + key + " : " + value);
        }
        System.out.println();

        // 객체 삭제
        map.remove("김자바");
        System.out.println("총 Entry 수: " + map.size());

        // 객체를 하나씩 처리
        Set<Map.Entry<String, Integer>> entrySet = map.entrySet();
//        Iterator<Map.Entry<String,Integer>> entryIterator = entrySet.iterator();

//        while(entryIterator.hasNext()){
//            Map.Entry<String,Integer> entry = entryIterator.next();
//            String key = entry.getKey();
//            Integer value = entry.getValue();
//            System.out.println("\t" + key + " : " +value);
//        }
//        System.out.println();
        for (Map.Entry<String, Integer> entry : entrySet) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            System.out.println("\t" + key + " : " + value);
        }
        System.out.println();

        // 객체 전체 삭제
        map.clear();
        System.out.println("총 Entry 수: " +map.size());
    }
}
