package kr.ac.ajou.study0611.comparator;

// Comparable 인터페이스를 구현하지 않은 Fruit 클래스
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
