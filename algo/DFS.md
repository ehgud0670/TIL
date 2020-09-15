### 깊이 순으로 방문하고 표시한다. 

```swift
func solutionByDFS(arrs: [[Int]]) -> [Int] {
    var dic = [Int: [Int]]()
    arrs.forEach {
        make(dic: &dic, key: $0[0], element: $0[1])
        make(dic: &dic, key: $0[1], element: $0[0])
    }
        
    let first = dic.min { $0.key < $1.key }!.key
    var answer = [first]
    var visited = [first: true]
        
    for e in dic[first]! {
        guard visited[e] == nil else { continue }
            
        visited[e] = true
        answer.append(e)
        dfs(v: e, dic: dic, visited: &visited, answer: &answer)
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
    
func dfs(v: Int, dic: [Int: [Int]], visited: inout [Int: Bool], answer: inout [Int]) {
    visited[v] = true
        
    for e in dic[v]! {
        guard visited[e] == nil else { continue }
            
        visited[e] = true
        answer.append(e)
        dfs(v: e, dic: dic, visited: &visited, answer: &answer)
    }
}
```