package kr.ac.ajou.programmers.algo0619;


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class 가장_큰_수 {

    class Descending implements Comparator<String> {

        @Override
        public int compare(String o1, String o2) {
           String o1o2 = o1 + o2;
           String o2o1 = o2 + o1;
           return -o1o2.compareTo(o2o1);
        }
    }

    public String solution(int[] numbers) {
        boolean nonZeroCheck = false;
        for(int num : numbers){
            if(num !=0){
                nonZeroCheck = true;
                break;
            }
        }
        if(!nonZeroCheck){
            return "0";
        }

        List<String> list = new ArrayList<>();
        for (int num : numbers) {
            list.add(String.valueOf(num));
        }

        list.sort(new Descending());

        StringBuilder answer = new StringBuilder();
        for(String num : list){
            answer.append(num);
        }

        return answer.toString();
    }

    public static void main(String[] args) {
        가장_큰_수 test = new 가장_큰_수();
        int[] numbers = {0,0,0,0};
        System.out.println(test.solution(numbers));

        int[] numbers2 = {3, 30, 34, 5, 9, 0};
        System.out.println(test.solution(numbers2));
    }
}
