# chapter 8
## 인터페이스(interface)

### 인터페이스의 역할

* 인터페이스(interface)는 개발 코드와 객체가 서로 통신하는 접점 역할을 한다.

=> 개발 코드가 인터페이스의 메소드를 호출하면 **인터페이스는 객체의 메소드를 호출시킨다.**(그렇기 때문에 개발 코드는 객체의 내부 구조를 알 필요가 없고 인터페이스의 메소드만 알고 있으면 된다.)<br><br>
=> 개발 코드가 직접 객체의 메소드를 호출하면 간단한데, 왜 중간에 인터페이스를 두는 지 의문점이 생긴다. 하지만 **그 이유는 개발 코드를 수정하지 않고, 사용하는 객체를 변경할 수 있도록 하기 위해서이다.** 인터페이스는 하나의 객체가 아니라 **여러 객체들**과 사용이 가능하므로 어떤 객체를 사용하느냐에 따라서 **실행 내용과 리턴값**이 다를 수 있다.<br>
즉 개발 코드 측면에서는 **코드 변경 없이 실행 내용과 리턴값을 다양화할 수 있는 다형성적인 장점**을 가지게 된다.<br>


### 인터페이스 선언
```java
package Family;
// 클래스는 필드, 생성자, 메소드를 구성 멤버로 가지는데 비해,
// 인터페이스는 상수와 메소드만을 구성 멤버로 가진다.
// 인터페이스는 객체를 생성할 수 없기 때문에 생성자를 가질 수 없기 때문이다.

//자바 7 이전까지는 인터페이스의 메소드는 추상 메소드만 선언이 가능했지만,
// 자바 8 부터는 디폴드(default) 메소드 와 정적(static) 메소드도 선언이 가능하다.

public interface RemoteControl {

    // 상수 필드
    public int MAX_VOLUME =10;
    public int MIN_VOLUME = 0;


    // 추상 메소드
    public void turnOn();
    public void turnOff();
    public void setVolume(int volume); // 메소드 선언부만 작성(추상 메소드)

    // 디폴트 메소드
    default void setMute(boolean mute){
        if(mute) //true
            System.out.println("무음 처리합니다.");
        else
            System.out.println("무음 해제합니다.");
    }

    static void changeBattery(){
        System.out.println("건전지를 교환합니다.");
    }


}
```
> 상수 필드(Constant Field) 선언

* 인터페이스는 **객체 사용 설명서** 이므로 런타임 시 데이터를 저장할 수 있는 필드를 선언할 수 없다.**(객체를 생성할 수 없으므로)**
* 그러나 상수 필드는 가능하다. 상수는 인터페이스에 고정된 값으로 런타임시에 데이터를 바꿀 수 없다. **상수를 선언할 때에는 반드시 초기값을 대입해야 한다.**
* 상수는 public static final로 선언하는데, 인터페이스의 모든 필드는 상수 필드이므로 모두 public static final의 특성을 갖고, public,static,final 키워드를 생략하더라도 **자동적으로** 컴파일 과정에 붙게 된다. 

> 추상 메소드(Abstract Method) 선언

인터페이스를 통해 호출된 메소드는 최종적으로 객체에서 실행된다. 그렇기 때문에 인터페이스의 메소드는 실행 블록이 필요 없는 추상 메소드로 선언한다. 추상 메소드는 리턴 타입, 메소드명, 매개변수만 기술되고 중괄호 {}는 붙이지 않는 메소드를 말한다.<br> 

* 인터페이스에 선언된 추상 메소드는 모두 public abstract 의 특성을 갖고 있기 때문에 public abstract 를 생략하더라도 자동적으로 컴파일 과정에서 붙게 된다.

> 디폴트 메소드(Default Method) 선언

디폴드 메소드: 자바 8에서 추가된 인터페이스의 새로운 멤버로,
형태는 클래스의 인스턴스 메소드와 동일한데, default 키워드가 리턴 타입 앞에 붙는다.<br>

* 디폴드 메소드는 public 특성을 갖기 때문에 public 을 생략하더라도 자동적으로 컴파일 과정에서 붙게 된다.

> 정적 메소드(Static Method) 선언

정적 메소드: 정적 메소드도 자바 8부터 추가된 인터페이스의 새로운 멤버로,
형태는 클래스의 정적 메소드와 완전 동일하다.<br>

* 정적 메소드는 public 특성을 갖기 때문에 public 을 생략하더라도 자동적으로 컴파일 과정에서 붙게 된다.
* 정적 메소드의 특징: 필드를 사용하지 않고 인터페이스로서 호출한다. 

### 인터페이스 구현

