package kr.ac.ajou.programmers;

public class 서울에서_김서방_찾기  {
    private static String solution(String[] seoul) {
        String answer;

        for (int i = 0; i < seoul.length; i++) {
            if (seoul[i].equals("Kim")) {
                answer = String.valueOf(i);
                return "김서방은 " + answer + "에 있다";
            }
        }
        return "";
    }


    public static void main(String[] args) {

        String[] seoul = {"Jane", "Kim"};
        System.out.println(solution(seoul));
    }
}