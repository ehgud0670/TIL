
import java.util.*;

public class 주식가격 {
	public int[] solution(int[] prices) {
		int[] answer = new int[prices.length]; 
		Queue<Integer> queue = new LinkedList<>();
		for(int price : prices) {
			queue.add(price);
		}
		
		int i = 0;
		while(!queue.isEmpty()) {
			
			int price = queue.poll();
			
			boolean check = false;
			int count = 1;
			for(int otherPrice : queue ) {
				if(price > otherPrice) {
					answer[i++] = count; 
					check = true;
					break;
				}
				count++;
			}
			if(!check) {
				answer[i++] = queue.size(); 
			}
		}
		
	      
	   return answer;
	}
	
	public static void main(String[] args) {
		
		주식가격 test = new 주식가격();
		
		int[] prices = {5,4,3,4,5};
		
		System.out.println(Arrays.
				toString(test.solution(prices)));
		
		
	}
}
