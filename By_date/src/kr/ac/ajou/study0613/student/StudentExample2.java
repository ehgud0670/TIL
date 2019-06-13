package kr.ac.ajou.study0613.student;

import java.util.Arrays;

public class StudentExample2 {
    public static void main(String[] args) {
        Student gyu = new Student("함형규", 26);
        Student kim = new Student("김도형", 21);
        Student ho = new Student("최호권", 27);

        Student[] students = new Student[3];

        students[0] = gyu;
        students[1] = kim;
        students[2] = ho;

        System.out.println("Before sorting: ");
        for (Student student : students) {
            printStudentInfo(student);
        }

        //sorting
        Arrays.sort(students);

        System.out.println("After sorting: ");
        for (Student student : students) {
            printStudentInfo(student);
        }
    }

    private static void printStudentInfo(Student student) {
        System.out.println("\tname: " + student.getName() +
                " - age: " + student.getAge());
    }
}
