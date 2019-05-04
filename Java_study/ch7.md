# chapter7
## 상속(inheritance)

### 상속 개념

* 상속은 부모클래스의 멤버를 자식 클래스가 이용할 수 있음을 말한다. 부모클래스를 상위클래스라 부르기도 하고, 자식클래스를 하위클래스라 부르기도 한다. 
* 클래스는 **extends 부모클래스**를 통해 자식클래스가 될 수 있다. 

* 부모 클래스에서 private 접근 제한을 갖는 필드와 메소드는 상속 대상에서 제외된다.

```java 
public class A { // 부모 클래스
    int field1;
    void method1(){}

    public static void main(String[] args) {
       B b = new B(); 

       b.field1 = 10; // A로부터 물려받은 필드와 메소드
       b.method1();

       b.field2 ="김도형"; // B가 추가한 필드와 메소드.
       b.method2();
    }
}

class B extends A{ // 자식 클래스
    String field2;
    void method2(){}
}
```

### 클래스 상속 
* 다른 언어와는 달리 **자바는 다중 상속을 허용하지 않는다.** 즉 여러 개의 부모 클래스를 상속할 수 없다. 그러므로 extends 다음에는 단 하나의 부모클래스만 와야 한다. 


### 부모 생성자 호출

* 현실에서 부모 없는 자식이 있을 수 없듯이 자바에서도 **자식 개체를 생성하면, 부모 객체가 먼저 생성되고 자식 객체가 그 다음에 생성된다.** 아래 코드는 DmbCellPhone 객체만 생성하는 것처럼 보이지만, **사실은 내부적으로 부모인 Cellphone 객체가 먼저 생성되고**, DmbCellPhone 객체가 생성된다. 

```java
DmbCellPhone dmbCellPhone = new DmbCellPhone();
// 메모리 heap영역에서 DmbCellPhone 객체만 생성되는 게 아니라 부모 객체인 CellPhone 객체도 생성된다.

```

**모든 객체는 클래스의 생성자를 호출해야만 생성된다.( 클래스 객체 = new 클래스();)** 부모 객체도 예외는 아닌데 그럼 부모 객체를 생성하기 위해 부모 생성자는 어디에 호출될까? 바로 **자식 생성자의 맨 첫줄에 부모 생성자가 호출된다.** 예를 들어 DmbCellPhone 의 생성자가 명시적으로 선언되지 않았다면 컴파일러는 다음과 같이 기본 생성자를 생성해낸다.<br>

```java
public DmbCellPhone(){
  super(); // super();는 부모 객체의 생성자 호출을 의미한다.(자동적으로 생성된 것.)
  // 자식 생성자를 생략했든 , 명시적으로 선언했든 부모 생성자는 항상 자식 생성자의 맨 첫줄에 호출된다.(super())
}

```

* 만약 직접 자식 생성자를 선언하고 명시적(explicit)으로 부모 생성자를 호출하고 싶다면 다음과 같이 작성하면 된다.
```java
// 자식 생성자
자식 클래스(매개변수 선언){ 
  super(매개값,...); //명시적으로 부모 생성자 선언. 

}
```
=> **super(매개값,...)는 매개값의 타입과 일치하는 부모 생성자를 호출한다.** 만약 매개값의 타입과 일치하는 부모 생성자가 없다면 컴파일 오류가 발생한다.그리고 **super(매개값,...)은 반드시 자식 생성자의 첫줄에 위치해야 한다.**<br>
super(매개값,...)가 생략되면 컴파일러에 의해 super()가 자동적으로 추가되기 때문에 부모의 기본 생성자가 있어야 한다. 하지만 부모클래스에 기본 생성자가 없고 특정 생성자만 있다면 기본 생성자가 자동 생성 되지 않기 때문에 이 경우는 반드시 부모 클래스의 기본 생성자를 선언해야만 한다.<br>


### 메소드 재정의(Overriding)
상위 클래스가 가지고 있는 멤버변수가 하위 클래스로 상속되는 것처럼<br>
상위 클래스가 가지고 있는 메소드도 하위 클래스로 상속되어 하위 클래스에서
사용할 수 있다.<br>
하지만, 하위 클래스에서 상위 클래스의 메소드를 재정의해서 사용 할 수도 있다.<br>

