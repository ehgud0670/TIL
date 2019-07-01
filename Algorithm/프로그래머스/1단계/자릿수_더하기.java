package kr.ac.ajou.programmers.algo0618;
// note : 다르게도 풀어자 Stirng 쓰지 말고.
public class 자릿수_더하기 {
    public int solution(int n) {
        int answer = 0;

        String temp = String.valueOf(n);
        int len = temp.length();

        for(int i=0; i<len; i++) {
            String subStr = temp.substring(i,i+1);
            answer += Integer.valueOf(subStr);
        }
        return answer;
    }

    public static void main(String[] args) {

        자릿수_더하기 test = new 자릿수_더하기();

        System.out.println(test.solution(123));

        System.out.println(test.solution(987));
    }
}
