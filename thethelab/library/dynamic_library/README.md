## 동적 라이브러리 만들기
## 동적로딩! 따로 파일을 컴파일 안해줘도 되므로 업데이트가 가능하다. 업데이트가 가능한 프로그램들은 동적 라이브러리를 사용하고 있다.

1. main.c 와 absolute.c 소스코드 작성하기
2. gcc absoulte.c -c 로 오브젝트 파일 만들기 (absolute.c -> absolute.o)
3. gcc -shared -fpic -FPIC absolute.o -o libabs.so 로 동적 라이브러리파일 libabs.so 만들기 (-o는 이름짓는 명령어이다.)
4. gcc main.c -labs -L. 소스코드와 동적 라이브러리 컴파일 하기
5. LD_LIBRARY_PATH=. ./a.out 실행할때 동적라이브러리가 있는 위치 알려주기(LD_LIBRARY_PATH) => 동적 로딩임을 보여준다.
