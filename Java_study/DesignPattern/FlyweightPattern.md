# Flyweight Pattern 

## 플라이웨이트 패턴을 사용하는 자바의 곳곳의 모습

> step1 

TestPattern.java
```java
public class TestPattern {

    public static void main(String[] args) {
        int temp = 3;
        Integer a = new Integer(temp);
        Integer b = new Integer(temp);
        Integer c = Integer.valueOf(temp);
        Integer d = temp;

        System.out.println("Flyweight Pattern");
    }
}

// 18줄에서 디버깅 한 모습 
// args = {String[0]@465} 
// temp = 3
// a = {Integer@466} 3
// b = {Integer@467} 3
// c = {Integer@468} 3
// d = {Integer@468} 3
```

> step2 

TestPattern.java
```java
public class TestPattern {
    public static void main(String[] args) {
        MyData md1 = new MyData();
        md1.xpos = 10;
        md1.ypos = 11;
        md1.name = "홍길동";

        MyData md2 = new MyData();
        md2 = md1;

        MyData md3 = new MyData();
        md3.xpos = 20;
        md3.ypos = 21;
        md3.name = "손오공";

        md2.name = "전우치";
        md2.xpos = 5;

        System.out.println("Flyweight Pattern");
    }
}

class MyData {
    int xpos;
    int ypos;
    String name;
}

// 53줄에서 디버깅한 모습
// args = {String[0]@466} 
// md1 = {MyData@467} 
// md2 = {MyData@467} 
// md3 = {MyData@468} 
// md2.xpos = 5
```

## 팩토리패턴 사용해서 플라이웨이튼 패턴 이용하기


FlyweightFactory.java
```java
public class FlyweightFactory {
    private static Map<String, Subject> map = new HashMap<>();

    public Subject getSubject(String key) {
        Subject subject = map.get(key);
        if (subject == null) {
            subject = new Subject(key);
            map.put(key, subject);

            System.out.println("새로 생성 " + key);
        } else {
            System.out.println("재사용 " + key);
        }

        return subject;
    }

}
```
Subject.java
```java
public class Subject {
    private String name;

    public Subject(String name) {
        this.name = name;
    }

}
```

TestPattern.java
```java
public class TestPattern {
    public static void main(String[] args) {
        FlyweightFactory flyweight = new FlyweightFactory();
        flyweight.getSubject("a");
        flyweight.getSubject("a");
        flyweight.getSubject("b");
        flyweight.getSubject("b");
    }
}

// 실행 결과 
// 새로 생성 a
// 재사용 a
// 새로 생성 b
// 재사용 b
```

