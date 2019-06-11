# Comparable & Comparator

* TreeSet의 객체와 TreeMap의 키는 **저장과 동시에 자동 오름차순으로 정렬**되는데, 
숫자(Integer, Double) 타입일 경우에는 값을, 문자열(String)타입일 경우 유니코드로 오름차순으로 정렬한다.
TreeSet과 TreeMap은 정렬을 위해 java.lang.Comparable을 구현한 객체를 요구하는데, 
Integer, Double, String은 모두 Comparable 인터페이스를 구현하고 있다. 사용자 정의 클래스도 
Comparable을 구현한 클래스라면 TreeSet의 객체나 TreeMap의 키로서 저장가능한데, 
Comparable를 구현하지 않는다면 저장하는 순간 ClassCastException(런타임 에러)이 발생한다.
<br> 그렇다면, Comparable 비구현 객체를 정렬하는 방법은 없을까?  
TreeSet 또는 TreeMap 생성자의 매개값으로 정렬자(Comparator)를 제공하면 
Comparable 비구현 객체도 정렬시킬 수 있다. 


> Comparable 인터페이스 

* Comparable에는 compareTo() 메소드가 정의되어 있기 때문에 사용자 정의 클래스에는 이 메소드를 오버라이딩하여 다음과 같이 리턴값을 만들어 내야 한다. 
 
| 리턴 타입 |    메소드   |  설명                         |
|-----------|-------------|-------------------------------|
| int  | compareTo(T o) | 주어진 객체와 같으면 0을 리턴 <br>주어진 객체보다 작으면 음수를 리턴 <br> 주어진 객체보다 크면 양수를 리턴 | 

=> 규칙이다. 규칙에 따라 오버라이딩 할 수 있도록 한다.
<br>만약 설명대로 리턴 타입을 오버라이딩하지 않고 엉뚱하게 리턴타입을 준다면 정렬이 Comparable를 구현한것처럼 되지 않고
엉뚱하게 될 것이다. **따라서 반드시 설명대로 오름차순으로 짜거나 아니면 내림차순으로 리턴값을 나오게 로직을 짜도록 하자.**


<br>나이가 적을 경우 -1을,  동일한 경우는 0을, 클 경우는 1을 리턴하도록 하는 
<br>Comparable을 구현한 Person 클래스
```java
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
    
    @Override
    public String toString() {
        return "{ name: " + this.name + ",  age: " + this.age + "}";
    }
    
}
``` 

PersonExample
```java
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
// 실행 결과
//{ name: Gyu,  age: 27}
//{ name: Kim,  age: 30}
//{ name: Ho,  age: 44}
```

> Comparator 인터페이스

* TreeSet 또는 TreeMap 생성자의 매개값으로 정렬자(Comparator)를 
제공하면 Comparable 비구현 객체도 정렬시킬 수 있다.

```java
// 오름차순 또는 내림차순 Comparator
TreeSet<E> treeSet = new TreeSet<>( new XXXAscendingComparator());
TreeMap<K,V> treeMap = new TreeMap<>(new XXXDescendingComparator());
```
  
정렬자는 Comparator 인터페이스를 구현한 객체를 말하는데, 
Comparator 인터페이스에는 다음과 같이 메소드가 정의되어 있다. 

| 리턴 타입 | 메소드              | 설명                                         |
|-----------|---------------------|----------------------------------------------|
| int | compare(T o1, T o2)       | o1과 o2가 동등하다면 0을 리턴<br>o1이 o2보다 앞에 오게하려면 음수를 리턴<br>o1이 o2보다 뒤에 오게 하려면 양수를 리턴 | 

=> compare() 메소드는 비교하는 두 객체가 동등하면 0,
 비교하는 값보다 앞에 오게 하려면 음수, 
 뒤에 오게 하려면 양수를 리턴하도록 구현하면 된다. 
 
 <br>Fruit 클래스의 내림차순 정렬자 DescendingComparator.  
 ```java
public class DescendingComparator implements Comparator<Fruit> {
    @Override
    public int compare(Fruit o1, Fruit o2) {
        if(o1.getPrice() == o2.getPrice()){
            return 0;
        } else if(o1.getPrice() > o2.getPrice()){
            return -1;
        } else{
            return 1;
        }
    }
}
```

<br>Comparable 인터페이스를 구현하지 않은 Fruit 클래스
```java
class Fruit {

    private String name;
    private int price;

    Fruit(String name, int price) {
        this.name = name;
        this.price = price;
    }

    int getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "{ name: " + this.name + " price: " + this.price + "}";
    }
}
```

<br>FruitExample
```java
public class FruitExample {
    public static void main(String[] args) {
        Fruit apple = new Fruit("사과", 1000);
        Fruit banana = new Fruit("바나나", 2000);
        Fruit mango = new Fruit("망고", 3000);


        DescendingComparator fruitDescendingComparator = new DescendingComparator();
        TreeSet<Fruit> fruits = new TreeSet<>(fruitDescendingComparator);


        fruits.add(apple);
        fruits.add(banana);
        fruits.add(mango);


        for (Fruit fruit : fruits) {
            System.out.println(fruit.toString());
        }

    }
}
// 실행 결과 
//{ name: 망고 price: 3000}
//{ name: 바나나 price: 2000}
//{ name: 사과 price: 1000}
```



> Comparable 보단 Comparator를 써야 한다.

=> to be Continue... 