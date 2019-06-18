package kr.ac.ajou.programmers.algo0618;

public class 문자열_내_p와_y의_개수 {

    private static boolean solution(String s) {

        int pCount = 0;
        int yCount = 0;

        int len = s.length();
        for (int i = 0; i < len; i++) {
            char target = s.charAt(i);
            if (target == 'p' || target == 'P') {
                pCount++;
            } else if (target == 'y' || target == 'Y') {
                yCount++;
            }
        }
        if (pCount == 0 && yCount == 0) {
            return false;
        } else return pCount == yCount;

    }

    public static void main(String[] args) {
        String str1 = "pPoooyY";
        String str2 = "Pyy";
        String str3 = "kk";

        System.out.println(solution(str1));
        System.out.println(solution(str2));
        System.out.println(solution(str3));
    }
}
