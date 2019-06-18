package kr.ac.ajou.programmers.algo0618;


import java.util.Arrays;
import java.util.Comparator;

public class 문자열_내림차순으로_배치하기 {

    class Descending implements Comparator<String> {


        @Override
        public int compare(String o1, String o2) {
            return -o1.compareTo(o2);
        }
    }


    public String solution(String s) {
        StringBuilder builder = new StringBuilder();

        int len = s.length();
        String[] strings = new String[len];
        for (int i = 0; i < len; i++) {
            strings[i] = String.valueOf(s.charAt(i));
        }

        Arrays.sort(strings, new Descending());
        for(String str : strings){
            builder.append(str);
        }

        return builder.toString();
    }

    public static void main(String[] args) {
        String s = "Zbcdefg";
        System.out.println(new 문자열_내림차순으로_배치하기().solution(s));
    }
}
