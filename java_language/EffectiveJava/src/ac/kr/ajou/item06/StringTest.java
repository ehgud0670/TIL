package ac.kr.ajou.item06;

public class StringTest {
    public static void main(String[] args) {

        // Not collect
        String str1 = new String("hello");
        String str2 = new String("hello");

        System.out.println(str1 == str2);
        System.out.println(str1.equals(str2));

        // collect
        String str3 = "hello";
        String str4 = "hello";

        System.out.println(str3 == str4);
        System.out.println(str3.equals(str4));

    }
}
