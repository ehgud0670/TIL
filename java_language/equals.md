## Object 상속

자바 플랫폼에서 모든 클래스는 Object클래스를 상속하고, 이 최상위 클래스가 equals() / hashCode() / toString() 를 가지고 있기 때문에 이를 상속하게 된다.<br>
(Primitive 타입은 해당 x) <br>

> equals

자바에서 '=='의 동작이 두가지이다.<br>
1. 원시 타입(primitive type)에 사용할 경우 두 피연산자의 값이 같은지 비교한다. (동등성 , equality)
2. 참조 타입(reference type)에 사용할 경우 두 피연산자의 주소가 같은지 비교한다. (참조 비교, reference comparision)

=> 그래서 자바에서 두 객체(객체는 reference type)의 동등성을 비교하기 위해서는 equals를 호출해야한다. 




