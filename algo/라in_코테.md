### Solution1

```swift
func Sol1(_ boxes:[[Int]]) -> Int {
        var bCount = boxes.count
        
        var dic = [Int: Int]()
        for box in boxes {
            for e in box {
                if dic[e] == nil {
                    dic[e] = 1
                    continue
                }
                
                dic[e]! += 1
            }
        }
        
        var arr = dic.sorted { $0.value > $1.value }
        var answer = 0
        while bCount != 0 {
            arr = arr.sorted { $0.value > $1.value }
            for i in 0 ..< arr.count {
                let v = arr[i].value
                let q = v / 2
                bCount -= q
                if bCount == 0 {
                    break
                }

                let r = v % 2
                arr[i].value = r
                
                if arr[i].value == 1 {
                    answer += 1
                    bCount -= 1
                    arr[i].value = 0
                    
                    if bCount == 0 {
                        break
                    }
                }
            }
        }
        
        return answer
}
```

### Solution2

```swift
func Sol2(_ ball:[Int], _ order:[Int]) -> [Int]  {
        var priArr = [(pri: Int, val: Int)]()
        for (i,v) in order.enumerated() {
            priArr.append((pri: i, val: v))
        }
        
        var ball = ball
        var answer = [Int]()
        while priArr.count != 0 {
            for i in 0 ..< priArr.count {
                guard priArr[i].val == ball.first || priArr[i].val == ball.last else {
                    continue
                }
                
                if priArr[i].val == ball.first {
                    let n = ball.removeFirst()
                    priArr.remove(at: i)
                    answer.append(n)
                    break
                }
                
                if priArr[i].val == ball.last {
                    let n = ball.removeLast()
                    priArr.remove(at: i)
                    answer.append(n)
                    break
                }
            }
        }
        
        return answer
}
```

### Solution3

```swift
func Sol3(_ n:Int) -> [Int] {
        var n = n
        var count = 0
        while n / 10 != 0 {
            count += 1
            
            let numStr = String(n)
            let startIndex = numStr.startIndex
            let lastIndex = numStr.index(numStr.endIndex, offsetBy: -1)
            
            var min = Int.max
            for i in 0 ..< numStr.count - 1 {
                let index = numStr.index(startIndex, offsetBy: i)
                let prefix = numStr[startIndex...index]
                if prefix.first == "0" {
                    continue
                }
                let pre = Int(prefix)!
                
                let nextIndex = numStr.index(index, offsetBy: 1)
                let suffix = numStr[nextIndex...lastIndex]
                if suffix.count > 1 {
                    if suffix.first == "0" {
                        continue
                    }
                }
                
                let su = Int(suffix)!
                
                let sum = pre + su
                if sum < min {
                    min = sum
                }
            }
            n = min
        }
        
        return [count, n]
    }
```


### Solution6

```swift
class C: CustomStringConvertible {
        var description: String {
            return "\(name)_\(sortSelected.joined())"
        }
        
        let name: String
        var aps: [String]
        var count: Int
        var request = [String: A]()
        var selected = [String: A]()
        var sortSelected = [String]()
        
        init(_ s: String) {
            let split = s.components(separatedBy: " ")
            self.name = split[0]
            self.aps = split[1].map { String($0) }
            self.count = Int(split[2])!
        }
    }
    
    class A: CustomStringConvertible {
        var description: String {
            return "[\(name), \(isSelected)]"
        }
        
        let name: String
        var coms: [String]
        var isSelected = false
        var isRejectd = [String: C]()
        
        init(_ s: String) {
            let split = s.components(separatedBy: " ")
            self.name = split[0]
            let coms = split[1].map { String($0) }
            self.coms = Array(coms.prefix(Int(split[2])!))
        }
    }
    
    func Sol6(_ companies:[String], _ applicants:[String]) -> [String] {
        let coms = companies.map { C($0) }
        var comDic = [String: C]()
        for com in coms {
            comDic[com.name] = com
        }
        
        let aps = applicants.map { A($0) }
        
        while true {
            var isBreak = true
            for a in aps {
                guard !a.isSelected else { continue }
                
                if a.isRejectd.count < a.coms.count {
                    isBreak = false
                }
            }
            if isBreak {
                break
            }
            
            // first
            for a in aps {
                guard !a.isSelected else { continue }
                
                for com in a.coms {
                    guard a.isRejectd[com] == nil else { continue }
                    let com = comDic[com]!
                    com.request[a.name] = a
                    break
                }
            }
            
            // second
            for c in coms {
                for a in c.aps {
                    guard let ap = c.request[a] else { continue }
                    
                    c.selected[a] = ap
                    ap.isSelected = true
                }
                
                // filter select
                if c.selected.count > c.count {
                    var q = [String: Int]()
                    for name in c.selected.keys {
                        var any = 0
                        for a in c.aps {
                            guard name != a else {
                                break
                            }
                            any += 1
                        }
                        q[name] = any
                    }
                    var sorted = q.sorted { $0.value > $1.value }
                    
                    while c.selected.count > c.count {
                        guard let first = sorted.first else { break }
                        c.selected[first.key]!.isSelected = false
                        c.selected[first.key]!.isRejectd[c.name] = c
                        c.selected.removeValue(forKey: first.key)
                        
                        sorted.removeFirst()
                    }
                }
                
                // filter
                c.request.filter { e in !c.selected.keys.contains(e.key) }.forEach {
                    $0.value.isRejectd[c.name] = c
                }
                c.request = [:]
            }
        }
        coms.forEach {
            $0.sortSelected = $0.selected.keys.sorted()
        }
        
        return coms.map { $0.description }
    }
```