package item03;

//chetBaker
public class Chet {
    private static final Chet INSTANCE = new Chet();

    private static int count;

    private Chet() {
        if (count > 1) {
            throw new IllegalStateException("this object should be singleton");
        }
    }

    static Chet getInstance() {
        return INSTANCE;
    }

    public void leaveTheBuilding() {

    }
}
