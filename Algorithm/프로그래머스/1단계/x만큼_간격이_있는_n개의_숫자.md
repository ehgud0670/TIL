## x만큼\_간격이\_있는\_n개의\_숫자

### 문제 설명

함수 solution은 정수 x와 자연수 n을 입력 받아, x부터 시작해 x씩 증가하는 숫자를 n개 지니는 리스트를 리턴해야 합니다. 다음 제한 조건을 보고, 조건을 만족하는 함수, solution을 완성해주세요.

### 제한 조건

* x는 -10000000 dltkd 10000000 이하인 정수입니다.
* n은 1000 이하인 자연수입니다. 

### 입출력 예

| x | n | answer       |
|---|---|--------------|
| 2 | 5 | [2,4,6,8,10] |
| 4 | 3 | [4,8,12] |
|-4 | 2 | [-4,-8] |


## 푸는 순서 

1. n의 길이를 가진 long 타입의 배열을 선언한다. 
2. long 타입의 변수를 하나 선언하고 x로 초기화한다.
3. for문을 0부터 n-1 번까지 배열에 2번의 변수를 대입하고 변수에 x를 더하면서 for문을 돌린다.

## 주의할 점 

* 함수의 리턴값이 long[] 이므로 리턴값에 들어갈 element의 타입을 **무조건 long으로 해야 한다.** int으로 두면 element의 값이 int의 범위보다 커지는 경우 **오버플로우가 나면서 제대로 된 값이 나오지 못하기 때문이다.** 


```java
import java.util.Arrays;

public class x만큼_간격이_있는_n개의_숫자 {
    public long[] solution(int x, int n) {
        long[] answer = new long[n];

        long k = x;
        int j = 0;
        for (int i = 0; i < n; i++) {

            answer[j++] = k;
            k += x;
        }


        return answer;
    }

    public static void main(String[] args) {
        x만큼_간격이_있는_n개의_숫자 test = new x만큼_간격이_있는_n개의_숫자();

        System.out.println(Arrays.toString(test.solution(2, 5)));
        System.out.println(Arrays.toString(test.solution(4, 3)));
        System.out.println(Arrays.toString(test.solution(-4, 2)));
    }
}

// 실행 결과 
// [2, 4, 6, 8, 10]
// [4, 8, 12]
// [-4, -8]
```
