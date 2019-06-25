package kr.ac.ajou.programmers.algo0619;

public class H_Index {

    public int solution(int[] citations) {

        int n = citations.length;

        for (int h = n; h > 0; h--) {
            int yesCount = 0;
            int noCount = 0;
            for (int citation : citations) {
                if (citation >= h) {
                    yesCount++;
                } else {
                    noCount++;
                }
            }
            if(yesCount>=h && noCount<h){
                return h;
            }
        }

        return 0;
    }

    public static void main(String[] args) {

        H_Index test = new H_Index();

        int[] citations = {3, 0, 6, 1, 5};
        System.out.println(test.solution(citations));
    }
}
