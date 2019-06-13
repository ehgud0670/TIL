package kr.ac.ajou.study0613.toString;

public class Point {

    private final int x;
    private final int y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String toString(){
        return "Point { " + "x=" + this.x +" , y= " +this.y +" }";
    }
}
