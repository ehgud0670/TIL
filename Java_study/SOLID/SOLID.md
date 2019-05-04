## SOLID 
## 객체지향 5대 원칙

* SOLID: 컴퓨터 프로그래밍에서 SOLID란 로버트 마틴이 2000년대 초반에 명명한 객체 지향 프로그래밍 및 설계의 다섯 가지 기본 원칙을 마이클 페더스가 두문자어 기억술로 소개한 것입니다. 프로그래머가 시간이 지나도 유지 보수와 확장이 쉬운 시스템을 만들고자 할 때 이 원칙들을 함께 적용할 수 있습니다. SOLID 원칙들은 소프트웨어 작업에서 프로그래머가 소스 코드가 읽기 쉽고 확장하기 쉽게 될 때까지 소프트웨어 소스 코드를 리팩토링하여 코드 냄새를 제거하기 위해 적용할 수 있는 지침입니다. 이 원칙들은 애자일 소프트웨어 개발과 적응적 소프트웨어 개발의 전반적 전략의 일부입니다.

SRP(Single Responsibility Principle)<br>
: 단일 책임의 원칙<br>
-> 모듈(변수, 함수, 클래스, 프로그램)은 <br>
단 하나의 책임을 가져야 한다.<br>

OCP(Open Close Principle)<br>
: 개방 폐쇄의 원칙<br>
-> 모듈은 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.<br>
  :새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.<br>

LSP(Liscov Substitution Principle)<br>
: 리스코프 치환 원칙<br>
-> 자식은 부모 클래스로 대체할 수 있어야 한다. <br>
  : 자식의 공통된 기능은 부모로부터 비롯되어야 한다.<br>
  => 상속의 목정은 다형성이다.<br>

ISP(Interface Segregation Principle)<br>
: 인터페이스 분리 원칙<br>
```java
MP3 : play() / playOneMinute()
-> iPod: play()
   iPhone: play()

class Person{

  void playMusic(Mp3 mp3){
    mp3.play();
	}
}
```
: 범용 인터페이스 보다는 세분화된 인터페이스가 좋다.<br>

DIP(Dependency Inversion Principle)<br>
: 의존관계 역전 원칙<br>
=> 클라이언트는 구체적인 타입에 의존하는 것이 아니라,<br>
  인터페이스나 추상 클래스에 의존해야 한다.<br>


