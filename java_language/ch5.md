# chapter5
## 참조 타입 (reference type)

프로그램이 하는 일은 결국 데이터를 처리하는 것이다. 따라서 데이터를 얼마나 잘 다루느냐가 좋은 프로그램을 작성<br>
할 수 있는 관건이 된다. 데이터를 잘 다루기 위해서는 자바에서 지원하는 데이터 타입에 대해서 반드시 이해하고 외워야 한다. <br>

* 자바의 데이터 타입은 원시타입(Primitive Type)과 참조타입(Reference Type)이 있다.

| 원시 타입(primitive type) |        |
|---------------------------|--------|
| 정수 타입 | byte   |
|           | char   |
|           | short  |
|           | int    |
|           | long   |
| 실수 타입 | float  |
|           | double |
| 논리 타입 | boolean | 

| 참조 타입(reference type) |
|---------------------------|
| 배열 타입  |
| 열거 타입  |
| 클래스     |
| 인터페이스 |

* 원시 타입으로 선언된 변수와 참조 타입으로 선언된 변수의 차이점: 저장되는 값이 무엇이냐.
=> 원시 타입인 byte, char, short, int , long, float, double, boolean을 이용해 선언한 변수에는 실제 값이 저장됨.<br>
=> 참조 타입인 배열, 열거, 클래스, 인터페이스을 이용해 선언한 변수는 메모리의 번지(주소)를 값으로 갖는다. (포인터와 같다)<br>

```java
//[기본 타입 변수]
int age = 25;
doulbe price = 50.57;

//[참조 타입 변수]
String name = "신용권";
String hobby = "독서";
```

|스택 영역 | 저장된 값|
|----------|----------|
| name     |  100     |
| hobby    |  200     |
| age      |  25      |
| price    |  50.57   |

|힙 영역 | 주소값 |
|--------|--------|
| 신용권| 100   |
| 독서  | 200   |

=> primitive 타입 변수인 age,price는 직접 값을 저장하고 있지만, reference type 변수인 name, hobby는 각각 문자열 리터럴인 "신용권"과 "독서"의 주소값을 가리키고 있음을 알 수 있다. <br> 
따라서 자바는 c와 달리 reference type인 경우 포인터가 따로 필요가 없음을 알 수 있다. <br>

## JVM의 메모리 사용 영역

1. 메소드(Method) 영역
메소드 영역에는 코드에서 사용되는 클래스(.class)들을 클래스 로더로 읽어 <br>
클래스 별로 런타임 상수풀(runtime constant pool), 필드(field)/ 메소드(method) 데이터, 메소드(method) 코드, 생성자(constructor) 코드 등을 <br>
분류해서 저장한다.<br>

* 메소드 영역은 JVM이 시작할 때 생성되고 모든 스레드가 공유한다.

2. 힙(Heap) 영역
* 힙 영역은 객체와 배열이 생성되는 영역이다. 
힙 영역에 생성된 객체와 배열은 JVM 스택 영역의 변수나 다른 객체의 필드에서 참조한다.<br>
참조하는 변수나 필드가 없다면 의미 없는 객체가 되기 때문에 이것을 쓰레기로 취급하고 JVM은 Garbage Collector 를 실행시켜 쓰레기 객체를
힙 영역에서 자동으로 제거한다.<br>
따라서 개발자는 객체를 제거하기 위해 별도의 코드를 작성할 필요가 없다.(사실 자바는 코드로 객체를 직접 제거시키는 방법을 제공하지 않는다.) <br>


