# Flyweight Pattern 

## �ö��̿���Ʈ ������ ����ϴ� �ڹ��� ������ ���

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

// 18�ٿ��� ����� �� ��� 
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
        md1.name = "ȫ�浿";

        MyData md2 = new MyData();
        md2 = md1;

        MyData md3 = new MyData();
        md3.xpos = 20;
        md3.ypos = 21;
        md3.name = "�տ���";

        md2.name = "����ġ";
        md2.xpos = 5;

        System.out.println("Flyweight Pattern");
    }
}

class MyData {
    int xpos;
    int ypos;
    String name;
}

// 53�ٿ��� ������� ���
// args = {String[0]@466} 
// md1 = {MyData@467} 
// md2 = {MyData@467} 
// md3 = {MyData@468} 
// md2.xpos = 5
```

## ���丮���� ����ؼ� �ö��̿���ư ���� �̿��ϱ�


FlyweightFactory.java
```java
public class FlyweightFactory {
    private static Map<String, Subject> map = new HashMap<>();

    public Subject getSubject(String key) {
        Subject subject = map.get(key);
        if (subject == null) {
            subject = new Subject(key);
            map.put(key, subject);

            System.out.println("���� ���� " + key);
        } else {
            System.out.println("���� " + key);
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

// ���� ��� 
// ���� ���� a
// ���� a
// ���� ���� b
// ���� b
```

