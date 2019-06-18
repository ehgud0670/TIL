package kr.ac.ajou.programmers.algo0618;

import java.util.Arrays;
import java.util.TreeSet;

public class 나누어_떨어지는_숫자_배열 {

    private static int[] solution(int[] arr, int divisor) {
        TreeSet<Integer> treeSet = new TreeSet<>();

        for (int element : arr) {
            if (element % divisor == 0) {
                treeSet.add(element);
            }
        }

        int size = treeSet.size();
        if (size == 0) {
            return new int[]{-1};
        }

        int[] answer = new int[size];
        int i = 0;
        for (int element : treeSet) {
            answer[i++] = element;
        }

        return answer;
    }

    public static void main(String[] args) {
        int[] arr1 = {5, 9, 7, 10};
        int divisor1 = 5;

        System.out.println(Arrays.toString(solution(arr1, divisor1)));

        int[] arr2 = {2, 36, 1, 3};
        int divisor2 = 1;

        System.out.println(Arrays.toString(solution(arr2, divisor2)));

        int[] arr3 = {3, 2, 6};
        int divisor3 = 10;

        System.out.println(Arrays.toString(solution(arr3, divisor3)));
    }
}
