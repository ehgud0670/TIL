package kr.ac.ajou.study0611;

public class Person implements Comparable<Person> {

    private int age;

    Person(int age) {
        this.age = age;
    }


    @Override
    public int compareTo(Person o) {
        if (this.age > o.age) {
            return 1;
        } else if (this.age == o.age) {
            return 0;
        } else {
            return -1;
        }
    }
}
