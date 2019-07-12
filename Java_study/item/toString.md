## Object 클래스의 toString()

* Object 클래스의 toString() 메소드는 객체의 문자 정보를 리턴한다. 
객체의 문자 정보란 객체를 문자열로 표현한 값을 말한다. 
<br>기본적으로 Object 클래스의 toString() 은 "클래스명@16진수해시코드"로 구성된 
문자 정보를 리턴한다. 

```java
Object obj = new Object();
System.out.println( obj.toString() );

// 실행결과
// java.lang.Object@74a14482
```

> 언제 toString()을 사용할까.

* 사실 Object의 toString의 return 값만 놓고 보면 어플리케이션에서 별 값어치 없는 정보이다. 
하지만 toString을 오버라이딩한다면 이야기는 달라진다. 해당 객체의 값어치 있는 정보들을 출력하여 볼수 있다.
 예를 들어 java.util 패키지의 Date 클래스는 toString() 메소드를 재정의하여 현재 시스템의 날짜와 시간 정보를 리턴한다. 
 
 Object 객체와 Date 객체의 toString() 비교.
 ```java
 public class ToStirngExample {
     public static void main(String[] args) {
         Object obj1 = new Object();
         Date obj2 = new Date();
 
         System.out.println(obj1.toString());
         System.out.println(obj2.toString());
     }
 }
 // 실행 결과
 // java.lang.Object@74a14482
 // Thu Jun 13 20:36:53 KST 2019
 ```
 
 
 > 데이터의 정보를 출력하는 용도 
 
만약 좌표의 데이터(x,y)를 Point 라는 클래스에 담아서 전송할 때
받는 사람 입장에서는 x 값과 y값을 어떻게 확인 할까. 여러가지 방법이 있겠지만 
**toString을 사용하여 출력해 x,y값을 확인하는 방법이 있다. 
이는 데이터의 정체를 쉽게 파악하게 해주는 장점이 있으며, 많이들 사용하는 방법이다.**

Point 클래스
```java
public class Point {

    private final int x;
    private final int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String toString(){
        return "Point { " + "x=" + this.x +" , y= " +this.y +" }";
    }
}
```

PointExample
```java
public class PointExample {
    public static void main(String[] args) {
        int x = 1;
        int y = 2;
        Point point = new Point(x,y);
        System.out.println(point.toString());
    }
}
// 실행 결과 
// Point { x=1 , y= 2 }
```
 

