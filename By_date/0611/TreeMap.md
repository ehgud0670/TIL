# TreeMap

* TreeMap은 이진 트리를 기반으로 한 Map 컬렉션이다. 
 HashMap과의 차이점은 객체를 저장하면 키를 기준으로 자동 오름차순으로 정렬된다는 점이다.
 <br>기본적으로 부모 키값과 비교해서 키 값이 낮은 것은 왼쪽 자식 노드에, 키 값이 높은 것은 
 오른쪽 자식 노드에 Map.Entry에 저장한다.<br> **키를 기준으로 자동 정렬한다는 것을 기억해두자.**
 
 키를 String 타입으로 사용하고 값으로 Integer 타입을 사용하는 TreeMap 객체 생성하기.
 ```java
 TreeMap<String, Integer> treeMap = new TreeMap<>();
 ```
 => Map 인터페이스 타입 변수에 대입해도 되지만 TreeMap 클래스 타입으로 대입한 이유는 
 <br>특정 객체를 찾거나 범위 검색과 관련된 TreeMap의 메소드를 사용하기 위해서이다.
 
 <br><br>다음은 TreeMap이 가지고 있는 검색 관련 메소드들이다. 

 | 리턴 타입 | 메소드 | 설명 |
 |----------------|--------------------|------------------------------------------------------------|
 |Map.Entry<K,V>  | firstEntry()       | 키가 제일 낮은 Map.Entry를 리턴 |
 |Map.Entry<K,V>  | lastEntry()        | 키가 제일 높은 Map.Entry를 리턴 |
 |Map.Entry<K,V>  | lowerEntry(K key)  | 주어진 키보다 바로 아래 Map.Entry를 리턴 |
 |Map.Entry<K,V>  | higherEntry(K key) | 주어진 키보다 바로 위 Map.Entry를 리턴 | 
 |Map.Entry<K,V>  | floorEntry(K key)  | 주어진 키와 동등한 키가 있으면 해당 Map.Entry를 리턴, <br>없다면 주어진 키 바로 아래의 Map.Entry를 리턴 |
 |Map.Entry<K,V>  | ceilingEntry(K key)| 주어진 키와 동등한 키가 있으면 해당 Mao.Entry를 리턴, <br>없다면 주어진 키 바로 위의 Map.Entry를 리턴 |
 |Map.Entry<K,V>  | pollFirstEntry()   | 키가 제일 낮은 Map.Entry를 꺼내오고 컬렉션에서 제거함 |
 |Map.Entry<K,V>  | pollLastEntry()    | 키가 제일 높은 Map.Entry를 꺼내오고 컬렉션에서 제거함 |
 

TreeMap 예제 
 ```java

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

```
 
 
 > TreeMap의 키와 Comparable & Comparator 는 뗄레야 뗄수 없는 관계
 
 => TreeMap의 키는 저장과 동시에 자동 오름차순으로 정렬되는데, 숫자(Integer, Double)타입일 경우에는
 값으로 정렬하고, 문자열(String) 타입일 경우에는 유니코드로 정렬한다. 
 TreeMap은 정렬을 위해 java.lang.Comparable을 구현한 객체를 요구하는데, 
 Integer, Double, String은 모두 Comparable 인터페이스를 구현하고 있다. 
 <br>**사용자 정의 클래스도 Comparable 인터페이스를 구현한다면 자동 정렬이 가능하고**, Comparable을 구현한 객체이거나,
 TreeMap의 생성자에 매개값으로 Comparator을 줘야 하고 아니라면 객체를 TreeMap에 키로 저장하는 순간 ClassCastException이 발생한다.
 
 
 *  TreeMap의 키가 될 클래스는 Comparable 인터페이스를 구현한 클래스이거나 아니면 TreeMap 
 생성자의 매개값으로 Comparator를 제공해야 한다. 
 **그렇지 않다면 저장하는 순 런타임 예외인 ClassCastException이 발생한다.
 그리고 OCP를 만족하려면 Comparable이 아닌 Comparator로 비교해야 함을 명심하자.**
 
 
 
   
   