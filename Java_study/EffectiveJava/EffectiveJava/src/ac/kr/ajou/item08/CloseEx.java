package ac.kr.ajou.item08;

public class CloseEx implements AutoCloseable{


    private boolean closed;

    @Override
    public void close() throws Exception {
        if(this.closed){ // 자원이 close 된 경우라면
            throw new IllegalStateException();
        }
        this.closed = true;
    }

    void printHello(){
        if(this.closed){ // 자원이 close 된 경우라면.
            throw new IllegalStateException();
        }
        System.out.println("hello");
    }

}
