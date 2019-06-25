package kr.ac.ajou.programmers.algo0619;

public class 전화번호_목록 {
    public boolean solution(String[] phone_book) {
        int len = phone_book.length;
        if(len == 1){
            return true;
        }

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                int iLen = phone_book[i].length();
                int jLen = phone_book[j].length();
                if(iLen > jLen){
                    if(phone_book[i].substring(0,jLen).equals(phone_book[j])){
                        return false;
                    }
                } else if(iLen < jLen){
                    if(phone_book[j].substring(0,iLen).equals(phone_book[i])){
                        return false;
                    }
                } else{
                    if(phone_book[i].equals(phone_book[j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String[] phone_book = {"119", "97"};

        전화번호_목록 test = new 전화번호_목록();
        System.out.println(test.solution(phone_book));
    }
}
