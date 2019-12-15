# Algo 7 
## ���� ���� 

��ȣ���� �����ϴ� ��¥ ������ ������ �̹����� �ߺ� ���ڸ� �̿��� ���ο� ��ȣ�� ��������ϴ�. ���� ��� "browoanoommaon" �̶�� ��ȣ���� ������ ���� ������ �ص��� �� �ֽ��ϴ�. 

```
1. "browoanoommnaon"
2. "browoannaon"
3. "browoaaon"
4. "browoon"
5. "brown"
```

������ ���ڿ� cryptogram�� �Ű������� �־��� ��, **�����ϴ� �ߺ� ���ڵ��� ������ ���**�� return �ϵ��� solution �޼��带 �ϼ����ּ���.

## ���ѻ���

* cryptogram�� ���̰� 1�̻� 1000������ ���ڿ��Դϴ�.
* cryptogram�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

## ����� ��

| cryptogram | result |
|------------|--------|
|"browoanoommnaon"|"brown"|
|"zyelleyz"|""|
| "zyellleyz" |""|
## ����� �� ���� 

����� �� #1
������ ���ÿ� �����ϴ�. 

����� �� #2 
������ ���� ������ �ص��� �� �ֽ��ϴ�. 

```java
1. "zyelleyz"
2. "zyeeyz"
3. "zyyz"
4. "zz"
5. ""
```

����� �� #3
������ ���� ������ �ص��� �� �ֽ��ϴ�. 
```java
1. "zyellleyz"
2. "zyeeyz"
3. "zyyz"
4. "zz"
5. ""
```


## �ڵ� 
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
