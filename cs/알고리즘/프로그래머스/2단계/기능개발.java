
import java.util.*;

public class 기능개발 {
	private static final int COMPLETE = 100;
	private static final int FIRST = 0;

	class Develop {

		int progress;
		int speed;

		Develop(int progress, int speed) {
			this.progress = progress;
			this.speed = speed;

		}

		void doDevelop() {
			this.progress += speed;

		}

		boolean checkCompleted() {
			if (this.progress >= COMPLETE) {
				return true;
			} else {
				return false;
			}
		}
	}

	void removeRecursively(List<Develop> list, HashMap<Integer, Integer> answerMap, int index) {
		if (list.size() != 0) {
			Develop first = list.get(FIRST);
			if (first.checkCompleted()) {
				list.remove(FIRST);
				answerMap.put(index, answerMap.getOrDefault(index, 0) + 1);
				removeRecursively(list, answerMap, index);
			}
		}
	}

	public int[] solution(int[] progresses, int[] speeds) {
		int len = progresses.length;
		List<Develop> list = new ArrayList<>();
		for (int i = 0; i < len; i++) {
			list.add(new Develop(progresses[i], speeds[i]));
		}

		HashMap<Integer, Integer> answerMap = new HashMap<>();
		while (!list.isEmpty()) {
			int index = answerMap.size();
			removeRecursively(list, answerMap, index);

			for (Develop develop : list) {
				if (!develop.checkCompleted()) {
					develop.doDevelop();
				}
			}

		}
		int size = answerMap.size();
		int[] answer = new int[size];
		
		Collection<Integer> co =  answerMap.values();
		int i=0;
		for(int num: co) {
			answer[i++] = num; 
		}
		return answer;
	}

	public static void main(String[] args) {
		기능개발 test = new 기능개발();
		int[] progresses = { 93, 30, 55 };
		int[] speeds = { 1, 30, 5 };
		System.out.println(Arrays.toString(test.solution(progresses, speeds)));
	}

}
