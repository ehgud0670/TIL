import java.util.*;

public class 가장_큰_수 {
	
	class StringComparator implements Comparator<String>{

		@Override
		public int compare(String o1, String o2) {
			String o1o2 = o1 + o2;
			String o2o1 = o2 + o1;
			
			return -o1o2.compareTo(o2o1);
		}
		
	}
	
	
    public String solution(int[] numbers) {
    	
    	int len = numbers.length;
    	
    	String[] nums = new String[len];
    	int i=0;
    	for(int num : numbers) {
    		nums[i++] = String.valueOf(num);  
    	}
    	Arrays.sort(nums,new StringComparator());
    
    	
    	
        if(nums[0].charAt(0) == '0') {
        	return "0";
        } else {
           StringBuilder answer= new StringBuilder();
            for(String num : nums) {
            	answer.append(num);
            }
            return answer.toString();
        }
    }
    
	public static void main(String[] args) {
		
		int[] numbers = {0,0,0,0};
		int[] numbers2 = {3, 30, 34, 5, 9};
		
		
		가장_큰_수 test = new 가장_큰_수();
		
		System.out.println(test.solution(numbers));
		System.out.println(test.solution(numbers2));
	}
}
