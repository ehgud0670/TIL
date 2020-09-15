### BFS: 너비 순으로 방문하고 표시한다. 

```swift
func BFS(arrs: [[Int]]) -> [Int] {
    var dic = [Int: [Int]]()
    arrs.forEach {
        make(dic: &dic, key: $0[0], element: $0[1])
        make(dic: &dic, key: $0[1], element: $0[0])
    }
        
        
    let first = dic.min { $0.key < $1.key }!.key
    var queue = [first]
    var visited = [first: true]
    var answer = [first]
        
    while queue.count != 0 {
        let v = queue.remove(at: 0)
            
        for e in dic[v]! {
            guard visited[e] == nil else { continue }
                    
            visited[e] = true
            queue.append(e)
            answer.append(e)
        }
    }
        
    return answer
}
    
func make(dic: inout [Int: [Int]], key: Int, element: Int) {
    if dic[key] == nil {
        dic[key] = [element]
        return
    }
    dic[key]!.append(element)
}
```