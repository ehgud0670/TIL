# Comparable 말고 Comparator를 써야 한다.

#### 1.자기가 만든 것이 아닌, 가져다 쓰는 라이브러리라면 Comparable 사용 불가
#### 2. Comparable : 기존 코드 수정해야 함 =\> OCP 불만족 <br>  Comparator(비교자) : 기존 코드 수정 X =\> OCP 만족, **진보된 방식**

<br><br>
> Array.sort() , Colletcions.sort() 메소드들 중에는 공통적으로 Comparator를 공통적으로 인자로 
받아들이는 메소드들이 있다. 

```java
   // Arrays에 있는 sort() 메소드
   public static <T> void sort(T[] a, Comparator<? super T> c) 
   
   // Collections에 있는 sort() 메소드
   public static <T> void sort(List<T> list, Comparator<? super T> c)
```

=> Arrays.sort() 나 Collections.sort()를 사용할 때 보통 Comparator(비교자)를 주지 않고 클래스만 주게 되는데, 
이런 경우, 클래스가 Comparable를 구현하지 않았다면 **컴파일 에러**가 발생한다. 
<br>(1. Arrays, Collections 말고 직접 List의 sort()을 사용할 때는 클래스가 Comparable을 구현하고 있더라도 매개변수로
 Comparator가 없다면 **컴파일 에러**가 발생한다.
 <br>2. TreeSet의 객체나 TreeMap의 키가 될 클래스는 Comparable를 구현하고 있어야 한다. 그게 아니라면 런타임시 
 클래스가 TreeSet이나 TreeMap에 저장되자마자 **런타임에러**가 발생한다. Comparable 비구현 객체인데 에러가 
 나지 않게 하려면 TreeSet이나 TreeMap의 매개값으로 Comparator(비교자)를 넘겨주면 된다.) 



> Comparable 인터페이스 사용의 문제점.

* 정렬하는 기준을 바꿀 수 없거나 바꾼다해도 OCP에 부합하지 않는다.

그럼 Comparable을 구현한 객체를 통해 sort()를 사용하면 되는데, 하지만 이 방식의 문제점은 기존의 Comparable 
이 정렬하는 기준이 아닌 다른 기준을 통해 정렬을 할 수 없다는 것이다. 예를 들어 Student 라는 클래스가 있고 필드로
이름(String name), 나이(int age)가 있고 Comparable로 나이로 정렬한다고 하자. 그럼 정렬을 나이로는 할 수 있어도 
이름으로는 못하고, case by case 로 나이로 정렬하거나 이름으로 정렬하게 하려면 compareTo() 메소드에 if문을 넣어 코드를
작성해야 하는데 이는 수정에는 닫혀있지 않아 OCP에 만족하지 않는 방법이다. 

* 다른 개발자가 만든 클래스이거나 라이브러리를 내가 Comparable를 구현하거나 수정할 수 없다.  

또 자기가 만든 클래스가 아닌 라이브러리의 클래스를 사용한다면 readOnly 라서 Comparable의 compareTo()를
고치거나 새로 Comparable를 구현할 수 없어서 불편하다. 또 다른 개발자가 만든 클래스라면 그 클래스의 
Comparable의 compareTo() 메소드를 맘대로 고칠수가 없다. 

Comparable를 구현한 Student 클래스
```java
public class Student implements Comparable<Student> {

    private String name;
    private int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // 오름차순 : age를 기준으로
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
```

StudentExample.java
```java
public class StudentExample {
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
//실행결과
//Before sorting: 
//	name: 함형규 - age: 26
//	name: 김도형 - age: 21
//	name: 최호권 - age: 27
//After sorting: 
//	name: 김도형 - age: 21
//	name: 함형규 - age: 26
//	name: 최호권 - age: 27
// => 나이로 정렬된다.(Comparable)
```
**=> age 말고 다른 기준으로 정렬할 수 없고(ex: name), 상황에 따라 age와 name 다 정렬 할 수 있게 
<br>compareTo()에 if문을 작성한다 하더라도 이는 수정에 열려있어 OCP에 위배된다.**  

> Comparator : OCP 만족, 진보된 방식.

* OCP에 부합하고, 클래스가 Comparable을 구현한 클래스여도 매개값으로 Comparator를 주면 
Comparable은 무시되고 Comparator가 발현한다.

=> Comparator를 사용하면 정렬할 때마다 다른 기준으로 정렬할 수 있기 때문에 
Comparable의 compareTo()를 수정할 필요가 없다. 
즉 정렬할때 Comparator를 만들면 그만이고(Opended, 확장에 열려있다)
기존의 Comparable의 compareTo는 수정안해도 되서(Closed, 수정에 닫혀있다) 
OCP에 만족한다. 

* 라이브러리나 다른 개발자가 작성한 클래스를 Comparator를 통해 다른 기준으로 정렬 가능하다. 

=> Comparable은 라이브러리나 다른 개발자의 compareTo()를 고칠 수 없고, 
Comparable를 구현도 할 수 없는 문제점이 있었다. 하지만 Comparator는 내가 작성할 수 있고,
**내가 작성한 Comparator로 라이브러리나 다른 개발자의 것을 정렬할 수 있는 장점**이 있다. 

StudentNameComparator.java
```java
public class StudentNameComparator implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {
        //String
        String o1Name = o1.getName();
        String o2Name = o2.getName();

        return o1Name.compareTo(o2Name);
    }
}
```

StudentExample.java
```java
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
            printStudentInfo(student);
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
            printStudentInfo(student);
        }
        System.out.println();

    }
    private static void printStudentInfo(Student student) {
        System.out.println("\tname: " + student.getName() +
                " - age: " + student.getAge());
    }
}
//실행결과
//Comparable: 
//	name: 김도형 - age: 21
//	name: 함형규 - age: 26
//	name: 최호권 - age: 27
//
//Comparator: 
//	name: 김도형 - age: 21
//	name: 최호권 - age: 27
//	name: 함형규 - age: 26 
```

 
 


