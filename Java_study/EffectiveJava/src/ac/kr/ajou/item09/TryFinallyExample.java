package ac.kr.ajou.item09;


// try- finally 구문은 처음 발생한 에러의 정보를 get 할 수 없다.
public class TryFinallyExample  {
    public static void main(String[] args){
        MyResource myResource;
        myResource = new MyResource();
        try{
            myResource.doSomething();
            MyResource myResource2 = new MyResource();
            try{
                myResource2.doSomething();
            } finally{
                myResource2.close();
            }
        }finally{
            myResource.close();
        }
    }
}
