### FizzBuzz

* 인프런 곰튀김님 함수형 프로그래밍 영상을 보고 흔적을 남긴다. 

```swift
extension FP {
    func fizzbuzz_nonFP() {
        var i = 1
        while i <= 100 {
            if i % 3 == 0 && i % 5 == 0 {
                print("fizzbuzz")
            }
            else if i % 3 == 0 {
                print("fizz")
            }
            else if i % 5 == 0 {
                print("buzz")
            }
            else {
                print(i)
            }
            i += 1
        }
    }
    
    static let fizz = { $0 % 3 == 0 ? "fizz" : "" }
    static let buzz = { $0 % 5 == 0 ? "buzz" : "" }
    static let fizzbuzz: (Int) -> String = { i -> String in
        let ff: (Int, String) -> String = { i , str in
            return str.isEmpty ? "\(i)" : str
        }
        
        return ff(i, fizz(i) + buzz(i))
    }
    static let loop: (Int, Int, (Int) -> String) -> Void = { min, max, f in
        (min ... max).forEach { print(f($0))}
    }
}
```