3. JVM 스택(Stack) 영역
JVM 스택 영역은 **각 스레드마다 하나씩 존재하며 스레드가 시작될 때 할당**된다.<br>
(자바 프로그램에서 추가적으로 스레드를 생성하지 않았다면 main 스레드만 존재하므로 JVM 스택도 하나이다.) <br>
JVM 스텍은 메소드를 호출할 때마다 **프레임(Frame)을 추가(push)하고, 메소드가 종료되면 프레임을 제거(pop)한다.** <br>
예외 발생 시 printStackTrace() 메소드로 보여주는 Stack Trace의 각 라인은 하나의 프레임(하나의 메소드)을 표현한다. <br>
프레임 내부에는 로컬 변수 스택이 있는데, 기본 타입 변수와 참조 타입 변수가 추가(push)되거나 제거(pop)된다.<br>
**변수가 이 영역에 생성되는 시점은 초기화 될 때, 즉 최초로 값이 저장될 때이다. 또 변수는 선언된 블록 안에서만 스택에 존재하고 블록을 벗어나면 스택에서 제거된다.**

예제 <br>
```java
(1)char v1 = 'A';

(2)if(v1 =='A'){
  int v2 = 10;
  double v3 = 0.7;
}

(3)boolean v4 = true;

```
=> 이 코드의 지역 변수의 생성(push)과 제거(pop)과정. <br>

(1)<br>

| 스택 변수 | 값|
|-----------|---|
| v1 | 'A'|

(2)<br>

| 스택 변수 | 값|
|-----------|---|
| v3 | 0.7 |
| v2 | 10  |
| v1 | A   |

(3)<br>

| 스택 변수 | 값|
|-----------|---|
| v4  | true|
| v1 | 'A'|


printStackTrace()의 예제 <br>
```java
public class NULLexception {
    public static void main(String[] args) {
        printStack();

    }
    public  static void printStack(){
        try {
            String data = null;
            System.out.println(data.toString());
        }
        catch (NullPointerException e ){
            e.printStackTrace();
        }
    }
}

//실행 결과 
//java.lang.NullPointerException
//	at NULLexception.printStack(NULLexception.java:9)  => 하나의 프레임(메소드)을 나타냄. printStack
//	at NULLexception.main(NULLexception.java:3)       => 하나의 프레임(메소드)을 나타냄. main

```

## 참조 변수의 ==,!= 연산
기본 타입 변수의 ==, != 연산은 변수의 값이 같은지, 아닌지를 조사하지만 <br>
**참조 타입 변수들 간의 ==, != 연산은 동일한 객체를 참조하는지, 다른 객체를 참조하는 지 알아볼 때 사용된다.**<br>
즉 참조타입 변수의 값이 힙 영역의 객체 주소이므로 결국 **주소값**을 비교하는 것이다.(중요!) <br>

## null 과 NullPointerException
* 참조 타입 변수는 힙 영역의 객체를 참조하지 않는다는 뜻으로 null값을 가질 수 있다. 
=> null 값도 초기값으로 사용할 수 있기 때문에 null로 초기화된 변수는 스택 영역에 생성된다.(다만 힙 영역의 객체를 참조하지 않는다.)<br>

|스택 영역 |   값 |
|----------|------|
| String a | null |

* NullPointerException : 참조 타입 변수 a의 값이 null인데,  a로 객체 관련해서 메소드를 호출하거나 값을 할당하면 발생하는 예외(Error)
```java
public class NullPointerEx {
    public static void main(String[] args) {
          try {
              int[] Array = null;
              Array[0] = 10;// 참조변수인 배열 intArray가 null값인데, 객체 intArray[0]에 10을 할당하려하므로 NullPointerException 발생.
          }
          catch (NullPointerException e){
              e.printStackTrace();
          }


    }
}
```

## String 타입
* 문자열은 String 객체로 생성되고, 변수는 String 객체를 참조한다. (명심!)
* 일반적으로 변수에 문자열을 저장할 경우에는 문자열 리터럴을 사용한다. (new 연산자 x!)

```java
String name1 = "신용권";
String name2 = "신용권";
// name1 과 name2는 지역변수로서 스택에 할당되고, 문자열 리터럴인 "신용권"은 객체로서 힙에 할당된다. 
// 또 자바는 문자열 리터럴이 동일하다면 String 객체를 공유하도록 되어 있으므로 모든 리터럴 문자열 "신용권"은 같은 주소값이다. 
// 따라서 변수 name1과 name2는 "신용권"을 참조하고, 같은 주소값을 갖고 있다. ("신용권"이 리터럴 문자열이기에)
```


