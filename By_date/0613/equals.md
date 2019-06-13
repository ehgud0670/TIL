## Object 클래스의 equals() 사용법


Object의 equals() 메소드
```java
 public boolean equals(Object obj) {
        return (this == obj);
    }
```

equals()

* equals() 메소드의 매개 타입은 Object인데 따라서 모든 객체가 매개값이 될 수 있다는 의미이다.
왜냐하면 Object 클래스가 최상위 타입(모든 클래스는 Object 클래스의 자식 클래스) 이므로 모든 객체는 
Object 타입으로 자동 타입 변환(Promotion)이 될 수 있기 때문이다. 

* Object 클래스의 equals() 메소드는 비교 연산자인 == 와 동일한 결과를 리턴한다.
즉 동일한 객체(동일한 주소값)면 true를, 다른 객체라면 false를 리턴한다.

* == 는 primitive 타입이면 값을 비교하고, reference 타입이면 객체의 번지를 비교한다. 
eqauls()는 primitive 타입에선 사용할 수 없고, reference 타입에서만 사용할 수 있다.


> equals() 오버라이딩하기.

=\> 자바에서는 두 객체를 동등 비교(논리적 비교)할 때 equals() 메소드를 흔히 사용한다.
equals() 메소드는 논리적으로 동등하면 true를, 논리적으로 동등하지 않으면 false를 리턴한다. 
논리적으로 동등하다는 것은 같은 객체이건 다른 객체이건 상관없이 특정한 기준에 의해 객체가 저장하고 있는 데이터가
 동일함을 뜻한다. 
 <br><br> **하지만 equals() 메소드를 통해 논리적 비교를 하려면 equals()를 
 오버라이딩하여 특정 기준을 세워 새로이 코드를 작성해야 한다.**
왜냐하면 Object 클래스의 equals() 자체가 == 와 같기 때문에 참조 비교(주소값 비교)를 하지 논리적 비교를 할 수 없기 때문이다.  
<br>따라서 equals()를 통해 논리적 비교를 하려면 오버라이딩하여 특정 기준을 세워 새로이 코드를 짜야 한다. 
애초에 그렇게 쓰라고 나온 메소드이기도 하다.    

String 의 equals() 
```java
 public boolean equals(Object anObject) {
        if (this == anObject) {
            return true;
        }
        if (anObject instanceof String) {
            String anotherString = (String)anObject;
            int n = value.length;
            if (n == anotherString.value.length) {
                char v1[] = value;
                char v2[] = anotherString.value;
                int i = 0;
                while (n-- != 0) {
                    if (v1[i] != v2[i])
                        return false;
                    i++;
                }
                return true;
            }
        }
        return false;
    }
```
=> 문자열 끼리의 논리적 비교를 하는 equals()이다. 
<br>주목할만 한 것은 <br>(1)논리적 비교를 하기 위해 오버라이딩 했다는 점, 
<br>(2) 두 문자열의 길이가 같지 않으면 false, 
<br>(3) 각 문자열의 첫번째 문자부터 비교하는데 같지 않으면 false,
<br>(4) 결국 while()문을 통과하면 true를 리턴한다는 점이다. 


<br>equals 를 오버라이딩 하지 않은 Member 클래스
```java
public class Member {
    private String id;

    Member(String id) {
        this.id = id;
    }
}
public class MemberExample {
    public static void main(String[] args) {
        Member member1 = new Member("Bob");
        Member member2 = new Member("Bob");
        Member member3 = new Member("Jason");

        System.out.println(member1.equals(member2));
        System.out.println(member1.equals(member3));

    }
}

// 실행 결과 
// false
// false
```
=\>  Member의 id 를 기준으로 논리적 비교를 하고 싶지만 equals()을 오버라이딩하지 않아
논리적 비교를 할 수 없다. 대신 참조 비교를 한다. 


<br>equals 를 오버라이딩한 Member 클래스
```java
public class Member {
    private String id;

    Member(String id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Member) {
            Member member = (Member) obj;
            return this.id.equals(member.id);
        }
        return false;
    }
}

public class MemberExample {
    public static void main(String[] args) {
        Member member1 = new Member("Bob");
        Member member2 = new Member("Bob");
        Member member3 = new Member("Jason");

        System.out.println(member1.equals(member2));
        System.out.println(member1.equals(member3));

    }
}
// 실행 결과
// true
// false
```