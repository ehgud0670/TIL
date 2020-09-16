# N으로 표현

dp의 f(n)의 정의는 이러하다.

```
N을 n번 썼을 때 나올 수 있는 숫자들의 집합(Set)
```

N이 5라고 하자. 그럼 f(1)은 5 하나이다. 
그럼 f(2)는 어떻게 구할까 

```
5를 2개 이어붙인 55, 그리고 f(1) + f(2 - 1), f(1) - f(2 - 1), f(1) * f(2 - 1), f(1) / f(2 - 1)

// {55, 10, 0, 25, 1}
```

그렇다. 5를 2개 이어붙인 55와 f(1)과 f(2 - 1)의 사칙연산해서 나온 숫자들의 집합이 f(2)이다. 

따라서 f(n) 을 구하는 방법은 

```
f(n) = `N을 n번 이어붙인 수` + for pivot in 1 ..< n { f(pivot) (사칙연산) f(n - pivot) }
```
이다. 

이렇게 해서 number를 원소로 가지는 집합을 가진 최소의 n을 리턴한다. 
근데 n이 1부터 8까지의 집합 중에 number가 없다면 -1을 리턴한다. 

```swift
func N으로표현(_ N:Int, _ number:Int) -> Int {
    var dp = [Int: Set<Int>]()
        
    var s = ""
    for n in 1 ... 8 {
        dp[n] = Set<Int>()
            
        s += String(N)
        dp[n]!.insert(Int(s)!)
    }
        
    for n in 2 ... 8 {
        for pivot in 1 ..< n {
            let j = n - pivot
            let iSet = dp[pivot]!
            let jSet = dp[j]!
                
            for ie in iSet {
                for je in jSet {
                    dp[n]!.insert(ie + je)
                    dp[n]!.insert(ie - je)
                    dp[n]!.insert(ie * je)
                        
                    if je != 0 {
                        dp[n]!.insert(ie / je)
                    }
                }
            }
        }
    }
        
    let sorted = dp.sorted { $0.key < $1.key }
    for i in 0 ..< sorted.count {
        guard sorted[i].value.contains(number) else { continue }
        return sorted[i].key
    }
        
    return -1
}
```