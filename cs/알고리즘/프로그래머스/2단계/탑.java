
import java.util.*;

public class 탑 {
	public int[] solution(int[] heights) {
		int len = heights.length;

		Stack<Integer> stack = new Stack<>();

		for (int height : heights) {
			stack.push(height);
		}

		int[] answer = new int[len];
		int index = len-1;
	
		while (stack.size() != 0) {

			int height = stack.pop();
			int size = stack.size();
			boolean check =false;
			for (int i = size - 1; i >= 0; i--) {
				if (stack.elementAt(i) > height) {
					answer[index--] = i+1;
					check = true;
					break;
				}
			}
			if(!check) {
				answer[index--] = 0;
			}
		}

		return answer;
	}

	public static void main(String[] args) {
		탑 test = new 탑();
		int[] heights = { 6, 9, 5, 7, 4 };
		System.out.println(Arrays.toString(test.solution(heights)));
	}
}
