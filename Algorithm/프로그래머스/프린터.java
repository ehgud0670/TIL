
import java.util.*;

public class 프린터 {
	
	public int solution(int[] priorities, int location) {
		int count = 0;
		List<Integer> list = new ArrayList<>();
	   for(int priority: priorities) {
		   list.add(priority);
	   }
	   
	   while(list.size()!=0) {
		   boolean check = false;
		   int target = list.remove(0);
		   for(int i=0; i<list.size();i++) {
			   if(target < list.get(i)) {
				   check = true;
				   list.add(target);
				   break;
			   }
		   }
		   if(!check) {
			   if(location == 0) {
				   return ++count;
			   }
			   ++count;
			  
		   }
		   location -=1;
		   if(location < 0) {
			   location = list.size()-1;
		   }
		   
	   }
	   
	   return 1000;
    }
	
	
	public static void main(String[] args) {
		프린터 test = new 프린터();
		
		
		int[] priorities = {2, 1, 3, 2};
		int location = 2;
	
		
		System.out.println(test.solution(priorities, location));
	
		int[] priorities2 = {1, 1, 9, 1, 1, 1};
		int location2 = 0;
		
		System.out.println(test.solution(priorities2, location2));
	}
}