## 배열 타입 
* 배열에 다른 타입의 값을 저장하려고 하면 타입 불일치(Type mismatch) 컴파일 오류가 발생한다.
* 배열의 길이가 한번 생성되었으면 길이를 늘리거나 줄일 수 없다. => 정적 배열(Static array)
* 배열 변수는 참조 변수에 속한다. 

```java
int[] intArray = null; // 배열의 초기값 null로 할당 가능.
intArray[0] = 10; //NullPointerException. => null 인 상태에서 element의 값을 읽거나 할당 불가능. (애초에 힙의 객체가 없으니깐!)
// 결론: 배열 변수는 배열을 생성하고 참조하는 상태에서 값을 저장하거나 읽어야 한다.
```

> 값 목록으로 배열 생성

```java
int[] a ={1,2,3};
// 지역 변수 a는 스택에 생성됨. a[0], a[1], a[2]는 객체로써 힙 영역에 생성되고 값이 각각 1,2,3 으로 할당됨.
// 배열 a는 첫번째 요소 a[0]의 시작 주소를 가리킴(참조) 
```
주의할점: <br>
배열 변수를 이미 선언한 후에 다른 실행문에서 중괄호를 사용한 배열 생성은 허용치 않는다. (컴파일 에러)
이런 경우는 new 연산자를 사용해 값 목록을 지정해주면 된다. 
```java
int[] a;
a = {1,2,3,}; // 컴파일에러
a = new int[]{1,2,3}; // new 연산자를 사용하여 초기화 가능.
```

메소드의 매개값이 배열일 경우에 마찬가지이다. <br>
```java
int add(int[] scores){ ...}  //함수 add 의 매개변수인 배열 scores
//====================================
int result = add({95,85,90}); // 컴파일 에러
int result = add(new int[] {95,85,90}) // 정상작동
```

> new 연산자로 배열 생성

* 값의 목록을 가지고 있지 않지만, 향후 값들을 저장할 배열을 미리 만들고 싶다면 new 연산자로 다음과 같이 배열 객체를 생성시킬 수 있다.
 
```java
 타입[변수] = new 타입[길이];
 int[] intArray = new int[5]; // intArray[0], intArray[1], intArray[2], intArray[3], intArray[4] 생성.
```

> 배열 길이 

배열변수.length로 길이측정가능하다. <br>
```java
int[] arr = {1,2,3};
int num = arr.length; // num은 3이다. 
```

> 커맨드 라인 입력

```java
public static void main(String[] args)
```
=> "java 클래스"로 프로그램을 실행하면 JVM은 길이가 0인 String배열을 먼저 생성하고 main() 메소드를 호출할 때 매개값으로 전달한다.<br>
```java
public class Args {
    public static void main(String[] args) {
        int num1 = Integer.parseInt(args[0]);
        int num2 = Integer.parseInt(args[1]);

        int result = num1+num2;
        System.out.println("result: " + result);
    }
}
```
실행결과 <br>
=> javac Args.java <br>
=> java Args 10 20 <br>
=> result: 30 <br>

> 다차원 배열

```java
int[][] scores = new int[2][3];
```
=> java도 배열이 decay가 되는지 물어보기 (될것같다.) <br> 

> 객체를 참조하는 배열

* 기본 타입(byte, char, short, int, long, float, double, boolean) 배열은 각 항목에 직접 값을 갖고 있지만,(그래도 힙 영역이다.) 참조 타입(클래스, 인터페이스) 배열은 각 항목에 객체의 번지를 가지고 있다. 
c언어에서 포인터 배열과 같은 느낌 <br>
```java
String[] strArray = new String[2];
strArray[0] = "java"; //객체를 참조
strArray[1] = new String("java"); //객체를 참조
```

