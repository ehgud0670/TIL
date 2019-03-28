# chapter9
## 중첩 클래스와 중첩 인터페이스 (inner class , inner interface)

### 중첩 클래스와 중첩 인터페이스란?
* 어떤 클래스가 특정 클래스와 관계를 맺을 경우에는, 관계 클래스를 클래스 내부에 선언하는 것이 좋다. 중첩 클래스(Nested class)란 **클래스 내부에 선언한 클래스를 말한다.**
* 중첩 클래스를 사용하면 **두 클래스의 멤버들을 서로 쉽게 접근 할 수 있다**는 장점과 **외부에는 불필요한 관계 클래스를 감춤으로써** 코드의 복잡성을 줄 일 수있는 장점이 있다.**(Encapsulatioin)**

* 중첩 인터페이스도 마찬가지로 클래스 내부에 선언할 수 있다. 

중첩 클래스 <br>
```java
class ClassName{
  class NestedClassName{ // 중첩 클래스
  }
}
```
중첩 인터페이스 <br>
```java
class ClassName{
	interface NestedinterfaceName{ //중첩 인터페이스
	}
}
```


### 중첩 클래스
중첩 클래스는 클래스 내부에 선언되는 위치에 따라서 두 가지로 분류된다.<br>
* 클래스의 멤버로서 선언되는 중첩 클래스 : 멤버 클래스라 칭한다.
* 메소드 내부에서 선언되는 중첩 클래스: 로컬 클래스라 칭한다.

| 선언 위치에 따른 분류|    | 선언 위치 | 설명                         |
|----------------------|----|-----------|------------------------------|
| 멤버 클래스|인스턴스 멤버 클래스| class A {  class B{}} | A객체를 생성해야만 사용할 수 있는 B 중첩 클래스|
|   | 정적 멤버 클래스 | class A { static class B{}}      | A 클래스 이름을 통해 바로 접근 할 수 있는 B 중첩 클래스 | 
|  로컬 클래스 |     |   class A{ void method(){class B{}}} | method()가 실행(호출)되어야만 사용할 수 있는 B 중첩 클래스 | 

> 인스턴스 멤버 클래스
* 생성자, 인스턴스 필드 선언 가능, 인스턴스 메소드 선언 가능, **정적 필드 선언 불가능, 정적 메소드 선언 불가능.**

```java
package ABC;

public class A {
    /* 인스턴스 멤버 클래스 */
    class B{
        int a;
        //static int b; 정적 필드 선언 불가능
        
        //생성자
        B(){ 
				}
        
        void method1(){
            
        }
        /* 정적 메소드 선언 불가능 
        static void method2(){
            
        }
        */
    }
}
```
> 정적 멤버 클래스
* 인스턴스 필드, 메소드, 정적 필드, 메소드 모두 선언 가능. 

```java
package ABC;

public class A {
    /* 정적 멤버 클래스 */
    static class C{
        int a;
        static int b; //정적 필드 선언 가능
        
        //생성자
        C(){

				}
        
        void method1(){

        }
        //정적 메소드 선언 가능
        static void method2(){

        }

    }
}
```

> 로컬 클래스
* 로컬 클래스는 클래스의 메소드가 호출되어야만 사용할 수 있고 메소드 안에서만 적용이 되는 중첩 클래스이기 때문에 접근 제한자(public,private)를 붙일 수 없고(필드,메소드는 가능), static 도 붙일 수 없다. (static은 오직 static 멤버 클래스 만! 메소드를 호출하고 static을 쓰는 것도 웃기다.-> 당연히 안된다.)
* 로컬 클래스 내부에는 인스턴스 필드와 메소드만 선언 가능하고 정적 필드와 메소드는 선언 불가능하다. 


### 중첩 클래스의 접근 제한

> 바깥 필드와 메소드에서 사용제한

* 인스턴트 멤버 클래스는 객체로서 정적 필드로 초기화될 수 없 정적 메소드 안에서 객체로서 생성될 수 없다.
* 정적 멤버 클래스 다 적용가능하다. (인스턴트 필드,메소드, 정적 필드,메소드)

```java
package ABC;

public class A {
      //인스턴트 필드
      B field1 = new B(); //(o)
      C field2 = new C(); //(o)

      // 인스턴트 메소드
      void method1(){
          B var1 = new B(); //(o)
          C var2 = new C(); //(o)
      }

      //정적 필드
      //static B field3 = new B(); (X)
      C field4 = new C(); // (O)

      // 정적 메소드
      static void method2(){
          //B var1 = new B(); (X)
          C var2 = new C(); //(O)
      }

      //인스턴트 멤버 클래스
      class B{}

      // 정적 멤버 클래스
      static class C{} 
}
```
> 멤버 클래스에서의 사용제한
* 인스턴스 멤버 클래스에서는 모든 바깥클래스의 인스턴스 필드, 메소드, 정적 필드, 메소드가 사용가능하다.
* 정적 멤버 클래스에서는 바깥 클래스의 정적 필드와 메소드만 사용가능하고 **인스턴스 필드와 인스턴스 메소드는 사용 불가하다.**

인스턴스 멤버 클래스 <br>
```java
package ABC;

public class A {
      int field1;
      void method1(){

      }

      static int field2;
      static void method2(){

      }

      // 인스턴트 멤버 클래스
      class B{

          void method(){
              field1 = 10;//(o)
              method1(); //(o)

              field2 =5; //(o)
              method2(); // (o)
          }

      }
}

```

정적 멤버 클래스 <br>
```java
package ABC;

public class A {
      int field1;
      void method1(){

      }

      static int field2;
      static void method2(){

      }

      // 인스턴트 멤버 클래스
      static class C{

          void method(){
              //field1 = 10;//(X)
              //method1(); //(X)

              field2 =5; //(o)
              method2(); // (o)
          }
      }
}

```


> 로컬 클래스에서의 사용제한
...<br>

### 중첩 인터페이스

```java
package Click;

public class Button {

    OnClickListener listener; // 인터페이스 타입 필드

    void setOnClickListener(OnClickListener listener){  // 매개변수의 다형성
       this.listener = listener;
    }

    void touch(){
        listener.onClick();
    }
    interface OnClickListener{
        void onClick(); //추상 메소드
    }
}
```

```java
package Click;

public class ButtonExample {
    public static void main(String[] args) {
       Button button = new Button();
       button.setOnClickListener(new Button.OnClickListener() {
           @Override
           public void onClick() {
               System.out.println("버튼을 클릭합니다.");
           }
       });

       button.touch();
    }
}
```

### 익명 객체 




