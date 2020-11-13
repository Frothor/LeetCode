//Second fastest
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
    if root == nil {
        return nil
    }
    queue := make([]*Node, 0)
    queue = append(queue, root)
    for len(queue) > 0 {
        l := len(queue) 
        for i := 0; i < l; i++ { //iterate l elements only
            node := queue[0]
            queue = queue[1:]
            
            if i == l - 1 {
                node.Next = nil //last node in this level
            } else if i < l - 1 {
                node.Next = queue[0] //not the last node in this level
            }
            
            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
            
        }
    }
    return root
}

//Another
func connect(root *Node) *Node {
	
    itr := root
    for root != nil && root.Left != nil {
        start := root
        
        for start != nil {
            start.Left.Next = start.Right
            if start.Next != nil {
                start.Right.Next = start.Next.Left
            }
            start = start.Next
        }
        
        root = root.Left
    }
    
    return itr
}

//Fastest
func connectNext(node *Node) {
    if node == nil {
        return
    }
    if node.Next != nil {
        connectNext(node.Next)
    }
    
    if node.Left != nil {
        if node.Right != nil {
            node.Left.Next = node.Right
            node.Right.Next = getNextRight(node)
        } else {
            node.Left.Next = getNextRight(node)
        }
        connectNext(node.Left)
    } else if node.Right != nil {
        node.Right.Next = getNextRight(node)
        connectNext(node.Right)
    } else {
        connectNext(getNextRight(node))
    }
}

func getNextRight(node *Node) *Node {
    for nextRight := node.Next ; nextRight != nil; nextRight = nextRight.Next {
        if nextRight.Left != nil {
            return nextRight.Left
        } else if nextRight.Right != nil {
            return nextRight.Right
        }
    }
    return nil
}

func nextLevel(node *Node) *Node {
    if node.Left != nil {
        return node.Left
    } else if node.Right != nil {
        return node.Right
    } 
    return getNextRight(node)
}

func connectRight(root *Node) {
    for level := root; level != nil ; level = nextLevel(level) {
        for node := level; node != nil; node = node.Next {
            if node.Left != nil {
                if node.Right != nil {
                    node.Left.Next = node.Right
                } else {
                    node.Left.Next = getNextRight(node)
                }
            }
            if node.Right != nil {
                node.Right.Next = getNextRight(node)
            }
        }
    }
}

func connect(root *Node) *Node {
    connectRight(root)
    return root
}
