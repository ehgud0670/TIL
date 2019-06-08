package ac.kr.ajou.item07.cache;

import java.util.HashMap;
import java.util.Map;
import java.util.WeakHashMap;

public class CacheSample {
    public static void main(String[] args) {
        // note: HashMap은 캐시에 쓰면 안되는 나쁜 예.
        Integer key1 = 1000;
        String value1 = "value1";

        Map<Integer, String> hashMapCache = new HashMap<>();
        hashMapCache.put(key1, value1);
        System.out.print("hashMapCache: ");
        hashMapCache.entrySet().forEach(System.out::println);

        key1 = null;
        System.gc(); // 강제 가비지 콜렉터 돌림.
        System.out.print("hashMapCache: ");
        hashMapCache.entrySet().forEach(System.out::println);
        // note : HashMap 은 Strong reference 라서 key1을 null 처리해도 key1은 지워지지 않는다.

        Integer key2 = 2000;
        String value2 = "value2";

        Map<Integer, String> weakHashMapCache = new WeakHashMap<>();
        weakHashMapCache.put(key2, value2);
        System.out.print("weakHashMapCache: ");
        weakHashMapCache.entrySet().forEach(System.out::println);

        key2 = null;
        System.gc();
        System.out.print("weakHashMapCache: ");
        weakHashMapCache.entrySet().forEach(System.out::println);
        // note : WeakHashMap 은 Weak reference 라서 key2을 null 처리하면 key2은 지워진다.

    }


}
