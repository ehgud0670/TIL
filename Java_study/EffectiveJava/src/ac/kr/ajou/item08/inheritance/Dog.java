package ac.kr.ajou.item08.inheritance;

class Dog extends Animal {

    Dog() {
        System.out.println("constructor");
        throw new RuntimeException();
    }

    @Override
    protected void finalize() throws Throwable {
        Animal.animal = this;
        naked();
    }
}
