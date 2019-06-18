package kr.ac.ajou.programmers.algo0618;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class 정수_내림차순으로_배치하기 {

    class Descending implements Comparator<Long> {

        @Override
        public int compare(Long o1, Long o2) {
            return -o1.compareTo(o2);
        }
    }

    public long solution(long n) {
        long answer = 0;

        List<Long> list = new ArrayList<>();

        while (true) {
            long remainder = n % 10;
            list.add(remainder);

            n = n / 10;
            if (n == 0) {
                break;
            }
        }
        list.sort(new Descending());
        int len = list.size();

        int mux = 1;
        for (int i = len - 1; i >= 0; i--) {
            long value = mux * list.get(i);
            answer += value;

            mux *= 10;
        }
        return answer;
    }

    public static void main(String[] args) {
        System.out.println(new 정수_내림차순으로_배치하기().
                solution(118372));
    }
}
