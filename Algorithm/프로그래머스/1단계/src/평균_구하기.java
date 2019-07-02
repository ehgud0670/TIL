package kr.ac.ajou.programmers.algo0617;

public class 평균_구하기 {
    private static double solution(int[] arr) {
        int len = arr.length;
        double sum = 0;
        for(int element : arr){
            sum += element;
        }

        return (sum / len);
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4};

        System.out.println(solution(arr));
    }
}
