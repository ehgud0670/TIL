# wc 명령어

* wordcount의 준말.

설명 
* 파일의 line / word / byte count 출력

자주 사용되는 옵션 
* -l 
<br>:라인수 만 출력

사용 예제 
* wc FILENAME
* wc -l FILENAME 
* cat FILENAME | wc -l 
* wc -l FILENAME | cut -d ' ' -f 1
* wc -l FILENAME | awk '{ print $1 }' # 라인수만 출력
* wc \*.c 

> **라인(line) 수**가 중요한 이유

: 예를 들어, /etc/passwd처럼 한 줄의 하나의 설정이 들어가는 파일이 있을 수 있는데 , **이때 라인 수로 몇 개의 설정이 있는지 알아낼 수 있기 때문에** 라인 수를 알아야 할 필요가 있고 따라서 wc -l FILENAME 명령어는 이런 경우에 자주 쓰인다. (예: 라인의 수가 3개이면 아 설정이 3개가 있구나라고 생각할 수 있다.)


## wc -l FILENAME

```
wc -l /etc/passwd

// 실행 결과
// 42 /etc/passwd
```
: 라인수와 해당 파일의 이름이 같이 출력된다.

## wc -l FILENAME | awk '{ print $1 }'


```
wc -l /etc/passwd | awk '{ print $1 }'

// 실행 결과 
// 42
```
: 라인수만 출력된다. 
<br>: awk '{ print $1 }' 의 의미 : 공백을 기준으로 첫번째 토큰만 출력하라.


## wc -l FILENAME | cut -d ' ' -f 1 

```
wc -l /etc/passwd | cut -d ' ' -f 1

// 실행 결과
// 42
```
: 라인수만 출력된다.
<br>: cut -d ' ' -f 1 의 의미 : delimiter(자르는 기준) 를  공백(' ')으로 두고 첫번째 필드를 내보내라(출력해라). 
<br>:따라서 첫번째 필드인 42만 출력된다. 