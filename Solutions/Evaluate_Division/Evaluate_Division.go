/*First I build a graph with multipliers derived for each A/B=k data point. Each node is a variable (e.g. A or B) and on edges I have multiplier. E.g. to transform A in numerator to n*B I need to multiply by k and to transform from B to n*A I need to multiply by 1/k. I need this so that I can perform transformations until I have the same symbol in numerator as in denominator. So for example if I have some equations involving A, B, C, D and I'm asked about B/D I walk through the graph of transformations (multiplications) from B to D getting n in the process which is the result (since e.g. D/D = 1).
I use BFS and when getting a result I use the parent hash table where I additionally store the multiplier from the edge which led me to that point.
I think BFS is correct here as it results in the lowest precision being lost as it performs least number of multiplications.*/

type node struct { // variables
    edges []*edge // directed
    name string
}

type edge struct {
    target *node
    multiplier float64
}

type parentMulti struct {
    parent *node
    multiplier float64
}

func bfs(source, target *node) (float64, bool) {
    if source == nil || target == nil {
        return 0.0, false
    }
    
    parents := make(map[*node]parentMulti)
    
    q := []*node{ source }
    found := false
    
    for len(q) > 0 {
        newQ := []*node{}
        for _, n := range(q) {
            for _, e := range(n.edges) {
                if parents[e.target].parent != nil {
                    continue
                }
                parents[e.target] = parentMulti{ n, e.multiplier }
                if e.target == target {
                    found = true
                    break
                }
                newQ = append(newQ, e.target)
            }
        }
        q = newQ
    }
    if found {
        ret := 1.0
        cursor := target
        for cursor != source {
            ret *= parents[cursor].multiplier
            cursor = parents[cursor].parent
        }
        return ret, true
    }
    return 0.0, false
    
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    nodesCache := make(map[string]*node)
    
    // build graph
    for i := range(equations) {
        n1 := nodesCache[equations[i][0]]
        if n1 == nil {
            n1 = new(node)
            nodesCache[equations[i][0]] = n1
        }
        n2 := nodesCache[equations[i][1]]
        if n2 == nil {
            n2 = new(node)
            nodesCache[equations[i][1]] = n2
        }
        n1ToN2 := &edge{n2, values[i]}
        n1.edges = append(n1.edges, n1ToN2)
        n2ToN1 := &edge{n1, 1.0/values[i]}
        n2.edges = append(n2.edges, n2ToN1)
    }
    
    ret := []float64{}
    
    for _, q := range(queries) {
        if value, ok := bfs(nodesCache[q[0]], nodesCache[q[1]]); ok {
            ret = append(ret, value)
        } else {
            ret = append(ret, -1.0)
        }
    }
    
    return ret
}

//Most common
func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    g:=make(map[string]map[string]float64)
    for ix, e:=range equations{
        if g[e[0]] == nil {
            g[e[0]] = make(map[string]float64)
        }
        if g[e[1]] == nil{
            g[e[1]] = make(map[string]float64)
        }
        g[e[0]][e[1]] = values[ix]
        g[e[1]][e[0]] = 1/values[ix]
    }
    
    ret:=make([]float64, len(queries))
    for ix, q:=range queries{
        if g[q[0]] == nil || g[q[1]] == nil{
            ret[ix] = -1.0
            continue
        } 
        if q[0] == q[1] {
            ret[ix] = 1.0
            continue
        }
        
        visited:=map[string]bool{}
        r:=dfs(g, q[0], q[1], visited)
        fmt.Println(q[0], q[1], r)
        if r < 0 {
            ret[ix] = -1.0
        }else{
            ret[ix] = r
        }
    }
    return ret
}

func dfs(g map[string]map[string]float64, start, end string, visited map[string]bool) float64{
    if start == end {
        return 1.0
    }
    visited[start] = true
    
    for k, v:=range g[start]{
        if !visited[k] {
            dist:=dfs(g, k, end, visited)
            if dist > 0 {
                 return v * dist

            }
        }
    }
    return -1.0
}

//Fastest
import "fmt"

type graph map[string]map[string]float64

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    myGraph := createGraph(equations, values)
    //fmt.Println(myGraph)
    //ans := make([]float64, 0)
    
    // Go through all queries and get values after traversing the graph for each of the queries
    ans := make([]float64, 0)

    for _, q := range queries {
        visited := make(map[string]bool)
        ans = append(ans, dfs(q[0], q[1], visited, myGraph))
    }
    return ans
    //return []float64{-1.0,-1.0}
    
}
                                
func createGraph(eqList [][]string, vals []float64) graph {
    g := make(graph)

    // Create entries for all different nodes in the graph if not present
    for i, eq := range eqList {
       if _, ok := g[eq[0]];  !ok {
            g[eq[0]] = make(map[string]float64)
        }
        if _, ok := g[eq[1]];  !ok {
            g[eq[1]] = make(map[string]float64)
        }  
        
        // Assign values from first node to the second
        // Also assign reverse values (1/val) from second node to first
        // if a / b = 2. then b / a = 1/2
        g[eq[0]][eq[1]] = vals[i]
        g[eq[1]][eq[0]] = 1/vals[i]
        
    }
    return g    
} 


func dfs(src, dest string, visited map[string]bool, g graph) float64 {
    // We looped around to come back to the same node so return -1
    if visited[src] {
        return -1
    }
    
    // We found edge from node src to dest so return the value (product of src * dest)
    if _,ok := g[src][dest]; ok {
        return g[src][dest]
    }
    
    visited[src] = true
    
    // Continue looking for the edge in the current adjacent nodes of src
    for next, _ := range g[src] {
        if retVal := dfs(next,dest,visited, g); retVal != -1 {
            return g[src][next] * retVal
        }
    }
    
    return -1    
}