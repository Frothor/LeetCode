/*
You need to traverse the graph this way:

Visit all leafs
Delete visited leafs
Visit new leafs
Delete them
And so on. In the end, you will have the centroid.
*/
func findMinHeightTrees(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}
	children := map[int][]int{}
	parents := map[int]int{}
	for _, e := range edges {
		children[e[0]] = append(children[e[0]], e[1])
		children[e[1]] = append(children[e[1]], e[0])
		parents[e[0]]++
		parents[e[1]]++
	}
	q := []int{}
	visited := map[int]bool{}
	for p := range children {
		if parents[p] == 1 {
			q = append(q, p)
			visited[p] = true
		}
	}
	remainingNodes := n
	for remainingNodes > 2 {
		former := len(q)
		for i := 0; i < former; i++ {
			for _, c := range children[q[i]] {
				parents[c]--
			}
		}
		for i := 0; i < former; i++ {
			for _, c := range children[q[i]] {
				if parents[c] == 1 && !visited[c] {
					q = append(q, c)
					visited[c] = true
				}
			}
			remainingNodes--
			delete(children, q[i])
		}
		q = q[former:]
	}
	out := []int{}
	for p := range children {
		out = append(out, p)
	}
	return out
}

//Fastest
func findMinHeightTrees(n int, edges [][]int) []int {
    if n == 1 {
        return []int{0}
    }
    linkNodes := make([][]int,n)
    for i :=0 ; i <n ; i++ {
        linkNodes[i] = make([]int,0,5)
    }
    
    count := make([]int,n)
    for _,e := range edges {
        linkNodes[e[0]] = append(linkNodes[e[0]],e[1])
        linkNodes[e[1]] = append(linkNodes[e[1]],e[0])
        count[e[0]]++
        count[e[1]]++
    }
    
    leafs := make([]int,0,n)
    for i:=0 ; i<n ; i++{
        if count[i] == 1{
            leafs = append(leafs,i)
        }
    }
    
    var leaf, nd int
    
    for n >2 {
        newLeafs := make([]int, 0, len(leafs))
        for _, leaf = range leafs{
            n--
            for _ , nd = range linkNodes[leaf]{
                count[nd]--
                if count[nd] == 1 {
                    newLeafs = append(newLeafs,nd)
                }
            }    
        }
        leafs = newLeafs
    }
    
    var res = make([]int,0,len(leafs))
    for _, v := range leafs{
        res = append(res,v)
    }
    
    return res
}