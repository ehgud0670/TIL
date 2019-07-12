package ac.kr.ajou.item08;

import java.lang.ref.Cleaner;

public class SampleResource implements AutoCloseable {

    private boolean closed;

    private static final Cleaner CLEANER = Cleaner.create();

    private final Cleaner.Cleanable cleanable;

    public SampleResource() {
        ResourceCleaner resourceCleaner = new ResourceCleaner();
        this.cleanable = CLEANER.register(this, resourceCleaner);
    }

    private static class ResourceCleaner implements Runnable {


        @Override
        public void run() {
            System.out.println("clean()");
        }
    }

    @Override
    public void close() throws RuntimeException {
        if (this.closed) {
            throw new IllegalStateException();
        }
        closed = true;
        System.out.println("close()");
        cleanable.clean();
    }

    void hello() {
        System.out.println("hi");
    }

    // note : 안전망 삼아서 finalize()에서 한번 더 close()를 호출한다.
    @Override
    protected void finalize() throws Throwable {
        if (!this.closed) {
            close();
        }
    }

    public static void main(String[] args) {
//        SampleResource sampleResource = null;
//        try {
//            sampleResource = new SampleResource();
//            sampleResource.hello();
//        } finally {
//            if (sampleResource != null) {
//                sampleResource.close();
//            }
//        }
        // note: 자바 10부터는 var 이라는 것이 된다.
        try (var sampleResource = new SampleResource()) {
            sampleResource.hello();
        }
    }
}

