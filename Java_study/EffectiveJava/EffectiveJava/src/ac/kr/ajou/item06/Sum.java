package ac.kr.ajou.item06;

class Sum {
//    sum: 2305843008139952128
//    time: 7022
//    sum: 2305843008139952128
//    time: 701
// 성능이 sum2()이 sum1()보다 10배 빠름을 알 수 있다.
    static void sum1() {
        long start = System.currentTimeMillis();
        Long sum = 0L;
        for (long i = 0; i <= Integer.MAX_VALUE; i++) {
            sum += i;
        }
        System.out.println("sum: " + sum);
        System.out.println("time: " + (System.currentTimeMillis() - start));
    }


    static void sum2() {
        long start = System.currentTimeMillis();
        long sum = 0L;
        for (long i = 0; i <= Integer.MAX_VALUE; i++) {
            sum += i;
        }
        System.out.println("sum: " + sum);
        System.out.println("time: " + (System.currentTimeMillis() - start));
    }


}
