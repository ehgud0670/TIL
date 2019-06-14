# HashSet

> 우선 Set 이란?

=> List 컬렉션은 저장 순서를 유지하지만, **(1) Set 컬렉션은 저장 순서가 유지되지 않는다. 
(2) 또한 객체를 중복해서 저장 할 수 없고, 하나의 null 만 저장할 수 있다.** 
<br> Set 컬렉션은 수학의 집합에 비유될 수 있다. 집합은 순서와 상관없고 중복이 허용되지 않기 때문이다. 

> hashCode(), equals()를 오버라이딩 하라!

HashSet은 Set 인터페이스의 구현 클래스이다. 

String 객체를 저장하는 HashSet 객체.
```java
Set<String> set = new HashSet<String>();
```

HashSet은 동일한 객체를 중복 저장하지 않는다. (마치 수학의 집합이 같은 값의 원소를 중복 저장하지 않는 것처럼!)
HashSet이 판단하는 동일한 객체란 보통 같은 참조 객체가 아닌 논리적으로 같은 객체를 일컫는다. HashSet은 동일한 객체인지
아닌지 hashCode() 와 equals()를 이용하여 비교한다. (1) 먼저 hashCode()를 호출해 서로 비교하고 다르면 다르다고 판단한다. 
(2) hashCode()의 값이 같다면 그 다음으로 equals()로 서로 비교해서 같으면 true를, 다르면 false를 리턴한다.
(hashMap의 키도 마찬가지!)
<br>**근데 Object 클래스의 hashCode() 와 equals()는 참조 비교이므로 이들을 오버라이딩해서 논리적 비교가 되게끔 코드를
반드시 작성해야 한다.** 오버라이딩을 올바르게 하였으면 HashSet 의 논리적 비교는 정상 작동하고 추가 할때 동일한 객체라 
판단하면 추가하지 않고, 새로운 객체라 판단하면 추가를 하게 된다.  

> hashCode를 오버라이딩 하였다면, HashSet 도 오름차순 자동 정렬이 된다. 

* Test 해본 결과, hashCode를 제대로 오버라이딩만 하였다면 HashSet도(HashMap도 마찬가지) 
TreeSet이나 TreeMap처럼 오름차순으로 자동 정렬이 됨을 알 수 있었다. 

테스트 한 소스 코드 \[Key.java, KeyExample.java]
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

    @Override
    public int hashCode() {
        return number;
    }

    int getNumber() {
        return number;
    }
}


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
// hashCode를 재정의하면, (int number 를 기준으로)
// number: 1
// number: 2
// number: 3 
```
