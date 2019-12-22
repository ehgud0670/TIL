package kr.ac.ajou.study0611.comparator;

import java.util.TreeSet;

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
