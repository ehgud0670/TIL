## 정적 라이브러리 만들기
## 정적 로딩! 한번 컴파일하면 업데이트 할수 없다. 다시 컴파일해야 한다.

1. main.c , add.c 소스코드 작성
2. gcc -c main.c add.c로 각각 오브젝트 파일(main.o, add.o) 생성
3. ar rcv libadd.a add.o 로 add.o를 정적 라이브러리인 libadd.a(.a는 아카이브 파일) 생성
4. gcc main.o -ladd -L. 로 main.o에 정적 라이브러리 libadd.o 적용. -L.은 현재 폴더임을 명시하는 명령어.
5. ./a.out 코드쳐서 제대로 실행되는 지 확인. 
