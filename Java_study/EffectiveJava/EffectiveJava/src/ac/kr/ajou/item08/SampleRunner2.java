package ac.kr.ajou.item08;

public class SampleRunner2 {
    public static void main(String[] args) {
        SampleRunner2 sampleRunner2 = new SampleRunner2();
        sampleRunner2.run();
        System.gc();
    }

    private void run() {
        SampleResource sampleResource = new SampleResource();
        sampleResource.hello();
    }
}
