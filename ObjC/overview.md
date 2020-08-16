# Overview

```objectivec 
#import <Foundation/Foundation.h>

int main (int argc, const char* argv[]) {
    @autoreleasepool {
        NSLog (@"Programming is fun!")
    }

    return 0;
}

```


```objectivec
#import <Foundation/Foundation.h>
```

* `#import`는 이 파일에 있는 정보를 마치 프로그램의 그 위치에 그대로 입력된 것처럼 가져오거나 포함시키라는 의미다. 

```objectivec
int main (int argc, const char * argv[])
```
main 함수

```objectivec
@autoreleasepool { }
```
여는 중괄호와 닫는 중괄호 사이에 나타나는 프로그램 명령문은 모두 오토릴리스 풀(autorelease pool)이라는 컨텍스트 내에서 실행되어야 한다.
**오토릴리스 풀은 여러분의 애플리케이션이 객체를 생성하며 사용하는 메모리를 시스템이 효과적으로 관리하도록 하는 기법이다.**

```objectivec
NSLog (@"Programming is fun!")
```
NSLog 루틴은 간단히 인수를 표시하거나 로깅하는 Objective-C 라이브러리 함수다. 그러나 그전에 자신이 실행된 날짜와 시간, 프로그램 이름, 아직 설명하지 않은 다른 숫자를 표시한다. 
예를 들면 아래와 같다.

```objectivec
2020-08-16 22:27:19.324883+0900 ObjcStarter[30075:288822]
```
=> 날짜, 시간, 프로그램 이름, 아직 설명하지 안은 다른 숫자

```objectivec
@"Programming is fun!"
```
=> 문자들은 큰따옴표로 둘러싸였고 @ 부호가 맨 앞에 있다. 이것들을 통틀어 NSString 객체라고 한다. (@문자가 없다면 C 스타일의 스트링 상수를 작성하는 것이고, @을 쓰면 NSString 스트링 객체를 작성하는 것이다.) 


```objectivec
return 0;
```
관례적으로 0은 프로그램이 정상 종료되었다는 의미다. 