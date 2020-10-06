//Iterative
func insertIntoBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        return &TreeNode{val, nil, nil}
    }
    
    node := root
    for node != nil {
        if node.Left != nil && node.Val > val {
            node = node.Left
        } else if node.Right != nil && node.Val < val {
            node = node.Right
        } else if node.Val > val {
            node.Left = &TreeNode{val, nil, nil}
            break
        } else {
            node.Right = &TreeNode{val, nil, nil}
            break
        }
    }
    
    return root
}

//Second fastest
func insertIntoBST(root *TreeNode, val int) *TreeNode {
	if root == nil { return &TreeNode{Val: val} }
	 if root.Val > val {
		 root.Left = insertIntoBST(root.Left, val)
	 } else {
		 root.Right = insertIntoBST(root.Right, val)
	 }
	 return root
 }

//Fastest
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func insertIntoBST(root *TreeNode, val int) *TreeNode {
    ans := root
    if root == nil {
        return &TreeNode{
            Val: val,
        }
    }
    for root != nil {
        if root.Val < val {
            if root.Right == nil {
                break
            }
            root = root.Right
            continue
        }
        
        if root.Val >= val {
            if root.Left == nil {
                break
            }
            root = root.Left
            continue
        }
    }
    if root.Val >= val {
        root.Left = &TreeNode {
            Val: val,
        }
    } else {
        root.Right = &TreeNode{
            Val: val,
        }
    }
    return ans
}