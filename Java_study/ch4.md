# chapter4
## 조건문과 반복문

### 조건문에서 if - else if - else 문 

```java
import java.util.Scanner;

public class Score {
    public static void main(String[] args) {
        int score;
        Scanner sc = new Scanner(System.in);

        score = sc.nextInt();

        if(score> 90)
            System.out.println('A');
        else if(score >80)
            System.out.println('B');
        else
            System.out.println('C');
    }
}
```

### 조건문에서 Switch문 
* if문과 비슷한데 case가 많은 경우 더 깔끔해서 사용한다. switch문의 괄호에는 정수타입이나 정수값을 산출하는 연산식, 문자, 문자열이 올 수 있다.  => boolean은 괄호에 올 수 없다. <br>


```java
public class SwitchExample {
    public static void main(String[] args) {
         int num = (int)(Math.random() * 6) + 1;  // Math.random()의 타입은 double 형.

         switch (num){
             case 1:
                 System.out.println("1번이 나옴.");
                 break;
             case 2:
                 System.out.println("2번이 나옴.");
                 break;
             case 3:
                 System.out.println("3번이 나옴.");
                 break;
             case 4:
                 System.out.println("4번이 나옴.");
                 break;
             case 5:
                 System.out.println("5번이 나옴.");
                 break;
             // default 는 else 와 같은 경우 이다. 따라서 6일때!
             default:
                 System.out.println("6번이 나옴.");
                     break;
         }

    }
}
```

### 반복문에서 for문

```java
int sum =0;
for(int i=1; i<=10; i++){
  sum +=i;

}
System.out.println(sum); // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55.
```

### 반복문에서 while문 

```java
int sum = 0;
int i = 1;
while(i<=10){
  sum += i;
  i++;
}
System.out.println(sum); // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55.
```

### 반복문에서 do-while문
* 처음 한번은 조건없이 반복문에 접근하는 do-while문.

```java
import java.util.Scanner;

public class DowhileExample {
    public static void main(String[] args) {
        System.out.println("메세지를 입력하세요.");
        System.out.println("종료하려면 q를 누르세요");

        String inputString;

        Scanner sc = new Scanner(System.in);

        do{
            System.out.print(">");
            inputString = sc.nextLine();
            System.out.println(inputString);
        }while(! inputString.equals("q") );

        System.out.println();
        System.out.println("프로그램 종료");
    }
}
```


### break문
* breka문 반복문인 for문 , while문 , do-while문을 실행 중지할 때 사용한다. (if문은 x!) 

### continue문

* continue문은 반복문인 for문, while문, do-while문에 사용되고, continue; 가 실행되면 조건식으로 올라간다. 

```java
public class ContinueExample {
    public static void main(String[] args) {
        for(int i =0; i<10; i++){
            if(i%2 == 0)  // i가 짝수면 조건문으로 올라간다.
              continue; 
            System.out.print(i + " ");  //1 3 5 7 9
        }
        System.out.println(); 
    }
}
```

