package ac.kr.ajou.item07;

import java.util.WeakHashMap;

public class WeakHashMapTest {
    public static void main(String[] args) {
        WeakHashMap<Integer, String> map = new WeakHashMap<>();

        Integer key1 = 1000;
        Integer key2 = 2000;

        map.put(key1, "test a");
        map.put(key2, "test b");

        key1 = null;
        System.gc(); // 강제 GC(Garbage Collector) 실행
        map.entrySet().forEach(System.out::println);

        // note: key1 객체가 null 이 되어 버리면
        //  key1을 map 이 아무리 key 로서, 객체로서 가져도
        //  map 이 WeakHashMap 이라 약한 참조로 객체(key1)를 참조하고 있어
        //  가비지 컬렉터의 대상이 되고 메모리가 충분해도 지워진다.
        //  따라서 map에는 key: 2000 , value = "test b" 만이 남게 된다.
    }
}
