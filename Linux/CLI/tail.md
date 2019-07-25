## tail 명령어

설명 
* 문서 내용의 뒷부분 출력 
: default하게 끝에서부터 10줄을 출력한다. 

자주 사용되는 옵션 
* -c , --bytes = \[+\] NUM  <br>: NUM byte만 출력
* -n , --lines = \[+\] NUM  <br>: NUM line만 출력
* -f , --follow\[={name | descr}]   <br>: 추가되는 내용 대기. 추가되는 내용은 append하여 출력
* -F
 <br>: 파일이 truncate 되는 경우 re-open하여 follow 함 (logrotate 되는 파일에 유용)
 * NUM
 <br>: byte 입력 시 K,M,G,T (키로, 메가, 기가, 테라) 입력가능 ( ex : 10M)
 <br> : '+' 입력 시 문서 시작의 NUM byte/line 지점에서 출력 시작
 <br>=> 만약 NUM이 +1이라면 문서의 1줄부터 시작한다.( 주의! head 의 -NUM은 NUM만큼 뒤에서 제외시키는 것이지만, tail의 +NUM은 문서의 NUM line 부터 출력이 시작함을 인지하자.)

사용 예제 

```
tail -n 1 SQL/SQL첫걸음/1강_데이터베이스.md 
```
: 1강_데이터베이스.md 파일의 끝에서 1줄을 출력한다. 

```
tail -n +5  SQL/SQL첫걸음/1강_데이터베이스.md
```
: 1강_데이터베이스.md 파일의 5줄부터 끝까지 출력한다.

``` 
cat /etc/passwd | tail -n 15
```
: cat으로 출력된 내용을 파이프로 받아서 tail 명령어를 시행해라. 결국 뒤 15줄만 출력. ( '\|' 는 파이프라 한다. ) 


```
cat /etc/passwd | tail -n +5
```
: cat으로 출력된 내용을 파이프로 받아서 tail 명령어를 시행해라. 결국 문서의 5줄부터 끝까지 출력


## tail 의 -f 옵션 
:문서의 뒤 10줄만 출력하는 것을 넘어서 **계속 대기하여 만약 문서에 내용이 추가되는 경우 그 추가된 내용까지 출력해주는 옵션**이다. 
<br> 로그 파일를 실시간으로 출력할 수 있으므로 -f 옵션은 많이 쓰인다. 다만 만약 -f 로 출력을 대기하는 도중 파일이 삭제라도 된다면 이후 똑같은 파일을 만든다 하더라도 출력을 계속해서 할 수 없다. 

실습1 
1. aa 라는 파일을 하나 만들어 내용을 하나 추가한다. 
2. tail -f aa 을 입력하여 대기한다.
3. 다른 터미널을 생성하여 리다이렉션으로 aa 파일에 문자열을 append 한다.
4. -f 옵션이 제대로 되는지 확인한다.

```
echo hello >> aa 
```
: aa라는 파일을 하나 만들고 hello라고 적습니다.

```
tail -f aa
// 실행 결과 
// hello

```
: tail -f aa 라 하면 aa의 문서가 출력됩니다. 그리고 계속 대기하며 기다리고 있습니다. 


![tail_f](https://user-images.githubusercontent.com/38216027/61861493-04b34480-af07-11e9-936e-a29a500101f9.png)
: 이후 다른 터미널을 생성하여 aa 파일에 문자열을 추가하면 -f 옵션은 추가된 문자열들을 출력하고 계속 대기합니다. 


실습2 
1. tail -f aa 로 aa 파일을 출력하고 대기한다.
2. aa 라는 파일을 rm 명령어로 지운다.
3. aa 파일을 다시 만들어 문자열을 추가한다.
4. -f 이 여전히 aa파일을 follow 하여 출력하는지 확인한다.(하지만 출력하지 않음을 알 수 있다.) 

![tail_f2](https://user-images.githubusercontent.com/38216027/61862008-1812df80-af08-11e9-838e-5cee0958c7a4.png)
: tail -f aa 로 파일 출력하였고, 이후 rm 으로 aa 파일을 지웠다. 이후 aa를 다시 만들어 문자열을 new! 와 i'm so sad.. 를 추가했지만 -f 는 출력하지 않았다. 파일을 삭제하고 다시 만들어도 -f 로는 파일을 follow 할 수 없기 때문이다. 
<br>=> **하지만 -F 옵션은 파일을 follow 할 수 있다!** 

## tail 의 -F 옵션
:-f 옵션과 마찬가지로 문서의 뒤 10줄만 출력하는 것을 넘어서 **계속 대기하여 만약 문서에 내용이 추가되는 경우 그 추가된 내용까지 출력해주는 옵션**이다. 
 <br>: 또 -f 옵션과 다르게 파일이 truncate 되는 경우 re-open하여 follow 함 (logrotate 되는 파일에 유용). 즉 파일이 없어지고 다시 만들어져도 그 파일을 계속해서 follow하여 추가되는 내용을 출력한다는 의미이다. 


 실습

 1. tail -F aa 로  aa 파일을 출력하고 대기한다. 
 2. rm으로 aa파일을 지운다. 
 3. aa 파일을 다시 만들어 문자열을 추가한다.
 4. -F 이 여전히 aa파일을 follow 하여 내용들을 출력하는지 확인한다.

 ![tail_F](https://user-images.githubusercontent.com/38216027/61862781-62e12700-af09-11e9-8280-fa8b78e8fd1c.png)
1. tail -F aa 를 입력하니 aa의 내용이 출력됨. ( new! i'm so sad..) 
2. rm 으로 aa 파일을 지우니 -F 옵션에서 파일 접근 불가능하다고 출력하지만 계속 대기함. (tail: 'aa'는 접근 불가능하게 됨: 그런 파일이나 디렉터리가 없습니다)
3. aa라는 파일을 다시 만들고 문자열 추가. ( new new! , wow! I'm so happy.)
4. -F 옵션은 다시 aa 파일을  follow 하였다고 알림( tail: 'aa' has appeared;  following new file)
5. 이후 -F 옵션은 새로운 내용을 출력. ( new new! , wow! I'm so happy.)


> 정리1 : -f 옵션은 계속 대기하지만 파일을 삭제되면 파일이 다시 생성된다해도 더이상 follow 하지 않는다. 반면 -F 옵션은 -f 와 마찬가지로 계속 대기하고 파일을 삭제된다 해도 다시 생성되면 파일을 follow 하여 새로운 내용들을 출력한다.

> 정리2 : -F 옵션은 logrotate 되는 파일에 유용하다.