==> 상속 관계에 있는 클래스 간에 같은 이름의 메소드를 정의하는 기술을 오버라이딩(Overriding)이라고 한다.<br>

```java
pulbic class Employee{

  String name;
  int age;
  
  //print() 메소드
  public void print(){
    System.out.prinln("사원의 이름은 " + this.name + "이고, 나이는 " +this.age + "입니다.");
	}
}

// Employee 상속
pulbic class Manager extends Employee{

  // 부모의 메소드를 재정의: Overriding
  @Override
  public void print(){
    System.out.prinln("매니저의 이름은 " + this.name + "이고, 나이는 " +this.age + "입니다.");
	}
}
```
> 부모 메소드 호출(super)

* 자식 클래스에서 부모 클래스의 메소드를 오버라이딩하게 되면, 부모 클래스의 메소드는 숨겨지고 오버라이딩된 자식 메소드만 사용한다. 이때 자식 클래스 내부에서 오버라이딩된 메소드를 사용할 상황이 발생하게 되는데 이런 경우 super 키워드를 사용하여 부모 클래스의 메소드를 사용하자.

```java
super.부모메소드();
```

부모 클래스 <br>
```java
public class Airplane {

  public void land(){
      System.out.println("착륙합니다");
  }
  public void fly(){
      System.out.println("일반비행합니다.");
  }
  public void takeOff(){
      System.out.println("이륙합니다.");
  }

}
```

자식클래스<br>
```java
public class SupersonicAirplane extends Airplane {

    private static final int NORMAL = 1;// 상수 NORMAL
    private static final int SUPERSONIC = 2;  // 상수 SUPERSONIC
    
    private int flymode = NORMAL;
    
    @Override
    public void fly() {
        if(flymode == SUPERSONIC){
            System.out.println("초음속 비행합니다.");
        }
        else
            //Airplane 객체의 fly() 메소드 호출
            super.fly();
    }
}
```

### final 클래스와 final 메소드
> 상속할 수 없는 final 클래스
* 클래스를 선언할 때 final 키워드를 class 앞에 붙이게 되면 이 클래스는 **최종적인 클래스**이므로 상속할 수 없는 클래스가 된다. 즉 final 클래스는 부모 클래스가 될 수 없어 자식 클래스를 만들 수 없다. 

```java
public final class 클래스{

}
// final class 는 곧 최종적인 클래스이므로 부모 클래스가 될 수 없고 따라서 자식 클래스를 만들 수 없다.
```

> 오버라이딩 할 수 없는 final 메소드 
* 메소드를 선언할때 final를 붙이게 되면 이 메소드는 최종적인 메소드가 되어 자식 클래스가 오버라이딩(재정의) 할 수 없게 된다.
=> 오버라이딩 자체를 할수 없고 결국 자식클래스는 부모클래스의 final 메소드를 그대로 사용할 수 밖에 없다. **(재정의 x!)**<br>

```java
public class Car {
    //field
    public int speed;
    
    //method
    public void speedUp(){
        speed+=1;
    }
    
    //final method   => 자식 클래스가 오버라이딩(재정의) 할 수 없다. 
    public final void stop(){
        System.out.println("차를 멈춤");
        speed=0;
    }
}
```

### protected 접근 제한자
* protected 접근제한자는 default 접근 제한자와 달리 다른 패키지여도 **자식클래스**이라면 **해당 대상(protected가 달린 필드 or 생성자 or 메소드)**에 접근 가능하다.
(default 접근 제한자는 다른 패키지라면 절대 접근할 수 없다.)<br>

* protected 는 필드와 생성자, 메소드 선언에 사용될 수 있다. (클래스 자체는 불가능하다.)

