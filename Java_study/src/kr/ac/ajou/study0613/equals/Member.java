package kr.ac.ajou.study0613.equals;


public class Member {
    private String id;

    Member(String id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Member) {
            Member member = (Member) obj;
            return this.id.equals(member.id);
        }
        return false;
    }
}
