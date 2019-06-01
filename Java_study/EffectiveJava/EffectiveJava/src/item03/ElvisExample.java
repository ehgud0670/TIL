package item03;

import java.lang.reflect.Constructor;

public class ElvisExample {
    public static void main(String[] args) throws Exception {
        Elvis elvis = Elvis.INSTANCE;

        Constructor<Elvis> constructor = Elvis.class.getDeclaredConstructor();
        constructor.setAccessible(true);
        Elvis elvis2 = constructor.newInstance();

    }
}
