package kr.ac.ajou.study0613;

public class Student implements Comparable<Student> {

    private String name;
    private int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 오름차순
    @Override
    public int compareTo(Student o) {
        if (this.age == o.age) {
            return 0;
        } else if (this.age > o.age) {
            return 1;
        } else {
            return -1;
        }
    }

    String getName() {
        return name;
    }

    int getAge() {
        return age;
    }
}
