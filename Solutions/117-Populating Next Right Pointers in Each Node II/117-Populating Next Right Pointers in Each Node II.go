//BFS
//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/961871/golang-BFS-solution
func connect(root *Node) *Node {
    if root == nil {
        return root
    }
    
    q := []*Node{root}
    for len(q) > 0 {
        for i := 0; i < len(q) - 1; i++ {
            q[i].Next = q[i + 1]
        }
        
        tmp := make([]*Node, 0, len(q) * 2)
        for _, n := range q {
            if n.Left != nil {
                tmp = append(tmp, n.Left)
            }
            if n.Right != nil {
                tmp = append(tmp, n.Right)
            }
        }
        q = tmp        
    }
    return root
}

//Another
func connect(root *Node) *Node {
    if root == nil {
        return nil
    }
    queue := make([]*Node, 0)
    queue = append(queue, root)
    for n := len(queue); n > 0; n = len(queue) {
        for i := 0; i < n; i++ {
            curr := queue[0]
            if i != n - 1 {
                curr.Next = queue[1]
            }
            if curr.Left != nil {
                queue = append(queue, curr.Left)
            }
            if curr.Right != nil {
                queue = append(queue, curr.Right)
            }
            queue = queue[1:]
        }
    }
    return root
}