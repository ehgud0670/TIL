# item 8
## finalizer 와 cleaner 사용을 피하라. 

* 자바에는 두 가지 객체 소멸자를 제공하는데, finalizer 와 cleaner 이다. 

<br>
> finalizer , cleaner 

=> 그 중 **finalizer는 예측할 수 없고, 상황에 따라 위험할 수 있어 일반적으로 불필요하다.**
오동작, 낮은 성능, 이식성 문제의 원인이 되기도 한다.
<br>finalizer는 나름의 쓰임새가 있지만 **기본적으로 '쓰지 말아야 하고'**, 따라서 자바 9에서는 
finalizer를 deprecated API로 지정하고 **cleaner를 그 대안으로 소개한다.**
(하지만 자바 라이브러리에서도 finalizer를 여전히 사용하는 코드가 있다.)
<br>**cleaner는 finalizer보다는 덜 위험하지만, 여전히 예측할 수 없고, 느리고, 일반적으로 불필요하다.** 

<br>
>  C++ 의 destructor(파괴자)

오해하지말기 
<br>=> 자바의 finalizer와 cleaner는 C++의 파괴자(destructor)와는 다른 개념이다. 
<br>C++에서의 파과자는 **(생성자의 꼭 필요한 대척점으로)** 특정 객체와 관련된 자원을 회수하는 보편적인 방법이다. 
<br>하지만 **자바에서는 접근할 수 없게 된 객체를 회수하는 역할을 GC가 담당하고, 프로그래머에게는 아무로 작업도 요구하지 않는다.**
또 C++의 파괴자는 비메모리 자원을 회수하는 용도로도 쓰이지만, **자바에서는 try-with-resources와 try-finally를 사용해 해결한다.**


> finalzier , cleaner 를 쓰지 않는 이유 

##### 1. finalizer와 cleaner가 즉시 수행된다는 보장이 없기 때문이다. 
GC가 실행되어야 finalizer와 cleaner가 호출이 되는데 GC가 언제 실행될지 모르므로, 따라서 finalizer와 cleaner도 언제 호출될지 모른다.
**따라서 finalizer와 cleaner로는 제때 실행되어야 하는 작업은 절대 할 수 없다.**
finalizer나 cleaner를 얼마나 신속히 수행할지 전적으로 **GC 알고리즘**에 달렸으며, 이는 GC 구현마다 천차만별이다.
  
* 또 **finalizer 스레드는 다른 어플리케이션 스레드보다 우선순위가 낮아서 실행될 기회를 제대로 얻지 못한다.**
일례로, 객체 수천개가 finalizer 대기열에서 회수되기만을 기다리다 프로그램이 OutOfMemoryError를 내며 죽는 경우가 있다. 

   => 자바 언어 명세는 어떤 스레드가 finalizer를 수행할지 명시하지 않으니 이 문제를 예방할 보편적인 해법은 없다. 

  
##### 2. finalizer 와 cleaner 의 수행 시점뿐 아니라 수행 여부조차 보장하지 않는다.
GC가 실행된다 해도 finalizer와 cleaner 의 수행을 절대 보장하지 않는 것을 의미한다.
즉 프로그램 동작 중에 finalizer 와 cleaner가 수행 조차 안할 수 있다는 것인데, 
접근할 수 없는 일부 객체에 딸린 종료 작업을 전혀 수행하지 못한채 프로그램이 중단될 수 있다는 얘기다. 
<br>따라서 프로그램 생애주기와 상관없는, **상태를 영구적으로 수정하는 작업에서는 절대 finalizer나 cleaner에 의존해서는 안된다.** 
예를 들어 데이터베이스 같은 공유 자원의 영구 락(lock) 해제를 finalizer나 cleaner에 맡겨 놓으면 분산 시스템 전체가 서서히 멈출 것이다.
<br>또 System.gc 와 같은 메서드에 현혹되지말자. finalizer와 cleaner가 실행될 가능성을 높여줄 수는 있으나, **보장해주진 않는다.**
 
##### 3. finalizer 동작 중 발생한 예외는 무시되며, 처리할 작업이 남았더라도 그 순간 종료된다. 
=> 잡지 못한 예외 때문에 해당 객체는 자칫 마무리가 덜 된 상태로 남을 수 있다. 
그리고 다른 스레드가 이처럼 훼손된 객체를 사용하려 한다면 어떻게 동작할지 예측할 수 없다. 
<br>그나마 cleaner를 사용하는 라이브러리는 자신의 스레드를 통제하기 때문에 이러한 문제를 

##### 4. finalizer와 cleaner는 심각한 성능 문제도 동반한다. 

=> try-with-resources를 써서 AutoCloseable 객체를 생성하고 GC가 수거하기까지 12ns가 걸린 반면,
finalizer를 사용하면 550ns가 걸렸다. finalizer가 GC의 효율을 떨어뜨리기 때문이다. 
cleaner(500ns)도 성능은 finalizer와 비슷했지만 안전망 형태로 사용하면 66ns 가 걸렸다.
<br>(안전망을 설치하는 대가로 성능이 약 5배 정도 느려졌다는 뜻이다.)

##### 5. finalizer를 사용한 클래스는 finalizer 공격에 노출되어 심각한 보안 문제를 일으킬 수도 있다. 