부모 클래스 의 필드, 생성자, 메소드 모두 protected 선언 <br>
```java
package test;

public class A {

    protected String field; //해당 필드는 다른 패키지에 자식클래스가 아니라면 사용할 수 없다.

    protected A(){ // 해당 생성자는 다른 패키지에 자식클래스가 아니라면 사용할 수 없다.

    }
    protected  void method(){ // 해당 메소드는 다른 패키지에 자식 클래스가 아니라면 사용할 수 없다.

    }
}
```


다른 패키지여도 자식 클래스라면 protected 접근 제한자에 접근 가능! <br>
```java
package q;

import test.A;

public class C extends A {
    public C(){
        super(); //(o)
        this.field = "value"; // (o)
        this.method(); //(o)
    }
}
```


### 타입 변환과 다형성

* 다형성이란 같은 타입이지만 실행 결과가 다양한 객체를 이용할 수 있는 성질을 말한다. 코드 측면에서 보면 다형성은 하나의 타입에 여러 객체를 대입함으로써 다양한 기능을 이용할 수 있도록 해준다. 

> 자동 타입 변환(Promotion)

```java
Cat cat = new Cat();
Animal animal = cat; // 자동 형 변환 (promotion)
```

* 부모 클래스 변수에 new 연산자로 자식 클래스를 대입하면 자동 형변환이 일어난다. 즉, 부모클래스에 자식 클래스를 대입하면 자동 형변환이 일어나는 것이다. 
* 부모클래스보다 자식클래스가 등급이 낮다. 데이터 형도 크기가 작은 것은 크기가 큰 자료형에 자동 형변환이 되는 것처럼 자식클래스도 부모클래스로 자동 형변환이 된다.
* 반대로 부모클래스는 자식 클래스 보다 높으므로 자식클래스에 부모 클래스를 대입할 수 없다.(컴파일 에러) 이 경우 강제 형변환(Casting) 하여 대입하여야 한다. 

* 부모 타입으로 자동 형 변환 된 이후 부모 클래스에 선언된 필드와 메소드만 접근이 가능하다. **단, 메소드가 자식 클래스에서 오버라이딩 되었다면 , 자식 클래스의 메소드가 대신 호출 된다.** 
=> 이는 다형성과 관련하여 매우 중요한 개념이므로 반드시 외우자. 이 기능 덕분에 부모 변수 animal 에 자식변수 cat을 대입하면 cat만의 오버라이딩 된 메소드를 사용할 수 있고 이후 자식변수 dog를 대입하면 dog만의 오버라이딩된 메소드를 사용할 수 있다. 즉 하나의 타입에 여러 객체를 대입함으로써 다양한 기능을 사용할 수 있는 다형성의 특성을 그대로 반영한 것이다. <br>

```java
package Family;

public class FamilyTest {
    public static void main(String[] args) {
        Parent parent = new Child(); // 자식클래스에서 부모 클래스로 자동형 변환 된다.

        parent.field = "xxx"; // 부모 클래스의 필드 호출.
        parent.method1();// 부모 클래스의 메소드 호출1.
        parent.method2();// 부모 클래스의 메소드 호출2.

        //parent.field2; 부모 클래스로 자동 형변환 된 것은 자식클래스의 필드와
        //parent.method3(); 메소드는 호출 불가능하다.
    }
}
```
> 하나의 배열로 객체 관리

* 같은 타입이면 배열로 관리 가능하다. 또 자식 클래스는 부모클래스로 자동 형변환 될 수 있기 때문에 배열 요소에 자식 객체를 대입할 수 있다. 
```java
Tire tires[4] = {
	new Tire(),
	new Tire(),
	new HankookTire(), //자식 객체인 new HankookTire() 대입 가능
	new KumhoTire()    //자식 객체인 new KumhoTire() 대입 가능
}
```

> 매개 변수의 다형성 
* 자동 타입 변환은 필드의 값을 대입할 때에도 발생하지만, **주로 메소드를 호출할 때 많이 발생한다.**
=> 메소드를 호출할때에는 매개 변수의 타입과 동일한 매개값을 지정하는 것이 정석이지만, 매개값을 다양화하기 위해(다형성) **매개변수에 자식 타입 객체를 지정할 수 도있다.**

