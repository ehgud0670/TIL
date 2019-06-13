package kr.ac.ajou.study0613.equals;

public class MemberExample {
    public static void main(String[] args) {
        Member member1 = new Member("Bob");
        Member member2 = new Member("Bob");
        Member member3 = new Member("Jason");

        System.out.println(member1.equals(member2));
        System.out.println(member1.equals(member3));

    }
}
