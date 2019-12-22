# item 6
## 불필요한 객체 생성을 피하라

```java
String s = new String("bikini"); // 따라 하지 말 것! 
String s = "bikini";
```


<br>성능을 훨씬 더 끌어올릴 수 있다!
```java
static boolean isRomanNumeral(String s){
  return s.matches("^(?=.)M*(C[MD]|D?C{0,3})" 
  + "(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$");
}
```

<br>값비싼 객체를 재사용해 성능을 개선한다. 
```java
public class RomanNumerals{
    private static final Pattern ROMAN = Pattern.compile(
            "^(?=.)M*(C[MD]|D?C{0,3})" 
              + "(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$");
    static boolean isRomanNumeral(String s){
        return ROMAN.matcher(s).matches();
    }
}
``` 


<br>끔찍이 느리다! 객체가 만들어지는 위치를 찾았는가?
```java
private static long sum(){
    Long sum = 0L;
    for(long i = 0; i <= Integer.MAX_VALUE; i++){
        sum += i;
    }
    
    return sum;
}
```