> 배열 복사 

* 배열은 한번 생성하면 크기를 변경할 수 없기때문에 더 많은 공간이 필요하다면 더 큰 배열을 새로 만들고 이전 배열을 복사한다.
=> for문을 이용해 복사하거나, System.arraycopy()을 이용해 배열을 복사한다. <br>


for문 이용<br>
```java
public class Copy {
    public static void main(String[] args) {
        int[] oldArray = {1,2,3,4};
        int[] newArray = new int[8];

        for(int i=0; i < newArray.length; i++){
            if(i<4)
              newArray[i] = oldArray[i];
            else
                newArray[i] = i+1;
            System.out.print(newArray[i] + " ");
        }

    }
}
```

System.arraycopy() 이용 <br>
```java
System.arraycopy(Object src, int srcPos, Object dest, int destPos, int length);
// src는 원본 배열, srcPos는 복사할 항목의 시작 인덱스, dest는 새 배열, destPos는 복사될 시작 인덱스 , length는 복사할 원소 개수.


public class Copy {
    public static void main(String[] args) {
        int[] oldArray = {1,2,3,4};
        int[] newArray = new int[8];

        System.arraycopy(oldArray,0,newArray,0,oldArray.length);
        for(int i=0; i<newArray.length; i++)
            System.out.print(newArray[i] +" ");  // 1 2 3 4 0 0 0 0 
        System.out.println();
        }

} 

```
> 향상된 for문

* 향상된 for문은 반복 실행을 하기 위해 카운터 변수와 증감식을 사용하지 않는다. **배열 및 컬렉션 항목의 개수만큼 반복하고**, 자동적으로 for문을 빠져나간다. 
```java
for( 타입 변수 : 배열){

	실행문
}
```
for문의 괄호()에는 **배열에서 꺼낸 요소를 저장할 변수 선언**,  콜론(:) 그리고 배열을 나란히 작성한다. <br>
최종적으로 가져올 요소가 없으면 for문이 종료된다. <br>

```java
public class Arrays {
    public static void main(String[] args) {
        int sum = 0;
        int[] array = {1,2,3};
        for (int i : array){
            sum +=i;
        }
        System.out.println(sum);
    }
}
```


## 열거 타입 

> 열거 타입 선언

* 열거타입을 선언하기 위해서는 먼저 열거 타입의 이름을 정하고 열거 타입 이름으로 소스 파일(.java)을 생성해야 한다. 
```java
public enum Week {
    MONDAY, // c와는 다르게 따로 숫자값을 갖고 있지 않는 열거 상수 인가 보다.
    TUESDAY, // 열거 상수는 객체이다. 힙 영역에 있다. 
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}
// 이렇게만 작성하였으면 파일이름은 Week.java이어야 한다.
```

> 열거 타입 변수

```java
public class Enumtest {
    public static void main(String[] args) {
        Week today = Week.FRIDAY; // 메소드로 불러들인 FRIDAY는 메소드 영역에 있는 힙 영역의 FRIDAY 객체를 참조한다.
        // 따라서  변수 today 와 메소드 영역의 열거 상수 Week.FRIDAY 는 FRIDAY 객체를 같이 참조 한다.
        System.out.println(today);
        Week week2 = null; // 열거변수도 reference type 이므로 null 값 지정가능하다.

    }
}
``` 

> 열거 타입의 name() 메소드

* 열거 객체가 가지고 있는 문자열을 리턴한다.
```java
 Week today = Week.SUNDAY;
 String name = today.name(); // SUNDAY 값 리턴되서 name 변수에 저장.
```
> 열거 타입의 ordinal() 메소드
 *  전체 열거 객체 중 몇 번째 열거 객체인지 알려준다. 
```java
  Week today = Week.SUNDAY;
  int ordinal = today.ordinal(); // enum은 0부터 시작하므로 답은 6. 6 리턴되서 ordinal에 저장.
```

