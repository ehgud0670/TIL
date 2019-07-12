package ac.kr.ajou.item06;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class UsingKeySet {

    public static void main(String[] args) {
        Map<String, Integer> menu = new HashMap<>();
        menu.put("Burger", 8);
        menu.put("Pizza", 9);

        //keySet() 이 호출될 때 마다 새로운 인스턴스가 생성되는 것이 아니라
        //매번 같은 인스턴스가 반환됨을 알 수 있다.
        Set<String> name1 = menu.keySet();
        Set<String> name2 = menu.keySet();

        System.out.println("Before");
        System.out.println("name1's size: " + name1.size());
        System.out.println("name2's size: " + name2.size());

        // 객체 menu 와 name1, name2는 같은 자원을 바라보고 있으므로(menu와  name1 사이는 key만 같은 자원이다),
        // 추가 되면 같이 추가되고 삭제되면 같이 삭제된다.
        // => 이 방법은 좋지 않으므로, Set을 카피하는 것이 안전한 방법이다. => Defensive copy.
        //name1.remove("Burger");
        menu.remove("Burger");

        System.out.println("After");
        System.out.println("name1's size: " + name1.size());
        System.out.println("name2's size: " + name2.size());


    }
}
