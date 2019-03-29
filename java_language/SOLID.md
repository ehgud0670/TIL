## SOLID
## 객체지향 설계 5대 원칙

### SRP(Single Responsibility Principle)
: 단일 책임의 원칙 <br>
-> 모듈(변수, 함수, 클래스, 프로그램)은<br> 
  : 단 하나의 책임을 가져야 한다. <br>

### OCP(Open Close Principle)
: 개방 폐쇄의 원칙 <br>
-> 모듈은 수정에는 닫혀있고, 확정에는 열려 있어야 한다. <br>
  : 새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다. <br>

### LSP(Liskov Substitution Principle)
: 리스코프의 치환 원칙<br>
-> 자식은 부모 클래스로 대체할 수 있어야 한다. <br>
  : 자식의 공통된 기능은 부모로부터 비롯되어야 한다.<br>
   => 상속의 목적은 다형성이다. <br>

### ISP(Interface Segregation Principle)
:인터페이스 분리 원칙<br>
```java
 MP3: play() / playOneMinute()
 
 -> iPod: play() 
   iPhone: play() 
 
 class Person{ 
   void playMusic(Mp3 mp3){
   	 mp3.play();
	 }
 }
```
: 범용 인터페이스 보다는 세분화된 인터페이스가 좋다.<br>


### DIP(Dependency Inversion Priciple)
: 의존관계 역전 원칙<br>
=> 클라이언트는 구체적인 타입에 의존하는 것이 아니라,<br>
   인터페이스나 추상 클래스에 의존해야 한다.<br>