* 개발 코드가 인터페이스 메소드를 호출하면 인터페이스는 객체의 메소드를 호출한다. 
* 객체는 인터페이스에서 정의된 **추상 메소드**와 동일한 메소드 이름, 매개 타입, 리턴 타입을 가진 실체 메소드를 가지고 있어야 한다. 
* 이러한 객체를 인터페이스의 구현(implement) 객체라고 하고, 구현 객체를 생성하는 클래스를 구현 클래스라고 한다. 

> 구현 클래스

=> 구현 클래스는 implements 키워드를 통해 인터페이스를 구현하고,
반드시 인터페이스의 추상 메소드를 오버라이딩하여 자신만의 실체 메소드로 코드를 입력해야 한다.<br>

```java
package Family;

public class Television implements RemoteControl {

    //필드
    int volume;

    @Override // 추상 메소드 turnOn()의 실체 메소드
    public void turnOn() {
        System.out.println("TV를 켭니다.");
    }

    @Override // 추상 메소드 turnOff()의 실체 메소드
    public void turnOff() {
        System.out.println("TV를 끕니다.");
    }

    @Override // 추상 메소드 setVolume의 실체 메소드
    public void setVolume(int volume) {
        if (volume > RemoteControl.MAX_VOLUME) {  //맥스 볼륨보다 현재 볼륨 설정이 큰 경우
            this.volume = RemoteControl.MAX_VOLUME;  // 맥스 볼륨으로 재설정
        } else if (volume < RemoteControl.MIN_VOLUME) { //민 볼륨보다 현재 볼륨 설정이 작은 경우
            this.volume = RemoteControl.MIN_VOLUME; // 민 볼륨으로 재설정
        }
        else {
            this.volume = volume;
        }
        System.out.println("현재 TV 볼륨: " + volume);
    }

}
```

> 익명 구현 객체
* 구현 클래스를 만들어 사용하는 것이 일반적이고, 클래스를 재사용할 수 있기 때문에 편리하지만, **일회성**의 구현 객체를 만들기 위해 소스 파일을 만들고 클래스를 선언하는 것은 매우 비효율적이다. 
* 따라서 자바는 소스 파일을 만들지 않고도 구현 객체를 만들 수 있는 방법을 제공하는데, 그것이 바로 **익명 구현 객체**이다. 
* 자바는 UI프로그래밍에서 이벤트를 처리하기 위해, 그리고 임시 작업 스레드를 만들기 위해 익명 구현 객체를 많이 사용한다. 또 자바 8에서 지원하는 **람다식**은 인터페이스의 구현 객체를 만들기 때문에(많이 사용하므로) 익명 구현 객체를 잘 익혀두자.

익명 구현 객체 <br>
```java
인터 페이스 변수 = new 인터페이스(){
  // 인터페이스에 선언된 추상 메소드의 실체 메소드 선언
};

```

```java
public class RemoteControlExample {
    public static void main(String[] args) {
        // 익명 구현 객체
        // 인터페이스 변수 = new 인터페이스(){...};
        RemoteControl Radio = new RemoteControl() {
            int volume;

            @Override
            public void turnOn() {
                System.out.println("라디오를 켭니다.");
            }

            @Override
            public void turnOff() {
                System.out.println("라디오를 끕니다.");
            }

            @Override
            public void setVolume(int volume) {
                if(volume > MAX_VOLUME){
                    this.volume = MAX_VOLUME;
                }else if(volume < MIN_VOLUME){
                    this.volume = MIN_VOLUME;
                }else{
                    this.volume = volume;
                }
                System.out.println("TV 볼륨: " + this.volume);
            }
        };
    }
}

```
> 다중 인터페이스 구현 클래스

* 인터페이스 A 와 인터페이스 B가 객체의 메소드를 호출할 수 있으려면 객체는 이 두 인터페이스를 모두 구현해야 한다.
* 자바는 중복 구현이 가능하도록 허용한다. 따라서 implement의 인터페이스를 중복되게 사용할 수 있다. 
* 다중 구현된 클래스는 **구현한 인터페이스들의 모든 추상 메소드**를 오버라이딩 해야한다.

