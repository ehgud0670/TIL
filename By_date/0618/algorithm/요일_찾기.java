package kr.ac.ajou.programmers.algo0618;
// 원제목: 2016년

public class 요일_찾기 {

    private static String solution(int a, int b) {
        final int 일월날짜수 = 31;
        final int 이월날짜수 = 29; // 윤년이라서
        final int 삼월날짜수 = 31;
        final int 사월날짜수 = 30;
        final int 오월날짜수 = 31;
        final int 육월날짜수 = 30;
        final int 칠월날짜수 = 31;
        final int 팔월날짜수 = 31;
        final int 구월날짜수 = 30;
        final int 십월날짜수 = 31;
        final int 십일월날짜수 = 30;

        int sum = 0;

        switch (a) {
            case 12:
                sum += 십일월날짜수; //11
            case 11:
                sum += 십월날짜수; //10
            case 10:
                sum += 구월날짜수; //9
            case 9:
                sum += 팔월날짜수; // 8
            case 8:
                sum += 칠월날짜수; //7
            case 7:
                sum += 육월날짜수; //6
            case 6:
                sum += 오월날짜수; //5
            case 5:
                sum += 사월날짜수; //4
            case 4:
                sum += 삼월날짜수; //3
            case 3:
                sum += 이월날짜수; //2
            case 2:
                sum += 일월날짜수; //1
            case 1:
                sum += b;
                break;
        }

        int remainder = sum % 7;
        switch(remainder){
            case 1:
                return "FRI";
            case 2:
                return "SAT";
            case 3:
                return "SUN";
            case 4:
                return "MON";
            case 5:
                return "TUE";
            case 6:
                return "WED";
            case 0:
                return "THU";
        }

        return "";
    }

    public static void main(String[] args) {
        System.out.println(solution(1,1));
        System.out.println(solution(5,24));
    }
}
