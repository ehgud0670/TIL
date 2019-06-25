package kr.ac.ajou.study0613.hashcode;

import java.lang.ref.WeakReference;
import java.util.*;

public class KeyExample {
    public static void main(String[] args) {
        Key key1 = new Key(3);
        Key key2 = new Key(2);
        Key key3 = new Key(1);
        Key key4 = new Key(1);

        HashSet<Key> keyHashSet = new HashSet<>();
        keyHashSet.add(key1);
        keyHashSet.add(key2);
        keyHashSet.add(key3);
        keyHashSet.add(key4);

        for(Key key : keyHashSet){
            System.out.println(key.getNumber());
        }
        System.out.println();

        HashMap<Key, String> keyStringHashMap = new HashMap<>();
        keyStringHashMap.put(key1, "kim");
        keyStringHashMap.put(key2, "gyu");
        keyStringHashMap.put(key3, "ho");
        keyStringHashMap.put(key4, "Doe");

        // hashCode를 재정의해야 오름차순으로 자동 정렬된다.
        Set<Map.Entry<Key, String>> entrySet = keyStringHashMap.entrySet();

        for (Map.Entry<Key, String> entry : entrySet) {
            System.out.println(entry.getKey().getNumber() + "-" + entry.getValue());
        }


    }
}
