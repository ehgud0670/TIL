import java.util.*;

public class 다리를_지나는_트럭 {

	class Truck {

		int weight;
		int amount;

		Truck(int weight, int amount) {

			this.weight = weight;
			this.amount = amount;
		}

		void minusAmount() {
			this.amount -= 1;
		}
	}

	public int solution(int bridge_length, int weight, int[] truck_weights) {
		int seconds = 0;
		int amount = bridge_length;

		Queue<Integer> queue = new LinkedList<>();
		for (int truck_weight : truck_weights) {
			queue.offer(truck_weight);
		}

		int sum = 0;
		List<Truck> trucks = new ArrayList<>();
		while (true) {

			// 다리에서 다리로
			boolean check = false;
			for (Truck truck : trucks) {
				truck.minusAmount();
				if (truck.amount == 0) {
					check = true;
				}
			}
			if (check) {// check = true 이면 다리에서 건너기.
				sum -= trucks.remove(0).weight;
			}

			// 무게가 만족되면 다리 건너기
			if (!queue.isEmpty()) {
				if (sum + queue.peek() <= weight) {
					int targetWeight = queue.poll();
					sum += targetWeight;
					trucks.add(new Truck(targetWeight, amount));
				}
			}
			seconds++;

			if (trucks.size() == 0) {
				break;
			}

		}

		return seconds;
	}

	public static void main(String[] args) {
		다리를_지나는_트럭 test = new 다리를_지나는_트럭();

		System.out.println(test.solution(2, 10, new int[] { 7, 4, 5, 6 }));
		System.out.println(test.solution(100, 100, new int[] { 10 }));
		System.out.println(test.solution(100, 100, new int[] { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }));
	}
}
