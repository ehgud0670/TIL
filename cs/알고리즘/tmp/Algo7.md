# Algo 7 
## 문제 설명 

암호문을 좋아하는 괴짜 개발자 브라운이 이번에는 중복 문자를 이용한 새로운 암호를 만들었습니다. 예를 들어 "browoanoommaon" 이라는 암호문은 다음과 같은 순서로 해독할 수 있습니다. 

```
1. "browoanoommnaon"
2. "browoannaon"
3. "browoaaon"
4. "browoon"
5. "brown"
```

임의의 문자열 cryptogram이 매개변수로 주어질 때, **연속하는 중복 문자들을 삭제한 결과**를 return 하도록 solution 메서드를 완성해주세요.

## 제한사항

* cryptogram은 길이가 1이상 1000이하인 문자열입니다.
* cryptogram은 알파벳 소문자로만 이루어져 있습니다.

## 입출력 예

| cryptogram | result |
|------------|--------|
|"browoanoommnaon"|"brown"|
|"zyelleyz"|""|
| "zyellleyz" |""|
## 입출력 예 설명 

입출력 예 #1
문제의 예시와 같습니다. 

입출력 예 #2 
다음과 같은 순서로 해독할 수 있습니다. 

```java
1. "zyelleyz"
2. "zyeeyz"
3. "zyyz"
4. "zz"
5. ""
```

입출력 예 #3
다음과 같은 순서로 해독할 수 있습니다. 
```java
1. "zyellleyz"
2. "zyeeyz"
3. "zyyz"
4. "zz"
5. ""
```


## 코드 
```java
 //use Stack
    public String solution(String cryptogram) {
        Stack<Character> stack = new Stack<>();
        char[] chars = cryptogram.toCharArray();

        int i = 0;
        int len = chars.length;
        while (true) {
            if (i >= len) {
                break;
            }
            if (stack.size() == 0) {
                stack.push(chars[i]);
            } else {
                char com1 = stack.peek();
                if (com1 == chars[i]) {
                    stack.pop();
                    i = i + getK(com1, i + 1, chars, len);
                } else {
                    stack.push(chars[i]);
                }
            }
            i++;
        }
        StringBuilder builder = new StringBuilder();
        while (true) {
            int size = stack.size();
            if (size == 0) {
                break;
            }
            builder.insert(0, stack.pop());
        }
        return builder.toString();
    }

    private int getK(char com1, int i, char[] chars, int len) {
        if (i >= len) {
            return 0;
        }

        if (com1 == chars[i]) {
            return 1 + getK(com1, i + 1, chars, len);
        } else {
            return 0;
        }
    }
```
