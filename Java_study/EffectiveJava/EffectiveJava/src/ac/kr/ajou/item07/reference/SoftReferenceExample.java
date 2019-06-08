package ac.kr.ajou.item07.reference;

import java.lang.ref.SoftReference;

public class SoftReferenceExample {
    public static void main(String[] args) {
        Integer prime = 1;
        SoftReference<Integer> soft = new SoftReference<>(prime);
        System.out.println(prime);
        System.out.println(soft.get());
        prime = null;
        System.gc();
        // Note: 강제적으로 가비지 콜렉터를 실행시켜도
        //  SoftReference 는 대상이 되지 않기 때문에 제거되지 않는다.
        System.out.println(soft.get());
        System.out.println(prime);
    }
}
// NOTE: SoftReference만 존재할 경우 GC대상으로 들어가도록 JVM은 동작한다.
//  다만 WeakReference 와의 차이점은 메모리가 부족하지 않으면 굳이 GC 하지 않는 점이다.
//  때문에 조금은 엄격하지 않은 Cache Library 들에서 널리 사용되는 것으로 알려져있다.