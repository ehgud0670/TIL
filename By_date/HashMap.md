# HashMap

* HashMap은  Map 인터페이스를 구현한 대표적인 Map 컬렉션으로, 
키(key)와 값(value)으로 구성된 Entry 객체를 저장하는 구조를 가지고 있다. 
<br>데이터베이스 테이블도 '키(key)-값(value)'으로 구성된 데이터 집합이다. 
근데 데이터베이스는 어플의 데이터 관리에서 어떻게 보면 필수적인 부분인데, 
'키(key)-값(value)'구조가 HashMap이 데이터베이스와 같아 HashMap을  
데이터 전송할때 많이 사용한다.

> equals() , hashCode() 를 오버라이딩해야 한다.

* HashMap의 키로 사용할 객체로 hashCode()와 equals() 메소드를 
<br>오버라이딩해서 동등 객체가 될 조건을 정해야 한다. 

<br>주로 키 타입은 String을 많이 사용하는데, String은 문자열이 같을 경우 동등 객체가 
<br>될 수 있도록  hashCode()와  equals()를 오버라이딩 되어 있기 때문이다.  


클래스 하나 만들어서 hashCode()와 equals() 오버라이딩 하기 
```java
public class Student {
    private int sno;
    private String name;

    Student(int sno, String name) {
        this.sno = sno;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Student) {
            Student student = (Student) obj;

            // 학번과 이름이 동일한 경우 true을 리턴
            return this.name.equals(student.name) && this.sno == student.sno;
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return this.sno + this.name.hashCode();
    }
}

```

>  HashMap 생성

* 키와 값의 타입은 기본 타입(byte, short, int, float, double, boolean, char)을 
<br> 사용할 수 없고 클래스(박싱 타입 포함 ex: Integer) 및 인터페이스 타입만 가능하다.


키 타입은 String, 값 타입은 Integer로 HashMap 객체 생성.
```java
Map<String, Integer> map = new HashMap<>();
``` 

<br>HashMap 예제
```java
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

```


hashCode() 와 equals()를 오버라이딩한 
<br>Student 클래스를 key로 이용하여 HashMap 사용하기.
```java
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

```