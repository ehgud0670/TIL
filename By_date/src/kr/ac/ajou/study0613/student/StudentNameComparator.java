package kr.ac.ajou.study0613;

import java.util.Comparator;

public class StudentNameComparator implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {
        //String
        String o1Name = o1.getName();
        String o2Name = o2.getName();

        return o1Name.compareTo(o2Name);
    }
}
