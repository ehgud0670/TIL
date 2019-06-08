package ac.kr.ajou.item07;

import java.util.Arrays;
import java.util.EmptyStackException;

public class Stack {
    private Object[] elements;
    private int size = 0;
    private static final int DEFAULT_INITIAL_CAPACITY = 16;

    public Stack() {
        elements = new Object[DEFAULT_INITIAL_CAPACITY];
    }

    public void push(Object e) {
        ensureCapacity();
        elements[size++] = e;
    }





//   제대로 구현되지 않은 pop() 메소드: 다 쓴 참조(obsolete reference)가 있어
//   가비지 컬렉터(GC)가 객체를 회수하지 않고 결국 메모리 누수가 발생한다.
// NOTE: 스택에 계속 쌓다가 많이 빼냈다고 치자. 그래도 스택이 차지하고 있는 메모리는 줄어들지 않는다.
//  왜냐하면 저 스택의 구현체는 필요없는 객체에 대한 참조를 그대로 가지고 있기 때문이다.
//  (기본 스택의 길이가 pop()해도 계속 정해져있으므로) 가용한 범위(활성 영역)는 size 보다 작은 부분이고
//  그 값보다 큰 부분에 있는 값들은 필요없이 메모리를 차지하는 부분이다.( => 메모리 누수 발생)
    public Object pop() {
        if (size == 0) {
            throw new EmptyStackException();
        }
        return elements[--size];
    }

    // 제대로 구현한 pop() 메소드 : 메모리 누수가 나지 않는다.
    public Object pop2() {
        if (size == 0) {
            throw new EmptyStackException();
        }
        Object result = elements[--size];
        elements[size] = null; // 다 쓴 참조 해제.
        return result;
    }

    /*
     * 원소를 위한 공간을 적어도 하나 이상 확보한다. => +1
     * 배열 크기를 늘려야 할 때마다 대략 두 배씩 늘린다.
     */
    private void ensureCapacity() {
        if (elements.length == size) { // size 는 인덱스.
            elements = Arrays.copyOf(elements, 2 * size + 1);
        }
    }
}