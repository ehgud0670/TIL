package kr.ac.ajou.programmers.algo0618;

public class 정수_제곱근_판별 {

    public long solution(long n) {

        long sqrt = (long)Math.sqrt(n);
        if(sqrt*sqrt == n) {
            return (sqrt + 1) * (sqrt + 1);
        } else{
            return -1;
        }
    }

    public static void main(String[] args) {
        정수_제곱근_판별 test = new 정수_제곱근_판별();
        System.out.println(test.solution(121));
        System.out.println(test.solution(3));
    }
}
