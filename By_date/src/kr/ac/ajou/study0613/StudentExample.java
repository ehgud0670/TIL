package kr.ac.ajou.study0613;


import java.util.TreeSet;

public class StudentExample {

    public static void main(String[] args) {
        TreeSet<Student> case1 = new TreeSet<>();
        Student gyu = new Student("함형규", 26);
        Student kim = new Student("김도형", 21);
        Student ho = new Student("최호권", 27);

        case1.add(gyu);
        case1.add(kim);
        case1.add(ho);

        System.out.println("Comparable: ");
        for (Student student : case1) {
            System.out.println("\tname: " + student.getName() +
                    " - age: " + student.getAge());
        }
        System.out.println();


        // 클래스가 comparable 인터페이스를 구현하더라도 Comparator를 사용할 수 있고,
        // 이 때 comparable의 compareTo()는 무시되고, 비교자를 통해 정렬된다.
        StudentNameComparator studentNameComparator = new StudentNameComparator();
        TreeSet<Student> case2 = new TreeSet<>(studentNameComparator);
        case2.add(gyu);
        case2.add(kim);
        case2.add(ho);

        System.out.println("Comparator: ");
        for (Student student : case2) {
            System.out.println("\tname: " + student.getName() +
                    " - age: " + student.getAge());
        }
        System.out.println();

        // note :  String 은  유니코드 깂을 기준으로 오름차순 자동 정렬된다.
        System.out.println("String's Comparable test: ");
        TreeSet<String> case3 = new TreeSet<>();
        case3.add("a");
        case3.add("A");

        for (String str : case3) {
            System.out.println("\t"+str);
        }


    }
}
