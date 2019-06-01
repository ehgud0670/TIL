package item03;

//public static final 필드 방식의 싱글턴
public class Elvis {
    static final Elvis INSTANCE = new Elvis();
    private static int count;

    // 생성자는 private 으로 감춰둔다.
    private Elvis() {
        count++;
        if(count>1){
            throw new IllegalStateException("this object should be singleton");
        }
    }


    // 어떤 용도인지 물어보기
    public void leaveTheBuilding() {

    }
}

// private 생성자는
