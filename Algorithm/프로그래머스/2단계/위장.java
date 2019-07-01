import java.util.*;

public class 위장 {
	
	   public int solution(String[][] clothes) {
		   if(clothes.length == 1) {
			   return 1;
		   }
		   
		   	HashMap<String,Integer> hashMap = new HashMap<>();
		   	for(String[] cloth : clothes) {
		   		String kind = cloth[1];
		   		hashMap.put(kind, hashMap.getOrDefault(kind, 0) + 1);
		   	}
		   	
		   	Collection<Integer> co = hashMap.values();
		   	
		   	int sum = 1;
		   	for(int num : co) {
		   		sum *= (num+1);
		   	}
		   	sum -=1;
		   	
	        return sum;
	    }
	
		public static void main(String[] args) {
			
			위장 test = new 위장();
			
			String[][] clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
			System.out.println(test.solution(clothes));
			
		}
}
