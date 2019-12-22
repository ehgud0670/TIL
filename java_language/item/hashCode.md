## Object 클래스의 hashCode()

```java
public native int hashCode();
// native 키워드란?
// native 키워드는 자바가 아닌 언어(보통 C나 C++)로 구현한 후 자바에서 사용하려고 할 때 
// 이용하는 키워드이다. 자바로 구현하기 까다로운 것을 다른 언어로 구현해서, 자바에서
// 사용하기 위한 방법이다. 구현할때 JNI(Java Native Interface)를 사용한다.

// 즉 객체의 주소값(메모리 번지)을 이용하는 hashCode가 주소값을 가져올 때 
// final 키워드를 이용해 자바보다 주소값이 표현가능한 c나 c++언어로 가져와서 
// 자바에서 사용하나 보다. 
```

> 객체 해시코드 

* 객체 해시코드란 객체를 식별할 하나의 정수값을 말한다. 
* Object 의 hashCode() 는 객체의 주소값(메모리 번지)을 이용해서 해시코드를 만들어 리턴하기 때문에
객체마다 다른 값을 가지고 있다. 
* 따라서 Object의 hashCode()를 (오버라이딩 하지 않고)사용하면 객체의 참조 비교에 사용할 수 있지 논리적 비교는 할 수 없다.

> 오버라이딩해서 hashCode() 사용하기

*  HashSet, HashMap, Hashtable 은 객체가 동등한 지 비교할 때 우선 객체의 hashCode()를 이용해 해시코드 값이 같은지 비교하고,
해시코드 값이 서로 다르면 동등하지 않다고 판단하고, 해시코드 값이 같다면 두번째로 객체의 equals()를 이용해 다시 비교한다.

* 따라서 HashSet, HashMap, HashTable의 객체가 될 클래스는 equals와 hashCode를 오버라이딩 하지 않았다면 **참조 비교는 할 수 있어도
논리적 비교는 할 수 없다.** 따라서 꼭 HashSet, HashMap, Hashtable을 사용할거면 hashCode()와 equals()를 꼭 오버라이딩해서 사용하자.
 
 hashCode() 를 오버라이딩하지 않은 Key 클래스
 ```java
public class Key {

    private int number;

    Key(int number) {
        this.number = number;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Key){
            Key key = (Key) obj;
            return this.number == key.number;
        }
        return false;
    }


    int getNumber() {
        return number;
    }
}
``` 

따라서 다른 키로 인식 
```java
public class KeyExample {
    public static void main(String[] args) {
        HashMap<Key,String> hashMap = new HashMap<>();

        hashMap.put(new Key(1), "Kim");

        String value = hashMap.get(new Key(1));
        System.out.println(value);
        // hashCode 와 equals 를 모두 재정의해야 오름차순으로 자동 정렬된다.

    }
}
// 실행 결과
// null
```

Key클래스가 number를 기준으로 hashCode를 재정의함
```java
    @Override
    public int hashCode() {
        return number;
    }
```

논리적으로 같은 키로 인식하여 제대로 출력된다. 
```java
public class KeyExample {
    public static void main(String[] args) {
        HashMap<Key,String> hashMap = new HashMap<>();

        hashMap.put(new Key(1), "Kim");

        String value = hashMap.get(new Key(1));
        System.out.println(value);
        // hashCode 와 equals 를 모두 재정의해야 오름차순으로 자동 정렬된다.

    }
}
//  실행 결과
//  Kim
```


> HashSet이나 HashMap은 원소들을 자동 오름차순 정렬하는데 hashCode를 오버라이딩하지 않으면 정상적으로 정렬되지 않는다.
 따라서 자동 정렬하고 싶다면 hashCode()를 오버라이딩 하도록 하자.
 
 
 HashSet
```java
public class KeyExample {
    public static void main(String[] args) {
        Key key1 = new Key(3);
        Key key2 = new Key(2);
        Key key3 = new Key(1);

        HashSet<Key> keyHashSet = new HashSet<>();
        keyHashSet.add(key1);
        keyHashSet.add(key2);
        keyHashSet.add(key3);


        // hashCode를 재정의해야 오름차순으로 자동 정렬된다.
        for(Key key : keyHashSet){
            System.out.println("number: " + key.getNumber());
        }
    }
}
// 실행 결과
// hashCode를 재정의 하지 않으면,
// number: 3
// number: 1
// number: 2
//
// hashCode를 재정의하면, 
// number: 1
// number: 2
// number: 3 
```
HashMap
```java
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
// hashCode를 재정의 하지 않으면, 
// 3-kim
// 1-ho
// 2-gyu
//
// hashCode를 재정의하면 ,
// 1-ho
// 2-gyu
// 3-kim
```

=> 따라서 HashSet 이나 HashMap을 사용할 때 **정상적으로 자동 정렬이 잘 되도록 하기 위해서라도** 
반드시 hashCode를 재정의하도록 하자.
<br>=\> TreeSet, TreeMap 만 오름차순으로 자동 정렬되는 줄 알았는데, Test 해보니 HashSet 과 HashMap 도 
hashCode를 오버라이딩 하면 오름차순 자동 정렬이 됨을 알 게 되었다. **물론 중복 저장을 피하기 위해 equals 도 오버라이딩 해야 한다.**  
