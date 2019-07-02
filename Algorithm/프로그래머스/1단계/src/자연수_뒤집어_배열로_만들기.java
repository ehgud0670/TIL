package kr.ac.ajou.programmers.algo0618;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 자연수_뒤집어_배열로_만들기 {

    public int[] solution(long n) {

        List<Long> list = new ArrayList<>();

        while (true) {
            long remainder = n % 10; // note: 변환은 되도록이면 하지말자. 특히 나눈 결과값에다 하지말자.
            list.add(remainder);

            n = n / 10;
            if (n == 0) {
                break;
            }
        }
        int size = list.size();

        int[] answer = new int[size];
        for (int i = 0; i < size; i++) {
            long temp = list.get(i);
            int value = (int) temp;

            answer[i] = value;
        }

        return answer;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new 자연수_뒤집어_배열로_만들기().solution(12984895)));
    }
}
