//Third fastest
func isValidBST(root *TreeNode) bool {
    stack := []*TreeNode{}
    
    inorder := math.MinInt64
    
    
    for len(stack) != 0 || root != nil {
        for root != nil {
            stack = append(stack, root)
            root = root.Left
        }
        
        idx := len(stack) - 1
        root = stack[idx]
        stack = stack[:idx]
        
        if root.Val <= inorder {
            return false
        }
        
        inorder = root.Val
        
        root = root.Right
    }
    
    return true
}

//Second fastest
func isValidBST(root *TreeNode) bool {
    return isValid(root, math.MinInt64, math.MaxInt64)
}

func isValid(root *TreeNode, min int64, max int64) bool {
    if root == nil {
        return true
    }
    
    if int64(root.Val) <= min || int64(root.Val) >= max {
        return false
    }
    
    return isValid(root.Left, min, int64(root.Val)) && isValid(root.Right, int64(root.Val), max)
}

//Fastest
func isValidBST(root *TreeNode) bool {
    return validate(root, nil, nil)
}

func validate(tree, min, max *TreeNode) bool {
    if tree == nil {
        return true
    }
    
    if min != nil && tree.Val <= min.Val {
        return false
    }
    if max != nil && tree.Val >= max.Val {
        return false
    }
    
    return validate(tree.Left, min, tree) && validate(tree.Right, tree, max)
}