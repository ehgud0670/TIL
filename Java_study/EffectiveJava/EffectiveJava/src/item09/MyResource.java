package item09;

import java.awt.dnd.Autoscroll;

public class MyResource implements AutoCloseable {

    public void doSomething() throws FirstException{
        System.out.println("doing something");
        throw new FirstException();
    }


    @Override
    public void close() throws SecondException{
        System.out.println("clean my resource");
        throw new SecondException();
    }
}