```java
public class Driver{

	void drive(Vehicle vehicle){   // 메소드의 파라미터로 부모 객체인 vehicle 선언.
    vehicle.run();   
	}


public static void main(String[] args){
  Driver driver = new driver(); // driver 객체 생성
  
  Vehicle vehicle = new Vehicle(); // 자동차 중 부모 객체인 vehicle 생성.
  driver.drive(vehicle); //Driver 클래스의 drive 메소드의 파라미터와 driver 변수의 메소드 호출 시 인자와 class 가 같으므로 정상 작동.

  Bus bus = new Bus(); // 자동차 중 자식 객체인 bus 생성
  driver.drive(vehicle); // 인자와 파라미터의 class가 달라도 정상 작동한다.
  //=> 왜냐하면 인자가 자식 객체인 bus 이기 때문에 파라미터에 대입될 때 파라미터가 부모 객체인 vehicle이므로 자동 형 변환 되어
  // 아무런 문제 없이 정상 작동하는것이다. 그리고 이는 한 객체를 다양하게 사용할 수 있는 다형성의 특징을 보여준다.  
}
```

> 강제 타입 변환(Casting)

* 강제 타입 변환(Casting)은 부모 타입을 자식 타입으로 변환하는 것을 말한다.
* 만약 부모 객체로 자식 타입에 선언된 필드와 메소드를 꼭 사용해야 싶다면 Casting하여 자식 타입으로 변환 후 자식 타입의 필드와 메소드를 사용하자.  

```java
public class FamilyTest {
    public static void main(String[] args) {
        Parent parent  = new Parent();
        Child child = (Child)parent; // 이와같이 부모 객체를 자식 객체로 강제 형 변환 가능.

        child.field2 = "zzz"; //강제 형변환 하였으므로 child는 자식클래스의 필드인 field2와
        child.method3(); // method3() 호출 가능.
    }
}
```

> 객체 타입 확인: instanceof
* 다형성의 단점은 부모 변수가 참조하는 객체가 부모 객체인지 자식 객체인지 알 수 없다는 것이다. 그러니깐 부모 변수가 자동 형변환 된건지 부모 객체를 참조한 건지 모르고, 또 자동 형변환 되어도 어느 자식 객체로 자동 형변환되었는지 알 수 없는 것이다. 
* 이 단점을 극복하기위한 방법은 **instanceof**연산자가 있다. 이 연산자는 부모 변수가 어떤 객체를 참조하는 지 확인 시켜주는 연산자이다. 

```java
package Family;

public class Parent {
    String field;
    public void method1(Parent parent){
       if(parent instanceof Child){
           System.out.println("부모 변수는 Child 객체를 참조합니다. ");
       }
    }
}

public class FamilyTest {
    public static void main(String[] args) {
        Parent parent = new Child(); // 자식클래스에서 부모 클래스로 자동형 변환 된다.

        parent.method1(parent);// parent는 자식 객체를 참조하고 있으므로,
        // 위의 Parent 클래스의 method1에서 instanceof가 작동된다. 
        }
}
//=> 실행 결과: 부모 변수 Child 객체를 참조합니다. 
```

### 추상 클래스(Abstract Class)

* 객체를 실제로 생성 할 수 있는 클래스: 실체 클래스
* 객체를 직접 생성 할 수 없는 클래스: 추상 클래스
=> 추상 클래스: 체 클래스들의 **공통적인 특성**을 추출해서 선언한 클래스<br>

> 추상 클래스의 개념
사전적 의미로 추상(abstract)은 **실체 간에 공통되는 특성을 추출한 것**을 말한다. 예를 들어 새, 곤충, 물고기 등의 실체에서 공통되는 특성을 추출해보면 **동물**이라는 공통점이 있다. 또 다른 예로 삼성,현대,LG 등의 실체에서 공통되는 특성을 추출해보면 **회사**이라는 공통점이 있다. 이와같이 동물이나 회사는 실제로 존재하는 것이 아니라 실제의 공통된 특성을 추출한 상징이다. (인간, 동물, 건물 등등 모오두 추상이다.)<br>

