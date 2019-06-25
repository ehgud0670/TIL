package kr.ac.ajou.study0613.hashcode;

public class Key {

    private int number;

    Key(int number) {
        this.number = number;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Key){
            Key key = (Key) obj;
            return this.number == key.number;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return number;
    }

    int getNumber() {
        return number;
    }
}
