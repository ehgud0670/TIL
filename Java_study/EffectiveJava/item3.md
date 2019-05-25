# item 3 
## private 생성자나 enum 타입으로 싱글턴임을 보증하라.

> 싱글턴이란?

* 싱글턴(singleton)이란 인스턴스를 오직 하나만 생성할 수 있는 클래스를 말한다. 

### 싱글턴 만드는 방식 

* 싱글턴을 만드는 방식은 두가지이다. 두 방식 모두 생성자를 **private 접근 제한자**로 감춰두고, 유일한 인스턴스에 접근할 수 있는 수단으로 **public static 멤버**를 하나 마련해둔다. 
<br>
<br>

### 방식 1: public static final 필드
public static final 필드 방식의 싱글턴<br>
```java
public class Elvis {
	public static final Elvis INSTANCE = new Elvis();

	// 생성자는 private 으로 감춰둔다. 
	private Elvis() {
	}

	public void leaveTheBuilding() {

	}

}
```
=> private 생성자는 public static final 필드인 Elvis.INSTANCE를 초기화할 때 딱 한 번만 호출된다.(static final 필드가 컴파일 타임 상수이므로)<br>
=> public이나 protected 생성자가 없으므로 Elvis 클래스가 초기화될 때 만들어진 인스턴스가 전체 시스템에서 하나뿐임을 보장하지만 예외는 단 한가지, 권한이 있는 클라이언트는 **리플렉션 API인 AccessibleObject.setAccessible을 사용해** private 생성자를 호출할 수 있다. <br>


public staic final 필드 예제<br>
AccessibleObject.setAccessible  예제<br>
```java 
public class ElvisExample {
	public static void main(String[] args) throws Exception {
		// Elvis elvis = new Elvis(); new 연산자는 생성자가 private 이므로 사용할 수 없다 => 컴파일 오류 

		Elvis elvis = Elvis.INSTANCE; // 사용 예시 

		Constructor<Elvis> constructor = Elvis.class.getDeclaredConstructor();
		constructor.setAccessible(true);
		Elvis elvis2 = constructor.newInstance();
		//setAccessible에 true를 매개변수로 주면 constructor.newInstance()를 통해 private 생성자를 호출 할 수 있다.
	}
}
```
=> setAccessible를 통한 private 생성자 참조를 막으려면 생성자를 수정하여 **두 번째 객체가 생성되려 할 때 예외를 던지게 하면 된다.**<br>

예외를 던져서 setAccessible 방어하기<br>
```java

private static int count;

private Elvis(){
	count++;
	if(count>1){
    throw new IllegalStateException("this object should be singleton");

	}
}
```
=> 이런식으로 짜면 private 생성자가 두 번 이상 호출되면 IllegalStateException이 발생하므로 setAccessible(true)에 대하여 방어할 수 있다. <br>
<br>
방식 1, public static final 필드의 장점:<br>

1. 해당 클래스가 싱글턴임이 API에 명백히 드러난다. **public static 필드가 final이라서 절대로 다른 객체를 참조할 수 없다.**<br>
2. 간결하다. 


### 방식 2: 정적 팩터리 방식의 싱글턴 

```java
public class Elvis{
  private static final Elvis INSTANCE = new Chet();
  private Elvis(){
	}
	public static Elvis getInstance() {
		return INSTANCE;
	}

  public void leaveTheBuilding(){
	}
}
```
```java
public class ElvisExample {

    public static void main(String[] args) {
        //Elvis chet = new Chet();
        Elvis chet = Chet.getInstance();

    }
}
```

방식 2, 정적 팩터리 방식의 장점: <br>

1. API를 바꾸지 않고도 싱글턴이 아니게 변경할 수 있다. 


```java
public static Elvis getInstance(){
	return new Elvis();
}
```
이렇게 바꿔주면 API를 바꾸지 않아도 싱글턴이 아니게 변경할 수 있다. 예를 들어 , 유일한 인스턴스를 반환하던 팩터리 메서드가 코드를 수정하면 스레드별로 다른 인스턴스를 넘겨주게 할 수 있다.<br>

2. 원한다면 제네릭 싱글턴 팩터리로 만들 수 있다는 점이다. 
=> 물어보기 <br>

```java
public static <E> Elvis<E> getInstance(){
	return new Elvis<>();
}
```

3. 정적 팩터리의 메소드 참조를 공급자(supplier)로 사용할 수 있다는 점이다. 

> supplier란?

인터페이스로서 싱글 메서드를 하나만 가지고 있다.<br>
싱글 메서드는 get()으로 타입 파라미터 T를 반환한다.<br>

```java
 Supplier<Elvis> supplier = Chet::getInstance;
```

### 직렬화

위의 두 방식 중 하나로 만든 싱글턴 클래스를 **직렬화**하려면 단순히 Serializable을 구현한다고 선언하는 것만으로는 부족하다. 모든 인스턴스 필드를 **일시적(transient)**으로 선언하고 **readResolve 메서드**를 제공해야 한다. 이렇게 하지 않으면 직렬화된 인스턴스를 역직렬화할 때마다 새로운 인스턴스가 만들어진다.<br> 

새로운 인스턴스를 만들고 싶지 않다면, 클래스에 다음의 메서드를 추가하자.<br>

```java
//싱글턴임을 보장해주는 readResolve 메서드
private Object readResolve() {
  // '진짜' Elvis를 반환하고, 가짜 Elvis는 가비지 컬렉터에 맡긴다.
  return INSTANCE;
}
```

### 열거(Enum) 타입

열거 타입 방식의 싱글턴 - 바람직한 방법<br>
```java
public enum Elvis {
 INSTANCE;

 public void leaveTheBuilding() {
 }
```
=> enum은 심지어 필드와 메소드를 가질 수 있어 더 바람직하다.<br>
=> public 필드 방식과 비슷하지만, 더 간결하고, 추가 노력없이 직렬화할수 있고, **심지어 아주 복잡한 직렬화 상황이나 리플렉션 공격에서도 제2의 인스턴스가 생기는 일을 완벽히 막아준다.** <br>
=> 코드가 좀 불편하게 느껴질 수 있지만 싱글톤을 구현하는 최선의 방법이다. 하지만 이 방법은 Enum 말고 다른 상위 클래스를 상속해야 한다면 사용할 수 없다. (Enum이 다른 인터페이스를 구현하도록 선언할 수는 있다.) <br>



