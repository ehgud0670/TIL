# chapter2
## 변수와 타입

### 변수
리터럴이란 소스 코드 내에서 직접 입력된 값을 말한다.(상수x, 변할수 있다.) <br>


논리 리터럴 <br>
= true, false <br>
=> 논리 리터럴을 저장할 수 있는 타입은 boolean 하나뿐이다. <br>

메소드 블록 내에서 선언된 변수: 로컬 변수(local variable) <br>
=> 로컬 변수는 실행이 끝나면 메모리에서 자동으로 없어진다. 

* 변수는 선언된 블록 내에서만 사용이 가능하다.
=> 변수가 if문에서 선언되면 if문에서만 사용가능하고(변수는 if문에 소멸), for문에서 선언되면 for문에서만 사용가능하다. <br>

### 데이터 타입

* primitive 타입 (원시 타입)

| primitive type| 값의 종류 | 메모리 사용 크기 | 저장되는 값의 범위 |
|---------------|-----------|------------------|--------------------|
| byte          | 정수      | 1byte = 8bit     | -128~127           |
| char  |  정수 | 2byte = 16bit | 0 ~ 2^16-1 |
| short |  정수 | 2byte = 16bit | -2^15 ~ 2^15-1 | 
| int   |  정수 | 4byte = 32bit | -2^31 ~ 2^31-1 |
| long  |  정수 | 8byte = 64bit | -2^63 ~ 2^63-1 |
| float |  실수 | 4byte = 32bit | 오차가 있는 값의 범위 |
| double | 실수 | 8byte = 64bit | 오차가 있는 값의 범위 |
| boolean | 논리| 1byte = 8bit  | true, false  |


### 타입 변환
1. 자동 타입 변환(Promotion)

=> 자동 타입 변환(Promotion)은 프로그램 실행 도중에 자동적으로 타입 변환이 일어나는 것을 말한다. <br>
자동 타입 변환은 작은 크기를 가지는 타입이 큰 크기를 가지는 타입에 저장될 때 발생한다. <br>

* 큰 크기 타입 = (자동 형 변환) 작은 크기 타입; 

크기별 type<br>
```java
 byte(1) < short(2) < int(4) < long(8) < float(4) < double(8)
```
=> float은 long보다 더 넓은 범위의 수를 표현할 수 있기 때문에 long보다 큰 크기 타입이다 . 즉 정수 타입 < 실수 타입 <br>


```java
byte byteValue = 10;
int intValue = byteValue; // 자동 타입 변환이 일어난다.

int value = 20;
double doubleValue = value; // 20.0으로 자동 타입 변환이 일어난다.
```
아래의 표처럼 byteValue는 int형 intValue로 자동 타입 변환이 되어 크기가 1byte에서 4yte으로 확장되고,(byte -> int) <br>
그 값이 intValue에 assign 된다. (원래 byteValue는 byte타입을 유지 한다.) <br>


|byte 타입|
|---------|
|00001010 |

|int 타입| | | |
|--------|-|-|-|
|00000000|00000000|00000000|00001010|

자동 타입 변환의 단 하나의 예외:<br>
=> char는 byte 보다 크므로 byte가 char로 자동 타입 변환되어야 하는게 정상이다.<br>
하지만 byte는 음수도 범위에 포함되지만 char의 범위 중 음수가 없으므로 컴파일 오류가 발생한다 <br>
이럴땐 강제 타입 변환(castiong)을 통해 해결한다. <br>
```java
byte byteValue = 4;
//char charValue = byteValue; // 컴파일 에러 
char charValue = (char)byteValue; // 해결
```

2. 강제 타입 변환(Casting)
큰 크기의 타입은 작은 크기의 타입으로 자동 형 변환을 할 수 없다. <br>
이 이치는 큰 그릇에 있는 물을 작은 그릇 안에 모두 담을 수 없는 것과 같은 이치이다. <br>
하지만 큰 그릇을 작은 그릇 사이즈로 쪼개어서 한 조각만 작은 그릇에 넣는다면 가능하다. <br>
이것이 바로 강제 형 변환(Casting)이다. 

* 작은 크기 타입 = (작은 크기 타입) 큰 크기 타입 => 강제 형 변환

```java
public class Casting {

    public static void main(String[] args) {
        int intValue = 103029770;
        byte byteValue = (byte)intValue;

        System.out.printf("intValue: %d \n",intValue); // 103029770
        System.out.printf("byteValue: %d \n",byteValue); // 10 => 값이 잘려 나간다. 
    }
}
```