```java
package Machine;

public class SmartTelevision implements RemoteControl, Searchable{
    int volume;
    //RemoteControl 의 추상 메소드들 : turnOn, turnOff, setVolume
    @Override
    public void turnOn() {
        System.out.println("TV를 켭니다.");
    }

    @Override
    public void turnOff() {
        System.out.println("TV를 끕니다.");
    }

    @Override
    public void setVolume(int volume) {
        if (volume > RemoteControl.MAX_VOLUME) {  //맥스 볼륨보다 현재 볼륨 설정이 큰 경우
            this.volume = RemoteControl.MAX_VOLUME;  // 맥스 볼륨으로 재설정
        } else if (volume < RemoteControl.MIN_VOLUME) { //민 볼륨보다 현재 볼륨 설정이 작은 경우
            this.volume = RemoteControl.MIN_VOLUME; // 민 볼륨으로 재설정
        }
        else {
            this.volume = volume;
        }
        System.out.println("현재 TV 볼륨: " + volume);
    }
    //Searchable 의 추상 메소드 search
    @Override
    public void search(String url) {
        System.out.println(url +"을 검색합니다.");
    }
}
```

### 인터페이스 사용
* 인터페이스 변수는 참조 타입이기 때문에 구현 객체가 대입될 경우 구현 객체의 번지를 저장한다. 
* 따라서 인터페이스 변수를 초기화할 때 new 연산자를 사용해야 한다.(new는 구현 객체의 주소값을 리턴한다.)
* 개발 코드에서 인터페이스는 클래스의 필드, 생성자 또는 메소드의 매개 변수, 생성자 또는 메소드의 로컬 변수가 될 수 있다. 

```java
package Machine;

public class MyClass {
    //필드로 인터페이스 사용
    RemoteControl rc = new Television();

    MyClass(){

    }
    //생성자로 인터페이스 사용  // MyClass mc = new Myclass(new Television());
    MyClass(RemoteControl rc){
        this.rc = rc;
    }

    void methodA(){
        //로컬 변수로 인터페이스 사용
         RemoteControl rc = new Audio();
    }

    // 함수의 매개변수로 인터페이스 사용  // mc.methodB(new Audio);
    void methodB(RemoteControl rc){

    }
}
```
> 추상 메소드, 디폴트 메소드, 정적 메소드 사용

* 추상 메소드와 디폴트 메소드는 구현 객체가 있어야만 호출이 가능하다.
* 정적 메소드는 구현 객체가 없이 호출 가능하고 인터페이스 이름으로서 호출하는 것이 원칙적이다. 

```java
package Machine;

public class RemoteControlExample2  {

    public static void main(String[] args) {
        RemoteControl rc =null; // 인터페이스 선언만 하는 것, null로 초기화하면 가능하다.

        rc = new Television();

        //추상메소드
        rc.turnOn();
        rc.turnOff();

        // 디폴드 메소드
        rc.setMute(true);

        // 정적 메소드 : 인터페이스 이름으로서 호출한다.
        RemoteControl.changeBattery();
    }
}
```
### 타입 변환과 다형성

* 요즘은 클래스의 상속보다는 인터페이스를 통해서 다형성을 구현하는 경우가 더 많다. 
* 인터페이스 타입에 어떤 구현 객체를 대입하느냐에 따라 실행 결과가 달라지는 걸 다형성적인 특성이 있다 한다.
```java
RemoteControl rc = new Television();
RemoteControl rc = new Audio();
```

* 인터페이스의 다형성의 특징: 사람이든 자동차는 움직일 수 있다. 그러나 둘은 클래스가 다르고 생물 대 기계라 상속도 불가능하다. 하지만 움직일 수 있다는 공통점을 이용하여 다형성을 나타낼 수 있지 않을 까? 여기서 나온게 **인터페이스의 다형성**이다. 만약 인터페이스의 이름이 Movable이라면 구현 객체가 사람도 될 수 있고, 자동차도 될 수 있다. 바로 이 경우 하나의 변수를 통해 다양한 객체를 이용할 수 있는 다형성의 성질을 이용 할수 있는 것이다. 

* 즉 클래스가 달라도, 클래스 상속의 관계가 아니더라도 인터페이스를 통해 다형성의 성질을 이용할 수 있고 이 개념은 매우 중요하다.  


> 객체 타입 확인(instanceof)
* 인터페이스도 클래스와 같이 instanceof연산자를 통해 인터페이스의 변수가 어떤 객체를 참조하고 있는 지 확인 할 수있다.
* 단 인터페이스 변수는 자신의 인터페이스로 객체를 구현할 수 없고, 인터페이스를 구현한 클래스들의 객체(구현 객체)를 대입받을 수 있다는 것을 명심하자.
(인터페이스 자체로는 객체를 만들 수 없다.)<br>
* new 연산자로 자신의 인터페이스를 호출하면 익명 구현 객체가 형성됨을 알자.

### 인터페이스 상속 : 인터페이스의 확장을 위해 생긴 개념.

* 인터페이스도 다른 인터페이스를 상속 할 수있다.
* 그리고 클래스와는 달리 다중 상속을 허용한다. 
* 자식 인터페이스를 구현한 클래스는 반드시 부모 인터페이스의 추상 메소드도 실체화 해야 한다. 