=> finalizer 의 공격 원리는 간단하다, 생성자나 직렬화 과정에서 예외가 발생하면, 이 생성되다 만 객체에서 
악의적인 하위 클래스의 finalizer가 수행할 수 있게 된다. 이 finalizer는 정적 필드에 자신의 참조를 할당하여 
GC가 수집하지 못하게 막을 수 있다. 또 이 객체의 메서드를 호출해 애초에는 허용되지 않았을 작업을 수행할 수 있는 건 일도 아니다.  
<br>**해결책으로는** final 클래스들은 그 누구도 하위 클래스를 만들 수 없으니 final 클래스로 만든다. 
또는 final이 아닌 클래스를 finalizer 공격으로부터 방어하려면 아무 일도 하지 않는 finalize 메소드를 만들고 final로 선언하자.


> finalizer 와 cleaner 을 대신할 해결책

=> AutoCloseable을 구현해주고, 클라이언트에서 인스턴스를 다 쓰고 나면 close 메소드를 호출하면 된다.
그리고 **try - with - resources 을 사용하는 것이 일반적이고 이롭다.**

* 구체적인 구현법과 관련하여 알아두면 좋을게 하나 있다. **각 인스턴스는 자신이 닫혔는지를 추적하는 것이 좋다.**
<br>**다시 말해, close 메서드에서 이 객체는 더 이상 유효하지 않음을 필드에 기록하고, 
다른 메서드는 이 필드를 검사해서 객체가 닫힌 후에 불렸다면 IllegalStateException을 던지는 것이다.**

예시 
```java
public class CloseEx implements AutoCloseable{
    private boolean closed;
    
    @Override public void close() throws Exception {
        if(this.closed){ // 자원이 close 된 경우라면 
            throw new IllegalStateException();
        }
        this.closed = true;
    }
    
    void printHello(){
        if(this.closed){ // 자원이 close 된 경우라면. 
            throw new IllegalStateException();
        }
        System.out.println("hello");
    }
    
}
```

> 그렇다면 과연 cleaner 와 finalizer 는 대체 어디에 사용해야 할까?
##### 1. Finalizer와 Cleaner를 안전망으로 쓰기

자원 반납에 쓸 close 메소드를 클라이언트가 호출하지 않았다는 가정하에, 
물론 실제로 Finalizer나 Cleaner가 호출될지 안될지 언제 호출될지도 모르긴 하지만, 
안하는 것 보다는 낫다. 실제로 자바에서 제공하는 FileInputStream, FileOutputStream, ThreadPoolExecutor 
그리고 java.sql.Connection에는 안전망으로 동작하는 finalizer가 있다.

안전망으로 쓰는 finalizer 
```java 
   // note : 안전망 삼아서 finalize()에서 한번 더 close()를 호출한다.
    @Override
    protected void finalize() throws Throwable {
        if (!this.closed) {
            close();
        }
    }
```

cleaner 를 안전망으로 활용하는 AutoCloseable 클래스
```java
public class Room implements AutoCloseable{
    private static final Cleaner cleaner = Cleaner.create();
    
    // 청소가 필요한 자원. 절대 ROOM을 참조해서는 안된다!
    private static class State implements Runnable{
        int numJunkPiles; // 방(Room) 안의 쓰레기 수
        
        State(int numJunkPiles){
            this.numJunkPiles = numJunkPiles; 
        }
        
        // close 메서드나 cleaner가 호출한다. 
        @Override public  void run(){
            System.out.println("방 청소");
            numJunkPiles = 0; 
        }
    }
    
    // 방의 상태. cleanable과 공유한다. 
    private final State state;
    
    // cleanable 객체. 수거 대상이 되면 방을 청소한다. 
    private final Cleaner.Cleanable cleanable;
    
    public Room(int numJunkPiles){
        state = new State(numJunkPiles);
        cleanable = cleaner.register(this,state);
    }
    
    @Override public void close(){
        cleanable.clean();
    }
}
```
```java
public class Adult{
    public static void main(String[] args){
      // try - with - resource 사용. 
        try(Room room = new Room(7)){
          System.out.println("안녕~");
      }
    }
}
```
=> try-with-resources를 쓴 경우로  close()가 먼저 호출되고, 안에 있는
cleaner의 clean()이 호출된다. "안녕"을 출력한 후 "방 청소"을 출력한다. 

```java
public class Teenager {
    public static void main(String[] args){
      new Room(99);
      System.out.println("아무렴");
    }
}
```
=> close()가 호출되지 않는 경우로 "방청소"가 출력되는 것이 보장되지 않는다. 
cleaner는 호출되지 않을 수 있기 때문이다. 다음은 cleaner의 명세에 적혀있는 것이다.

* System.exit 을 호출할 때의 cleaner 동작은 구현하기 나름이다. 청소가 이뤄질지는 보장하지 않는다.
 
=> 프로그램이 종료될때 cleaner의 동작은 보장되지 않는다. 보장되지 않는다면, 
따라서 프로그램 종료되기전 GC가 객체를 회수하는 것이 아닌 프로그램이 종료되었으니 
객체들이 소멸되는 경우가 된다. 
<br>=> 또 System.gc()를 추가하는 것으로 종료전에 cleaner을 호출할 수 있었지만, 이 또한 보장되지 않는다. 
<br>

##### 2. 네이티브 피어 정리할 때 쓰기 

```java
자바 클래스 -> 네이티브 메소드 호출 -> 네이티브 객체 (네티이브 Peer)
```

=> 네이티브 객체는 일반적인 객체가 아니라서 GC가 그 존재를 모른다. 
네이티브 피어가 들고 있는 리소스가 중요하지 않은 자원이며, 성능상 영향이 크지 않다면 Cleaner나 Finalizer를 사용해서 
해당 자원을 반납할 수도 있을 것이다. 하지만, 중요한 리소스인 경우에는 위에서 언급한대로 close 메소드를 사용하는게 좋다.


  







