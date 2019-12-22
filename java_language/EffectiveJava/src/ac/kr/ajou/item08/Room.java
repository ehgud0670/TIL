package ac.kr.ajou.item08;

import java.lang.ref.Cleaner;

public class Room implements AutoCloseable {
    private static final Cleaner cleaner = Cleaner.create();

    // note : 청소가 필요한 자원. 절대 Room 을 참조해서는 안 된다!
    private static class State implements Runnable {
        int numJunkPiles; // 방 안의 쓰레기 수

        State(int numJunkPiles) {
            this.numJunkPiles = numJunkPiles;
        }

        // note: close 메서드나 cleaner 가 호출한다.
        @Override
        public void run() {
//             note : State 인스턴스안에 Room 을 참조해선 안된다. -> State 클래스안에 Room 이 있으면 안된다.
//            try(Room room = new Room(10)) {
//            } catch (Exception e) {
//                e.printStackTrace();
//            }


            System.out.println("방 청소");
            numJunkPiles = 0;
        }


    }

    // note: cleanable 객체. 수거 대상이 되면 방을 청소한다.
    private final Cleaner.Cleanable cleanable;
    private State state;


    public Room(int numJunkPiles) {
        // note: 방의 상태. cleanable 과 공유한다.
        this.state = new State(numJunkPiles);
        cleanable = cleaner.register(this, state);
    }

    @Override
    public void close() throws Exception {
        cleanable.clean();
    }
}