클래스에도 추상 클래스가 존재하는 데, 객체를 직접 생성할 수 있는 클래스를 실체 클래스라 한다면 **이 클래스들의 공통적인 특성을 추출한 것**을 추상 클래스라 한다. 추상 클래스와 실체 클래스는 **상속의 관계**를 가지는데, 추상 클래스가 **부모**이고 실체 클래스가 **자식**으로 구현된다.
이 때 추상 클래스의 **모든 필드와 메소드는 실체 클래스들의 공통적인 것**들이고, 모든 실체 클래스들을 추상클래스의 모든 필드와 메소드를 물려받는다.<br>

추상 클래스는 실체 클래스의 공통되는 필드와 메소드를 추출해서 만들었기 때문에 **객체를 직접 생성할 수 없다.** 실체 클래스로 객체를 생성해야 한다. 또 추상 클래스로 변수는 입력하되, 실체 클래스로 객체를 대입(Promotion)하여도 된다.(다형성)<br>

> 추상 클래스의 선언 : 클래스 앞에 abstract 키워드를 붙여야 한다. 
```java
package ANIMAL;

// 추상 클래스는 앞에 abstract 키워드를 붙여야 한다.
public abstract class Animal {
    //필드
    public String kind;
    // 메소드
    public void breathe(){
        System.out.println("숨을 쉽니다.");
    }
    // 추상 클래스에서 선언되는 필드와 메소드는 모두 실체클래스들의
    // 공통적인 특성들을 추출한 것이다.
    // 모든 동물들은 종과 숨이 쉴 수 있기에 추상클래스에 선언가능한 것이다.
}

public class Dog extends Animal{
    
    public Dog(){
        this.kind = "포유류";
    }

 @Override // 추상클래스의 메소드도 오버라이딩(Overriding)이 가능하다.
    public void breathe() {
        System.out.println("개가 숨을 쉽니다.");
            }

    public static void main(String[] args) {
        Animal animal = new Dog(); // 추상 변수도 자동 형 변환가능.
        System.out.println(animal.kind);;
        animal.breathe();

    }
}
// 실행 결과:
//포유류
//개가 숨을 쉽니다. 
```

> 추상 메소드와 오버라이딩( 자동 형변환 & 다형성)
* 아무리 공통된 거라도, 메소드 중에는 메소드의 선언만 통일화하고, 실체 내용은 실체 클래스마다 달라야 하는 경우가 있다.
* 예를 들어 모든 동물은 소리를 내기 때문에 sound()라는 메소드를 공통적으로 선언할 수 있지만, 동물 마다 내는 소리가 다르기 때문에 실체 내용은 실체 클래스마다 달라야 한다. 
* 이 경우 추상 메소드에서 추상 메소드를 선언하여 메소드의 선언부만 있고 메소드의 실행 내용은 실체 클래스에서 오버라이딩할때 구체적으로 적도록 하여 해결 할 수있다.
(추상 메소드는 추상 클래스에서만 선언할 수 있다.)<br>


```java
package ANIMAL;

// 추상 클래스는 앞에 abstract 키워드를 붙여야 한다.
public abstract class Animal {
    public abstract void sound(); // 추상 메소드
    // 동물마다 내는 소리가 다르므로 이렇게 추상 메소드로 선언만 하고,
    // 실행 내용은 실체 클래스에서 오버라이딩(재정의) 하여  사용하도록 하자.

    public static void main(String[] args) {
        Animal animal = new Dog(); // 자동 형변환
        animal.sound();// "멍멍"
        
        animal = new Cat(); // 자동 형변환 
        animal.sound();// "야옹야옹"
    }
}

class Cat extends Animal{

    @Override
    public void sound() { //실체 클래스 Cat이 추상 클래스인 Animal 클래스의 추상 메소드 sound()를 재정의하여 구체적으로 코드를 짰다.  
        System.out.println("야옹야옹");
    }
}

class Dog extends Animal{

    @Override
    public void sound() { //실체 클래스 Dog가 추상 클래스인 Animal 클래스의 추상 메소드 sound()를 재정의하여 구체적으로 코드를 짰다.  
        System.out.println("멍멍");
    }
}
```



