package ac.kr.ajou.item06;

public class StringTest2 {
    public static void main(String[] args) {
        Boolean true1 = Boolean.valueOf("true");
        Boolean true2 = Boolean.valueOf("true");


        // Don't use this!
//        Boolean true3 = new Boolean("true");

        System.out.println(true1 == true2);
        System.out.println(true1 == Boolean.TRUE);

    }

}
