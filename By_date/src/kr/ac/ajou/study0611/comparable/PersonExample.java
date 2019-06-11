package kr.ac.ajou.study0611.comparable;

import java.util.Set;
import java.util.TreeSet;

public class PersonExample {

    public static void main(String[] args) {
        Person kim = new Person("Kim", 30);
        Person gyu = new Person("Gyu", 27);
        Person ho = new Person("Ho", 44);

        TreeSet<Person> personSet = new TreeSet<>();
        personSet.add(kim);
        personSet.add(gyu);
        personSet.add(ho);

        for (Person person : personSet) {
            System.out.println(person.toString());
        }

    }
}
