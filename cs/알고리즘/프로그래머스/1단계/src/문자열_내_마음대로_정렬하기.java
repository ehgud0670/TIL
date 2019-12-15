package kr.ac.ajou.programmers.algo0618;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class 문자열_내_마음대로_정렬하기 {

    class Ascending implements Comparator<NewSort> {

        @Override
        public int compare(NewSort o1, NewSort o2) {
            if (o1.c.equals(o2.c)) {
                return o1.str.compareTo(o2.str);
            } else {
                return o1.c.compareTo(o2.c);
            }

        }
    }
    class NewSort {
        private String str;
        private Character c;

        NewSort(String str, char c) {
            this.str = str;
            this.c = c;
        }
    }

    public String[] solution(String[] strings, int n) {

        List<NewSort> list = new ArrayList<>();

        for (String str : strings) {
            list.add(new NewSort(str, str.charAt(n)));
        }
        list.sort(new Ascending());

        int size = list.size();
        String[] answer = new String[size];
        for (int i = 0; i < size; i++) {
            answer[i] = list.get(i).str;
        }

        return answer;
    }

    public static void main(String[] args) {

        String[] strings = {"sun", "bed", "car"};
        int n = 1;
        System.out.println(Arrays.toString(new 문자열_내_마음대로_정렬하기().
                solution(strings, n)));

        String[] strings2 = {"abce", "abcd", "cdx"};
        int n2 = 2;
        System.out.println(Arrays.toString(new 문자열_내_마음대로_정렬하기().
                solution(strings2, n2)));
    }
}
