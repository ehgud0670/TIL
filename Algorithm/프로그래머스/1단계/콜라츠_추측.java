package kr.ac.ajou.programmers.algo0618;

public class 콜라츠_추측 {

    public int solution(long num) {
        if(num == 1){
            return 0;
        }
        int count = 0;

        while (true) {
            if (count >= 500) {
                return -1;
            } else if (num == 1) {
                return count;
            } else {

                if (num % 2 == 0) {
                    num = num / 2;
                } else {
                    num = num * 3 + 1;
                }
                count++;
            }
        }

    }

    public static void main(String[] args) {
        콜라츠_추측 test = new 콜라츠_추측();
        System.out.println(test.solution(6));
        System.out.println(test.solution(16));
        System.out.println(test.solution(626331));
    }
}