```java
package Machine;

public class A implements InterfaceA {
    @Override   //InterfaceA의 추상 메소드
    public void methodC() {

    }

    @Override// InterfaceA의 부모 인터페이스 RemoteControl 의 추상 메소드
    public void turnOn() {

    }

    @Override// InterfaceA의 부모 인터페이스 RemoteControl 의 추상 메소드
    public void turnOff() {

    }

    @Override// InterfaceA의 부모 인터페이스 RemoteControl 의 추상 메소드
    public void setVolume(int volume) {

    }

    @Override// InterfaceA의 부모 인터페이스 Searchable 의 추상 메소드
    public void search(String url) {

    }
}
```

### default 메소드와 인터페이스 확장

default 메소드는 구현 객체가 있어야 사용할 수 있는 개념인데 코드는 인터페이스에서 짜고 사용은 구현 객체가 하니 뭔가 어색해 보인다. 디폴트 메소드의 제대로 된 쓰임새에 대해 알아보자.<br>

> 디폴드 메소드의 필요성 

* 디폴드 메소드는 기존 인터페이스의 확장해서 새로운 기능을 추가하기 위해 생겨난 개념이다.
* 기존 인터페이스의 이름과 추상 메소드의 변경없이 디폴드 메소드만 추가하면 기존의 인터페이스를 구현한 객체는 디폴드 메소드가 추상 메소드가 아니기에 반드시 이 메소드를 오버라이딩 안해도 되고 따라서 컴파일 에러도 생기지 않는다. 
* 또 기존의 인터페이스를 구현한 객체 중 인터페이스에서 새로 추가한 기능을 넣을 수 없는 경우, 만약 새로운 기능이 추상 메소드라면 컴파일 에러가 나서 기능을 추가 할 수도 없다. 하지만 새로운 기능이 디폴드 메소드라면 해당 객체의 디폴드 메소드에 대한 실체화 의무가 없으므로 컴파일 오류가 안나므로 결국 인터페이스는 새로운 기능을 추가할 수 있게 된다.  

기존 인터페이스 <br>
```java
package DefualtMethod;

public interface MyInterface {

    void method1();

}
```
기존 구현 클래스 <br>
```java
package DefualtMethod;

public class Myclass implements MyInterface{

    @Override
    public void method1() {
        System.out.println("Myclass-method1()");
    }
}
```

수정 인터페이스<br>
```java
package DefualtMethod;

public interface MyInterface {

    void method1();
    
    default void method2(){
        System.out.println("default method");
    }
}
```
=> 디폴드 메소드가 생성된 거라 MyclassA는 해당 메소드를 오버라이딩 안해도 되고, 이는 컴파일 오류가 나지 않고 모두 정상작동함을 보여준다. MyclassA는 디폴드 메소드를 그냥 사용하면(혹은 오버라이딩 해도 되고)된다.<br>



> 디폴트 메소드가 있는 인터페이스 상속

부모 인터페이스에 디폴트 메소드가 정의되어 있을 경우, 자식 인터페이스에서 디폴트 메소드를 활용하는 방법은 다음 세 가지가 있다. 

일단, 부모 인터페이스<br>
```java
package Interface;

public interface ParentInterface {
    void method1(); // 추상 메소드

    //우리의 주인공 디폴트 메소드
    default void  method2(){

    }
}
```

* 디폴트 메소드를 단순히 상속만 받는다.
자식 인터페이스1<br>
```java
package Interface;

// case1: 부모의 디폴트 메소드, 단순히 상속받기
public interface ChildInterface1 extends ParentInterface{

    public static void main(String[] args) {
        ChildInterface1 ch = new ChildInterface1() {
            @Override
            public void method1() {

            }

        };

        ch.method2(); //부모의 디폴트 메소드를
        // 단순히 상속 받아 변수가 호출하여 사용하고 있다.
    }

}
```

* 디폴트 메소드를 재정의(Overriding)해서 실행 내용을 변경한다.
```java
package Interface;

//case2: 부모의 디폴트 메소드를 Overriding 하기
public interface ChildInterface2 extends  ParentInterface{

    @Override // 부모의 디폴드 메소드를 Overriding
    default void method2() {
        System.out.println("haha");
    }

    public static void main(String[] args) {
        ChildInterface2 ch2 = new ChildInterface2() {
            @Override
            public void method1() {

            }
        };
        ch2.method2();
    }
}
```

* 디폴트 메소드를 추상 메소드로 재선언 불가능하다. 컴파일에러 난다. (명심!)

