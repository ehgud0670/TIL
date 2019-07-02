## K번째 수 

### 문제 설명

배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.
<br>예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면 

1. array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
2. 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
3. 2에서 나온 배열의 3번째 숫자는 5입니다.

배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.


### 제한 사항

* array의 길이는 1 이상 100 이하입니다.
* array의 각 원소는 1 이상 100 이하입니다.
* commands의 길이는 1 이상 50 이하입니다.
* commands의 각 원소는 길이가 3입니다.

### 입출력 예

| array | commands | return |
|----------------|---------------------------|---------|
|[1,5,2,6,3,7,4] | [[2,5,3],[4,4,1],[1,7,3]] | [5,6,3] | 

### 입출력 예 설명 

* [1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
* [1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
* [1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.

## 푸는 방법

1. int len = commands.length;으로 하여 총 command의 개수를 구하고 이를 토대롤 int[] answer = new int[len]; 을  선언한다.
2. for문을 이용해 commands의 각 command를 가져온 뒤 각 i,j,k를 -1 하여 index화 한다.
3. for문안에 ArrayList를 생성해 i번째부터 j번째까지 해당하는 수들만 add 한다.
4. 그리고 ArrayList의 k번째 원소를 반환하여 answer라는 배열에 차곡차곡 추가하고 이 answer라는 배열을 최종 반환한다.  


```java
import java.util.*;

public class K번째_수 {

    public int[] solution(int[] array, int[][] commands) {
        int len = commands.length;
        int[] answer = new int[len];

        int i = 0;
        for(int[] command : commands){
            // command의 각 값들을 인덱스화 하기 : -1 빼준다.
            int start = command[0] -1; // inclusive
            int end = command[1] -1;  // inclusive
            int K = command[2] -1 ;

            List<Integer> list = new ArrayList<>();
            for(int j= start; j<= end; j++){
                list.add(array[j]);
            }
            Collections.sort(list);

            int element = list.get(K);
            answer[i++] = element;
        }

        return answer;
    }

    public static void main(String[] args) {
        K번째_수 test = new K번째_수();

        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};


        System.out.println(Arrays.toString(test.solution(array,commands)));
    }
}
```
