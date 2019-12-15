
import java.util.*;

public class 쇠막대기 {

	public int solution(String arrangement) {

		char[] chars = arrangement.toCharArray();
		int len = chars.length;

		Stack<Integer> openBraceStack = new Stack<>();
		List<Integer> lazerIndex = new ArrayList<>();

		int count = 0;
		for (int i = 0; i < len; i++) {

			if (chars[i] == '(') {
				if (chars[i + 1] == ')') {
					lazerIndex.add(i);
				} else {
					openBraceStack.push(i);
				}
			} else if (chars[i] == ')') {
				if (chars[i - 1] == '(') {
					continue;
				}
				count += 1;
				int openIndex = openBraceStack.pop();
				int closeIndex = i;
				for (int index : lazerIndex) {
					if (index > openIndex && index < closeIndex) {
						count++;
					}
				}
			}

		}

		return count;
	}

	public static void main(String[] args) {
		쇠막대기 test = new 쇠막대기();

		String arrangement = "()(((()())(())()))(())";

		System.out.println(test.solution(arrangement));
	}
}
