package kr.ac.ajou.study0613.hashcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class KeyExample {
    public static void main(String[] args) {
        Key key1 = new Key(3);
        Key key2 = new Key(2);
        Key key3 = new Key(1);

        HashMap<Key, String> keyStringHashMap = new HashMap<>();
        keyStringHashMap.put(key1, "kim");
        keyStringHashMap.put(key2, "gyu");
        keyStringHashMap.put(key3, "ho");

        // hashCode를 재정의해야 오름차순으로 자동 정렬된다.
        Set<Map.Entry<Key, String>> entrySet = keyStringHashMap.entrySet();

        for (Map.Entry<Key, String> entry : entrySet) {
            System.out.println(entry.getKey().getNumber() + "-" + entry.getValue());
        }

    }
}
