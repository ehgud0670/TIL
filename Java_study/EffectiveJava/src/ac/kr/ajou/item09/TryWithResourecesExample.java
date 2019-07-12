package ac.kr.ajou.item09;

// try-with-resources 을 사용하면 자동으로 자원을 닫아 준다.
// 또한 어디서 먼저 에러가 났는지 알 수 있고(close()메소드의 에러는 숨겨지기(suppressed) 때문이다.),
// 가독성을 매우 높여준다는 큰 장점이 있다. => 자원 닫기를 해야 할 경우에 반드시 try-with-resources 문을 사용하자!
public class TryWithResourecesExample {
    public static void main(String[] args) {
        try(MyResource myResource = new MyResource();
            MyResource myResource2 = new MyResource()){
            myResource.doSomething();  // 예외가 myResource 에서만 발생해도, myResource, myResource2 모두 닫아준다.
            myResource2.doSomething();
        }

    }
}
//    Exception in thread "main" item09.FirstException
//        at item09.MyResource.doSomething(MyResource.java:9)
//        at item09.TryWithResourecesExample.main(TryWithResourecesExample.java:6)
//        Suppressed: item09.SecondException
//        at item09.MyResource.close(MyResource.java:16)
//        at item09.TryWithResourecesExample.main(TryWithResourecesExample.java:5)
