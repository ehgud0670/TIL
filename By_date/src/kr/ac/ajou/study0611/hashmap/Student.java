package kr.ac.ajou.study0611;

public class Student {
    private int sno;
    private String name;

    Student(int sno, String name) {
        this.sno = sno;
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Student) {
            Student student = (Student) obj;

            // 학번과 이름이 동일한 경우 true을 리턴
            return this.name.equals(student.name) && this.sno == student.sno;
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return this.sno + this.name.hashCode();
    }

    @Override
    public String toString() {
        return "{ sno : " + sno + " , name : " + name + "}";
    }
}
