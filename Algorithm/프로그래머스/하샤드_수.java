package kr.ac.ajou.programmers.algo0618;

public class 하샤드_수 {

    public boolean solution(int x) {

        int sum = 0;
        int temp = x;
        while (true) {
            sum += temp % 10;
            temp = temp / 10;
            if (temp == 0) {
                break;
            }
        }
        return x % sum == 0;
    }

    public static void main(String[] args) {
        하샤드_수 test = new 하샤드_수();

        System.out.println(test.solution(10));
        System.out.println(test.solution(12));
        System.out.println(test.solution(11));
        System.out.println(test.solution(13));

    }
}
